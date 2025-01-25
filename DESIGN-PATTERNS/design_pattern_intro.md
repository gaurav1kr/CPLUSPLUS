# Design Patterns in C++

## **1. Introduction to Design Patterns**

### **Classification of Design Patterns**
1. **Creational Patterns**: Deal with object creation mechanisms, aiming to create objects in a way suitable for the situation.
   - Examples: Factory Method, Abstract Factory, Builder, Singleton, Prototype.

2. **Structural Patterns**: Focus on the composition of classes and objects to form larger structures.
   - Examples: Adapter, Bridge, Composite, Decorator, Facade, Flyweight, Proxy.

3. **Behavioral Patterns**: Concerned with communication between objects and the delegation of responsibilities.
   - Examples: Strategy, Observer, Command, State, Template Method, Iterator, Mediator, Chain of Responsibility, Visitor.

---

## **2. Creational Design Patterns**

### **a) Factory Method**
**Scenario**: Used when a class cannot anticipate the type of objects it needs to create.

**Example**: A logistics system where different types of transports (Truck, Ship) are created based on user input.

```cpp
class Transport {
public:
    virtual void deliver() = 0;
    virtual ~Transport() = default;
};

class Truck : public Transport {
public:
    void deliver() override { std::cout << "Delivered by Truck\n"; }
};

class Ship : public Transport {
public:
    void deliver() override { std::cout << "Delivered by Ship\n"; }
};

class Logistics {
public:
    virtual Transport* createTransport() = 0;
    void planDelivery() {
        Transport* transport = createTransport();
        transport->deliver();
        delete transport;
    }
};

class RoadLogistics : public Logistics {
    Transport* createTransport() override { return new Truck(); }
};

class SeaLogistics : public Logistics {
    Transport* createTransport() override { return new Ship(); }
};
```

**Use Case**:
- GUI frameworks that need to create different types of UI elements dynamically.

---

### **b) Abstract Factory**
**Scenario**: Used to create families of related objects without specifying their concrete classes.
**Example**: A cross-platform UI library creating buttons and checkboxes for different operating systems.

---

### **c) Builder**
**Scenario**: Used when creating a complex object step-by-step.
**Example**: Building a car with multiple customizable parts (engine, wheels, etc.).

---

### **d) Singleton**
**Scenario**: Ensures only one instance of a class is created and provides a global point of access to it.
**Example**: Configuration settings manager in an application.

---

### **e) Prototype**
**Scenario**: Used to create a new object by copying an existing object (cloning).
**Example**: A game where objects (e.g., trees, rocks) are cloned for performance optimization.

---

## **3. Structural Design Patterns**

### **a) Adapter**
**Scenario**: Used to allow incompatible interfaces to work together.
**Example**: Integrating a legacy payment system with a modern e-commerce platform.

---

### **b) Bridge**
**Scenario**: Decouples abstraction from its implementation, allowing both to vary independently.
**Example**: A remote control (abstraction) that works with various devices (implementation).

---

### **c) Composite**
**Scenario**: Used to treat a group of objects as a single object (tree structure).
**Example**: A file system where folders and files are treated uniformly.

---

### **d) Decorator**
**Scenario**: Dynamically adds behavior to objects without modifying their code.
**Example**: Adding encryption to file I/O operations.

---

### **e) Facade**
**Scenario**: Provides a simplified interface to a complex subsystem.
**Example**: A single API for interacting with a home automation system.

---

### **f) Flyweight**
**Scenario**: Reduces memory usage by sharing common data between objects.
**Example**: Text rendering in a word processor, where characters share font data.

---

### **g) Proxy**
**Scenario**: Provides a surrogate or placeholder for another object.
**Example**: A virtual proxy to delay the loading of large images in an application.

---

## **4. Behavioral Design Patterns**

### **a) Strategy**
**Scenario**: Allows selecting an algorithm at runtime.
**Example**: Sorting with different strategies (QuickSort, MergeSort).

---

### **b) Observer**
**Scenario**: Used for a publish-subscribe mechanism.
**Example**: Notification system where multiple subscribers are notified of changes.

---

### **c) Command**
**Scenario**: Encapsulates a request as an object.
**Example**: Undo/redo functionality in a text editor.

---

### **d) State**
**Scenario**: Allows an object to change its behavior when its internal state changes.
**Example**: A finite state machine for a vending machine.

---

### **e) Template Method**
**Scenario**: Defines the skeleton of an algorithm in a base class and allows subclasses to override steps.
**Example**: A game engine where subclasses implement specific behaviors for characters.

---

### **f) Iterator**
**Scenario**: Provides a way to access elements of a collection sequentially.
**Example**: Iterating over items in a custom container class.

---

### **g) Mediator**
**Scenario**: Reduces coupling between components by introducing a mediator object.
**Example**: A chat application where a server acts as a mediator for clients.

---

### **h) Chain of Responsibility**
**Scenario**: Passes a request along a chain of handlers until it is processed.
**Example**: Event handling in a UI system.

---

### **i) Visitor**
**Scenario**: Allows adding new operations to existing class hierarchies without modifying them.
**Example**: Tax calculation for different types of goods in a shopping cart.

---

## **5. Choosing the Right Design Pattern**

When deciding which design pattern to use:
1. **Understand the Problem**: Clearly define the issue you're trying to solve.
2. **Evaluate Constraints**: Identify performance, scalability, and maintainability needs.
3. **Match with a Pattern**: Look for a pattern that best aligns with your problem's structure and behavior.

---
