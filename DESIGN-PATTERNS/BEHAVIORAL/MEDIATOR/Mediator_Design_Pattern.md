
# Mediator Design Pattern

## Overview

The **Mediator Design Pattern** is a behavioral design pattern that promotes loose coupling between objects by ensuring that they communicate with each other through a mediator object rather than directly. This pattern helps reduce the dependencies among objects, making the system more maintainable and scalable.

---

## Key Concepts

1. **Mediator**: The central object that handles communication between different components (colleagues).
2. **Colleagues**: The components that rely on the mediator for communication.
3. **Loose Coupling**: Instead of objects referring to each other directly, they interact through the mediator, reducing interdependencies.

---

## Real-Life Example: Air Traffic Control (ATC)

In an airport, airplanes do not communicate directly with each other to avoid collisions. Instead, they communicate through the air traffic control (ATC) tower, which acts as the mediator. The ATC tower coordinates the actions of all airplanes, ensuring safe takeoffs, landings, and in-air navigation.

---

## Use Cases

1. **Chat Applications**: A chatroom acts as a mediator between users. Users send messages to the chatroom, and the chatroom broadcasts them to all participants.
2. **UI Components**: In a form, different components (e.g., textboxes, buttons) might interact with each other through a mediator to ensure proper behavior without direct dependencies.
3. **Gaming**: In multiplayer games, a server acts as the mediator between players, handling events like attacks or movements.

---

## Advantages

1. Simplifies communication logic by centralizing it in the mediator.
2. Reduces coupling between objects, making the system more maintainable.
3. Encourages single-responsibility principle.

---

## Disadvantages

1. The mediator can become complex if it manages many interactions.
2. Over-reliance on a mediator might lead to a monolithic design.

---

## C++ Implementation

Here’s an implementation of the Mediator Pattern in a chatroom scenario:

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <memory>

// Forward declaration
class Mediator;

// Abstract Colleague
class Colleague {
protected:
    Mediator* mediator;
public:
    Colleague(Mediator* mediator) : mediator(mediator) {}
    virtual void send(const std::string& message) = 0;
    virtual void receive(const std::string& message) = 0;
    virtual ~Colleague() = default;
};

// Mediator Interface
class Mediator {
public:
    virtual void sendMessage(const std::string& message, Colleague* sender) = 0;
    virtual ~Mediator() = default;
};

// Concrete Mediator
class ChatRoom : public Mediator {
private:
    std::vector<Colleague*> colleagues;
public:
    void addColleague(Colleague* colleague) {
        colleagues.push_back(colleague);
    }

    void sendMessage(const std::string& message, Colleague* sender) override {
        for (Colleague* colleague : colleagues) {
            if (colleague != sender) {
                colleague->receive(message);
            }
        }
    }
};

// Concrete Colleague
class User : public Colleague {
private:
    std::string name;
public:
    User(const std::string& name, Mediator* mediator) : Colleague(mediator), name(name) {}

    void send(const std::string& message) override {
        std::cout << name << " sends: " << message << "\n";
        mediator->sendMessage(message, this);
    }

    void receive(const std::string& message) override {
        std::cout << name << " receives: " << message << "\n";
    }
};

int main() {
    ChatRoom chatRoom;

    User alice("Alice", &chatRoom);
    User bob("Bob", &chatRoom);
    User charlie("Charlie", &chatRoom);

    chatRoom.addColleague(&alice);
    chatRoom.addColleague(&bob);
    chatRoom.addColleague(&charlie);

    alice.send("Hello, everyone!");
    bob.send("Hi Alice!");
    charlie.send("Hey Alice, Bob!");

    return 0;
}
```

---

## Explanation of Code

1. **Mediator (ChatRoom)**: Manages the communication between users.
2. **Colleagues (User)**: Send and receive messages via the mediator.
3. **Loose Coupling**: Users do not communicate directly but rely on the mediator for message handling.
4. **Output**:
   ```
   Alice sends: Hello, everyone!
   Bob receives: Hello, everyone!
   Charlie receives: Hello, everyone!
   Bob sends: Hi Alice!
   Alice receives: Hi Alice!
   Charlie receives: Hi Alice!
   Charlie sends: Hey Alice, Bob!
   Alice receives: Hey Alice, Bob!
   Bob receives: Hey Alice, Bob!
   ```

This demonstrates how the mediator pattern simplifies communication and decouples objects effectively.
