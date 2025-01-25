# Observer Design Pattern Example in C++

## Introduction
The **Observer Design Pattern** is a behavioral design pattern used when you need to notify multiple objects (observers) about changes in the state of another object (the subject). It's commonly used for implementing distributed event-handling systems.

### Real-life Example: **Weather Monitoring System**
Imagine a weather station that updates its temperature, and multiple displays (e.g., TV, Phone App, LED Board) want to get notified whenever the temperature changes.

---

## **Code Implementation**

```cpp

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm> // For std::remove

// Forward declaration
class Observer;

// Subject (Weather Station)
class Subject {
public:
    virtual void attach(std::shared_ptr<Observer> observer) = 0;
    virtual void detach(std::shared_ptr<Observer> observer) = 0;
    virtual void notify() = 0;
    virtual ~Subject() = default;
};

// Observer Interface
class Observer {
public:
    virtual void update(float temperature) = 0;
    virtual ~Observer() = default;
};

// Concrete Subject (Weather Station)
class WeatherStation : public Subject {
private:
    std::vector<std::shared_ptr<Observer>> observers;
    float temperature = 0.0f;

public:
    void attach(std::shared_ptr<Observer> observer) override {
        observers.push_back(observer);
    }

    void detach(std::shared_ptr<Observer> observer) override {
        // Use std::find to locate the observer before removing
        auto it = std::find(observers.begin(), observers.end(), observer);
        if (it != observers.end()) {
            observers.erase(it);
        }
    }

    void notify() override {
        for (auto& observer : observers) {
            if (observer) {
                observer->update(temperature);
            }
        }
    }

    void setTemperature(float temp) {
        temperature = temp;
        notify(); // Notify all observers when temperature changes
    }
};

// Concrete Observers
class PhoneDisplay : public Observer {
private:
    std::string name;

public:
    explicit PhoneDisplay(const std::string& displayName) : name(displayName) {}
    void update(float temperature) override {
        std::cout << name << " Phone Display: Temperature updated to " << temperature << "°C\n";
    }
};

class LEDBoardDisplay : public Observer {
private:
    std::string location;

public:
    explicit LEDBoardDisplay(const std::string& loc) : location(loc) {}
    void update(float temperature) override {
        std::cout << "LED Board at " << location << ": Temperature is now " << temperature << "°C\n";
    }
};

// Client Code
int main() {
    // Create WeatherStation (Subject)
    std::shared_ptr<WeatherStation> weatherStation = std::make_shared<WeatherStation>();

    // Create Observers
    std::shared_ptr<Observer> phoneDisplay = std::make_shared<PhoneDisplay>("Home");
    std::shared_ptr<Observer> ledBoardDisplay = std::make_shared<LEDBoardDisplay>("City Center");

    // Attach Observers to the WeatherStation
    weatherStation->attach(phoneDisplay);
    weatherStation->attach(ledBoardDisplay);

    // Simulate temperature changes
    weatherStation->setTemperature(25.5f); // Notify all observers
    weatherStation->setTemperature(30.2f); // Notify all observers

    // Detach one observer and update temperature again
    weatherStation->detach(phoneDisplay);
    weatherStation->setTemperature(28.0f); // Only LED Board is notified

    return 0;
}

```

---

## **Explanation of the Code**

1. **Subject Interface**:
   - Defines methods to attach, detach, and notify observers.

2. **Concrete Subject (WeatherStation)**:
   - Maintains a list of observers and notifies them whenever the temperature changes.

3. **Observer Interface**:
   - Provides a method (`update`) that will be called whenever the subject's state changes.

4. **Concrete Observers**:
   - `PhoneDisplay` and `LEDBoardDisplay` implement the `Observer` interface and react to state changes in the `WeatherStation`.

5. **Client Code**:
   - Simulates the addition and removal of observers and the notification mechanism.

---

## **Output Example**
```
Home Phone Display: Temperature updated to 25.5°C
LED Board at City Center: Temperature is now 25.5°C
Home Phone Display: Temperature updated to 30.2°C
LED Board at City Center: Temperature is now 30.2°C
LED Board at City Center: Temperature is now 28.0°C
```

---

This implementation ensures that any number of observers can subscribe to the subject, and they are notified whenever the subject's state changes. This pattern is widely used in GUIs, event systems, and real-time data monitoring applications.
