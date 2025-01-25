
# Chain of Responsibility Design Pattern

The **Chain of Responsibility** is a behavioral design pattern that allows a request to be passed along a chain of handlers until it is processed by one of the handlers or reaches the end of the chain unhandled. This pattern decouples the sender of the request from its receiver by giving multiple objects a chance to process the request.

## Key Concepts:
1. **Handler**: The abstract base class or interface defining a method to process the request and a way to set the next handler.
2. **Concrete Handler**: Implements the handling logic. If it cannot handle the request, it passes it to the next handler.
3. **Client**: Initiates the request and is unaware of how the request will be processed or who will process it.

---

## Real-Life Use Case: Customer Support System
Imagine a customer support system where queries can be resolved at different levels:
1. **Level 1 Support** handles basic issues.
2. **Level 2 Support** addresses more complex issues.
3. **Level 3 Support** resolves advanced or critical issues.

Each support level checks if it can handle the request. If not, it forwards the request to the next level.

---

## Steps to Implement:
1. Define an abstract base class for the handler with methods for processing requests and setting the next handler.
2. Create concrete handler classes that override the handling method.
3. Chain the handlers together dynamically.
4. The client sends requests to the chain without knowing which handler will process them.

---

## C++ Code Implementation

```cpp
#include <iostream>
#include <string>
#include <memory>

// Abstract Handler
class SupportHandler {
protected:
    std::shared_ptr<SupportHandler> nextHandler;

public:
    virtual ~SupportHandler() = default;

    // Set the next handler in the chain
    void setNextHandler(std::shared_ptr<SupportHandler> handler) {
        nextHandler = handler;
    }

    // Handle the request or pass it to the next handler
    virtual void handleRequest(const std::string& issue) = 0;
};

// Concrete Handlers
class Level1Support : public SupportHandler {
public:
    void handleRequest(const std::string& issue) override {
        if (issue == "basic") {
            std::cout << "Level 1 Support: Resolved basic issue.\n";
        } else if (nextHandler) {
            nextHandler->handleRequest(issue);
        } else {
            std::cout << "Level 1 Support: Unable to resolve the issue.\n";
        }
    }
};

class Level2Support : public SupportHandler {
public:
    void handleRequest(const std::string& issue) override {
        if (issue == "intermediate") {
            std::cout << "Level 2 Support: Resolved intermediate issue.\n";
        } else if (nextHandler) {
            nextHandler->handleRequest(issue);
        } else {
            std::cout << "Level 2 Support: Unable to resolve the issue.\n";
        }
    }
};

class Level3Support : public SupportHandler {
public:
    void handleRequest(const std::string& issue) override {
        if (issue == "critical") {
            std::cout << "Level 3 Support: Resolved critical issue.\n";
        } else if (nextHandler) {
            nextHandler->handleRequest(issue);
        } else {
            std::cout << "Level 3 Support: Unable to resolve the issue.\n";
        }
    }
};

// Client code
int main() {
    auto level1 = std::make_shared<Level1Support>();
    auto level2 = std::make_shared<Level2Support>();
    auto level3 = std::make_shared<Level3Support>();

    // Chain the handlers
    level1->setNextHandler(level2);
    level2->setNextHandler(level3);

    // Client sends requests
    std::cout << "Sending a basic issue...\n";
    level1->handleRequest("basic");

    std::cout << "\nSending an intermediate issue...\n";
    level1->handleRequest("intermediate");

    std::cout << "\nSending a critical issue...\n";
    level1->handleRequest("critical");

    std::cout << "\nSending an unknown issue...\n";
    level1->handleRequest("unknown");

    return 0;
}
```

---

## Explanation of Code:
1. **Base Class (`SupportHandler`)**:
   - Provides a method `setNextHandler` to link handlers in a chain.
   - Declares a pure virtual method `handleRequest` for processing requests.

2. **Concrete Handlers (`Level1Support`, `Level2Support`, `Level3Support`)**:
   - Implement `handleRequest` to process specific types of issues.
   - Delegate unhandled requests to the next handler.

3. **Client**:
   - Chains the handlers together using `setNextHandler`.
   - Sends requests to the first handler in the chain.

---

## Advantages:
1. **Decoupled Components**: The sender and receiver are decoupled.
2. **Flexible**: Handlers can be added, removed, or reordered without affecting the client.
3. **Open/Closed Principle**: The chain can be extended without modifying existing code.

## Disadvantages:
1. **Uncertain Handling**: If no handler processes the request, it might remain unhandled.
2. **Performance**: Traversing the chain can be inefficient for long chains.

The **Chain of Responsibility** is ideal when there are multiple potential handlers for a request, and the order of processing can vary.
