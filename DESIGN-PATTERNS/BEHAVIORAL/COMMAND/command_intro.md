# Command Design Pattern in C++

The **Command Design Pattern** is a behavioral design pattern used to encapsulate a request as an object, thereby allowing you to parameterize clients with different requests, delay execution of requests, or log them. It decouples the sender of the request from the receiver by introducing a layer of abstraction in the form of command objects.

## Components of the Command Pattern
1. **Command**: An abstract interface defining a method for executing a command.
2. **ConcreteCommand**: Implements the Command interface, binding a receiver to an action.
3. **Receiver**: The object that performs the actual work when the command is executed.
4. **Invoker**: Stores and executes commands.
5. **Client**: Creates specific command objects and associates them with the appropriate receivers.

---

## Real-Life Use Case: Smart Home Automation
Imagine a smart home system where you can control devices like lights, fans, and TVs using a remote. Each button on the remote is associated with a specific action (e.g., turning on/off a light). The **Command Pattern** is ideal for encapsulating these actions.

---

## C++ Implementation

Here is a C++ example of the Command Pattern applied to a smart home automation system:

```cpp
#include <iostream>
#include <memory>
#include <vector>

// Command interface
class Command {
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
    virtual void undo() = 0;
};

// Receiver: Light
class Light {
public:
    void turnOn() {
        std::cout << "Light is ON\n";
    }

    void turnOff() {
        std::cout << "Light is OFF\n";
    }
};

// ConcreteCommand: LightOnCommand
class LightOnCommand : public Command {
private:
    Light* light;

public:
    explicit LightOnCommand(Light* light) : light(light) {}

    void execute() override {
        light->turnOn();
    }

    void undo() override {
        light->turnOff();
    }
};

// ConcreteCommand: LightOffCommand
class LightOffCommand : public Command {
private:
    Light* light;

public:
    explicit LightOffCommand(Light* light) : light(light) {}

    void execute() override {
        light->turnOff();
    }

    void undo() override {
        light->turnOn();
    }
};

// Invoker: RemoteControl
class RemoteControl {
private:
    Command* command;

public:
    void setCommand(Command* command) {
        this->command = command;
    }

    void pressButton() {
        if (command) {
            command->execute();
        }
    }

    void pressUndo() {
        if (command) {
            command->undo();
        }
    }
};

// Client
int main() {
    Light livingRoomLight;

    // Create commands
    LightOnCommand lightOnCommand(&livingRoomLight);
    LightOffCommand lightOffCommand(&livingRoomLight);

    // Create invoker (remote control)
    RemoteControl remote;

    // Turn on the light
    remote.setCommand(&lightOnCommand);
    remote.pressButton(); // Output: Light is ON

    // Turn off the light
    remote.setCommand(&lightOffCommand);
    remote.pressButton(); // Output: Light is OFF

    // Undo the last action
    remote.pressUndo(); // Output: Light is ON

    return 0;
}
```

---

## Explanation of the Code
1. **Command Interface**: The `Command` interface defines `execute()` and `undo()` methods for commands.
2. **Receiver**: The `Light` class represents the device controlled by commands.
3. **Concrete Commands**: `LightOnCommand` and `LightOffCommand` encapsulate the actions to turn the light on or off.
4. **Invoker**: The `RemoteControl` class stores and triggers commands.
5. **Client**: The `main()` function acts as the client, creating commands and assigning them to the invoker.

---

## Advantages
1. Decouples the sender (Invoker) and receiver.
2. Simplifies adding new commands without changing existing code.
3. Enables features like undo/redo, logging, and queuing commands.

---

## Other Real-Life Use Cases
1. **GUI Buttons**: Associating button clicks with actions (e.g., saving a file, opening a document).
2. **Transactional Systems**: Reverting changes in a database.
3. **Task Scheduling**: Delaying or queuing operations in background services.
