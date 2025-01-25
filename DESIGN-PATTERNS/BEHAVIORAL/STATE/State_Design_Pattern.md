
# State Design Pattern

## Overview
The **State Design Pattern** is a behavioral design pattern that allows an object to change its behavior when its internal state changes. It provides a way to encapsulate state-specific behavior within separate classes and lets the context class delegate state-specific behavior to the current state object.

This pattern is particularly useful when an object has multiple states, and the behavior of the object changes based on its current state.

---

## Key Components
1. **Context**: Maintains a reference to the current state and interacts with the state object to perform operations.
2. **State**: Defines an interface for encapsulating behavior associated with a particular state.
3. **Concrete States**: Implement the behavior associated with a specific state.

---

## Real-Life Example: Traffic Light System
A traffic light can be in one of three states:
1. **Red Light**
2. **Green Light**
3. **Yellow Light**

The behavior (e.g., "stop", "go", or "slow down") depends on the current state. The state transitions cyclically: Red → Green → Yellow → Red.

---

## C++ Implementation

Below is the code to implement a traffic light system using the State Design Pattern:

```cpp
#include <iostream>
#include <memory>
#include <string>

// Forward declaration
class TrafficLightState;

// Context Class
class TrafficLightContext {
private:
    std::shared_ptr<TrafficLightState> currentState;

public:
    TrafficLightContext(std::shared_ptr<TrafficLightState> state) : currentState(state) {}

    void setState(std::shared_ptr<TrafficLightState> state) {
        currentState = state;
    }

    void handle();
};

// State Interface
class TrafficLightState {
public:
    virtual ~TrafficLightState() = default;
    virtual void handle(TrafficLightContext& context) = 0;
    virtual std::string getStateName() const = 0;
};

// Concrete State: Red Light
class RedLightState : public TrafficLightState {
public:
    void handle(TrafficLightContext& context) override {
        std::cout << "Red Light: Stop!\n";
        // Transition to the next state
        context.setState(std::make_shared<GreenLightState>());
    }

    std::string getStateName() const override {
        return "Red Light";
    }
};

// Concrete State: Green Light
class GreenLightState : public TrafficLightState {
public:
    void handle(TrafficLightContext& context) override {
        std::cout << "Green Light: Go!\n";
        // Transition to the next state
        context.setState(std::make_shared<YellowLightState>());
    }

    std::string getStateName() const override {
        return "Green Light";
    }
};

// Concrete State: Yellow Light
class YellowLightState : public TrafficLightState {
public:
    void handle(TrafficLightContext& context) override {
        std::cout << "Yellow Light: Slow Down!\n";
        // Transition to the next state
        context.setState(std::make_shared<RedLightState>());
    }

    std::string getStateName() const override {
        return "Yellow Light";
    }
};

// Context method implementation
void TrafficLightContext::handle() {
    std::cout << "Current State: " << currentState->getStateName() << "\n";
    currentState->handle(*this);
}

// Main Function
int main() {
    // Initialize with Red Light
    auto redLight = std::make_shared<RedLightState>();
    TrafficLightContext trafficLight(redLight);

    // Simulate the traffic light system
    for (int i = 0; i < 6; ++i) {
        trafficLight.handle();
    }

    return 0;
}
```

---

## How It Works
1. **Initialization**: The `TrafficLightContext` starts with an initial state, such as `RedLightState`.
2. **State Handling**: The `handle` method in the context delegates the operation to the current state's `handle` method.
3. **State Transition**: Each concrete state decides the next state and transitions the context to it.
4. **Output**: The system transitions through states (Red → Green → Yellow) and performs actions accordingly.

---

## Real-Life Use Cases
1. **Traffic Light System**:
   - Automates transitions between red, yellow, and green lights.
   - Encapsulates light-specific logic into separate classes.

2. **Media Player**:
   - States: Playing, Paused, Stopped.
   - Actions depend on the current state, such as play, pause, or stop.

3. **Document Workflow**:
   - States: Draft, Review, Published.
   - Transitions between states depend on user actions or conditions.

4. **Vending Machine**:
   - States: Idle, HasMoney, Dispensing.
   - Behavior changes based on whether money is inserted or an item is dispensed.

5. **ATM Machine**:
   - States: Idle, CardInserted, PINEntered, Transaction.
   - Actions vary depending on the state, like entering a PIN or withdrawing cash.

---

## Benefits
The State Design Pattern improves maintainability, as state-specific logic is encapsulated in separate classes, and adding a new state involves creating a new class without modifying existing ones.
