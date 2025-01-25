# Builder Design Pattern in C++

The **Builder Design Pattern** is a creational design pattern used to construct a complex object step by step. It separates the construction of an object from its representation, enabling the same construction process to create different representations. This is particularly useful when creating an object involves multiple steps and configurations.

---

## **Key Components**
1. **Builder (Abstract Builder)**: Defines the interface for creating parts of a product.
2. **Concrete Builder**: Implements the builder interface and constructs parts of the product.
3. **Product**: The complex object being built.
4. **Director**: Orchestrates the construction process using the builder.

---

## **Real-Life Example: Car Manufacturing**
Imagine building a car where the construction involves assembling components like the engine, wheels, and GPS. The steps to build a basic car or a luxury car differ, but the process can use the same interface.

---

### **C++ Implementation**

Here's an example of the Builder design pattern applied to a car manufacturing scenario:

```cpp
#include <iostream>
#include <string>
#include <memory>

// Product: The complex object to be built
class Car {
public:
    std::string engine;
    int wheels;
    std::string gps;

    void showCarDetails() const {
        std::cout << "Car Details:\n";
        std::cout << "Engine: " << engine << "\n";
        std::cout << "Wheels: " << wheels << "\n";
        std::cout << "GPS: " << gps << "\n";
    }
};

// Builder: Abstract interface for creating parts of the product
class CarBuilder {
public:
    virtual ~CarBuilder() = default;
    virtual void buildEngine() = 0;
    virtual void buildWheels() = 0;
    virtual void buildGPS() = 0;
    virtual std::shared_ptr<Car> getCar() = 0;
};

// Concrete Builder: Builds a specific type of car (e.g., BasicCar)
class BasicCarBuilder : public CarBuilder {
private:
    std::shared_ptr<Car> car;

public:
    BasicCarBuilder() { car = std::make_shared<Car>(); }

    void buildEngine() override {
        car->engine = "Basic Engine";
    }

    void buildWheels() override {
        car->wheels = 4;
    }

    void buildGPS() override {
        car->gps = "No GPS";
    }

    std::shared_ptr<Car> getCar() override {
        return car;
    }
};

// Concrete Builder: Builds a luxury car
class LuxuryCarBuilder : public CarBuilder {
private:
    std::shared_ptr<Car> car;

public:
    LuxuryCarBuilder() { car = std::make_shared<Car>(); }

    void buildEngine() override {
        car->engine = "V8 Engine";
    }

    void buildWheels() override {
        car->wheels = 4;
    }

    void buildGPS() override {
        car->gps = "Advanced GPS System";
    }

    std::shared_ptr<Car> getCar() override {
        return car;
    }
};

// Director: Orchestrates the building process
class CarDirector {
private:
    CarBuilder* builder;

public:
    void setBuilder(CarBuilder* builder) {
        this->builder = builder;
    }

    void constructCar() {
        builder->buildEngine();
        builder->buildWheels();
        builder->buildGPS();
    }
};

// Main Function
int main() {
    CarDirector director;

    // Building a Basic Car
    BasicCarBuilder basicCarBuilder;
    director.setBuilder(&basicCarBuilder);
    director.constructCar();
    auto basicCar = basicCarBuilder.getCar();
    std::cout << "Basic Car:\n";
    basicCar->showCarDetails();

    std::cout << "\n";

    // Building a Luxury Car
    LuxuryCarBuilder luxuryCarBuilder;
    director.setBuilder(&luxuryCarBuilder);
    director.constructCar();
    auto luxuryCar = luxuryCarBuilder.getCar();
    std::cout << "Luxury Car:\n";
    luxuryCar->showCarDetails();

    return 0;
}
```

---

### **Explanation**
1. **Product (`Car`)**:
   - Represents the complex object to be built.
   - Has attributes like `engine`, `wheels`, and `gps`.

2. **Builder (`CarBuilder`)**:
   - An abstract interface defining the steps to build a car.

3. **Concrete Builder (`BasicCarBuilder` and `LuxuryCarBuilder`)**:
   - Implements the steps to build specific types of cars.

4. **Director (`CarDirector`)**:
   - Orchestrates the steps defined in the builder to construct the car.

5. **Client (Main Function)**:
   - Decides which builder to use and directs the construction process.

---

### **Output**

```
Basic Car:
Car Details:
Engine: Basic Engine
Wheels: 4
GPS: No GPS

Luxury Car:
Car Details:
Engine: V8 Engine
Wheels: 4
GPS: Advanced GPS System
```

---
