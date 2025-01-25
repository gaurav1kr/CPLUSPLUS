# Decorator Pattern

The **Decorator Pattern** is a structural design pattern that allows behavior to be added to an individual object dynamically, without affecting the behavior of other objects from the same class. This is achieved by creating a set of decorator classes that are used to wrap concrete components.

---

## Key Concepts:
1. **Component Interface**: Defines the interface for objects that can have responsibilities added to them dynamically.
2. **Concrete Component**: The object to which additional behavior will be added.
3. **Decorator**: Maintains a reference to a component object and defines an interface conforming to the component's interface.
4. **Concrete Decorators**: Extend the functionality of the component by adding behavior.

---

## Real-Life Use Cases

1. **GUI Elements**:
   - In a graphical user interface, you might have a base class `Widget`. A concrete implementation might be a `TextBox`. Using decorators, you can dynamically add scrollbars, borders, or shadows to the `TextBox` without modifying its core behavior.

2. **Logging in Software**:
   - You can use the decorator pattern to add logging, performance monitoring, or other behaviors to methods at runtime without altering their original implementation.

3. **Coffee Shop Example**:
   - Imagine a coffee shop where you can add extras like milk, sugar, and whipped cream to a base coffee. The base coffee is the component, and each extra is a decorator that dynamically enhances the coffee.

---

## C++ Implementation: Coffee Shop Example

Here’s how you could implement the coffee shop use case in C++ using the decorator pattern:

```cpp
#include <iostream>
#include <memory>
#include <string>

// Component Interface
class Coffee {
public:
    virtual ~Coffee() = default;
    virtual std::string getDescription() const = 0;
    virtual double cost() const = 0;
};

// Concrete Component
class BasicCoffee : public Coffee {
public:
    std::string getDescription() const override {
        return "Basic Coffee";
    }

    double cost() const override {
        return 5.0; // Base price of coffee
    }
};

// Decorator Base Class
class CoffeeDecorator : public Coffee {
protected:
    std::shared_ptr<Coffee> wrappedCoffee;

public:
    CoffeeDecorator(std::shared_ptr<Coffee> coffee) : wrappedCoffee(std::move(coffee)) {}
};

// Concrete Decorators
class Milk : public CoffeeDecorator {
public:
    Milk(std::shared_ptr<Coffee> coffee) : CoffeeDecorator(std::move(coffee)) {}

    std::string getDescription() const override {
        return wrappedCoffee->getDescription() + ", Milk";
    }

    double cost() const override {
        return wrappedCoffee->cost() + 1.0; // Adding milk costs extra
    }
};

class Sugar : public CoffeeDecorator {
public:
    Sugar(std::shared_ptr<Coffee> coffee) : CoffeeDecorator(std::move(coffee)) {}

    std::string getDescription() const override {
        return wrappedCoffee->getDescription() + ", Sugar";
    }

    double cost() const override {
        return wrappedCoffee->cost() + 0.5; // Adding sugar costs extra
    }
};

class WhippedCream : public CoffeeDecorator {
public:
    WhippedCream(std::shared_ptr<Coffee> coffee) : CoffeeDecorator(std::move(coffee)) {}

    std::string getDescription() const override {
        return wrappedCoffee->getDescription() + ", Whipped Cream";
    }

    double cost() const override {
        return wrappedCoffee->cost() + 1.5; // Adding whipped cream costs extra
    }
};

// Main Function
int main() {
    // Basic Coffee
    std::shared_ptr<Coffee> myCoffee = std::make_shared<BasicCoffee>();
    std::cout << myCoffee->getDescription() << " costs $" << myCoffee->cost() << '\n';

    // Add Milk
    myCoffee = std::make_shared<Milk>(myCoffee);
    std::cout << myCoffee->getDescription() << " costs $" << myCoffee->cost() << '\n';

    // Add Sugar
    myCoffee = std::make_shared<Sugar>(myCoffee);
    std::cout << myCoffee->getDescription() << " costs $" << myCoffee->cost() << '\n';

    // Add Whipped Cream
    myCoffee = std::make_shared<WhippedCream>(myCoffee);
    std::cout << myCoffee->getDescription() << " costs $" << myCoffee->cost() << '\n';

    return 0;
}
```

---

## Explanation of the Code:

1. **Base Interface**: The `Coffee` class defines a common interface for all coffee types and decorators.
2. **Concrete Component**: `BasicCoffee` is the base coffee that can be decorated.
3. **Base Decorator Class**: `CoffeeDecorator` holds a reference to a `Coffee` object and delegates calls to it.
4. **Concrete Decorators**: `Milk`, `Sugar`, and `WhippedCream` add new behavior to the coffee object.

---

## Output:
```
Basic Coffee costs $5
Basic Coffee, Milk costs $6
Basic Coffee, Milk, Sugar costs $6.5
Basic Coffee, Milk, Sugar, Whipped Cream costs $8
