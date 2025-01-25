
# Bridge Design Pattern

The **Bridge Pattern** is a structural design pattern that decouples an abstraction from its implementation so that the two can evolve independently. It is used to avoid a permanent binding between an abstraction and its implementation.

---

## Key Components

1. **Abstraction**: Defines the interface for the high-level abstraction and maintains a reference to the implementor.
2. **Implementor**: Defines the interface for the concrete implementations.
3. **ConcreteImplementor**: Implements the Implementor interface.
4. **RefinedAbstraction**: Extends the Abstraction and interacts with the Implementor.

---

## When to Use the Bridge Pattern
1. You want to avoid a permanent binding between abstraction and its implementation.
2. You need to extend abstractions and implementations independently without affecting each other.
3. There are multiple implementations of an abstraction, and you want to choose an implementation dynamically.
4. You want to reduce the number of subclasses when dealing with a mix of features.

---

## Real-Life Example

Think about a **remote control** for devices like TVs or audio systems:
- The **remote control** is the abstraction.
- The **TV or audio system** is the concrete implementation.

By separating the remote control interface (abstraction) from the devices (implementation), we can extend either of them independently. For example, a "smart remote" can work with different kinds of TVs.

---

## C++ Code Example

Here is an example of the Bridge Pattern in C++:

```cpp
#include <iostream>
#include <memory>
#include <string>

// Implementor
class Device {
public:
    virtual void powerOn() = 0;
    virtual void powerOff() = 0;
    virtual void setVolume(int level) = 0;
    virtual ~Device() = default;
};

// ConcreteImplementor1
class TV : public Device {
public:
    void powerOn() override {
        std::cout << "TV is now ON.\n";
    }

    void powerOff() override {
        std::cout << "TV is now OFF.\n";
    }

    void setVolume(int level) override {
        std::cout << "TV volume set to " << level << ".\n";
    }
};

// ConcreteImplementor2
class Radio : public Device {
public:
    void powerOn() override {
        std::cout << "Radio is now ON.\n";
    }

    void powerOff() override {
        std::cout << "Radio is now OFF.\n";
    }

    void setVolume(int level) override {
        std::cout << "Radio volume set to " << level << ".\n";
    }
};

// Abstraction
class RemoteControl {
protected:
    std::shared_ptr<Device> device;

public:
    RemoteControl(std::shared_ptr<Device> dev) : device(std::move(dev)) {}

    virtual void turnOn() {
        device->powerOn();
    }

    virtual void turnOff() {
        device->powerOff();
    }

    virtual void setVolume(int level) {
        device->setVolume(level);
    }

    virtual ~RemoteControl() = default;
};

// RefinedAbstraction
class AdvancedRemoteControl : public RemoteControl {
public:
    AdvancedRemoteControl(std::shared_ptr<Device> dev) : RemoteControl(std::move(dev)) {}

    void mute() {
        std::cout << "Muting the device.\n";
        device->setVolume(0);
    }
};

// Main
int main() {
    // Use a TV with a simple remote
    std::shared_ptr<Device> tv = std::make_shared<TV>();
    RemoteControl simpleRemote(tv);
    simpleRemote.turnOn();
    simpleRemote.setVolume(15);
    simpleRemote.turnOff();

    std::cout << "-----\n";

    // Use a Radio with an advanced remote
    std::shared_ptr<Device> radio = std::make_shared<Radio>();
    AdvancedRemoteControl advancedRemote(radio);
    advancedRemote.turnOn();
    advancedRemote.setVolume(10);
    advancedRemote.mute();
    advancedRemote.turnOff();

    return 0;
}
```

---

## Explanation of Code

1. **Implementor Interface (`Device`)**: Declares basic operations like `powerOn`, `powerOff`, and `setVolume`.
2. **Concrete Implementors (`TV`, `Radio`)**: Provide specific implementations for the `Device` interface.
3. **Abstraction (`RemoteControl`)**: Contains a reference to the `Device` and defines high-level operations.
4. **Refined Abstraction (`AdvancedRemoteControl`)**: Extends `RemoteControl` to add extra functionalities like `mute`.

---

## Advantages
1. Decouples abstraction from implementation, enabling independent extension of both.
2. Improves code maintainability by reducing the number of classes when there are multiple dimensions of variation.
3. Promotes flexibility in code design.

---

## Real-World Use Cases
1. **Graphic Systems**: Decouple the representation of graphical objects from how they are rendered (e.g., OpenGL, DirectX).
2. **Database Drivers**: Abstraction for database operations while supporting different database implementations (MySQL, PostgreSQL, etc.).
3. **User Interfaces**: Separate the GUI framework (e.g., buttons) from their rendering implementation for different platforms.
