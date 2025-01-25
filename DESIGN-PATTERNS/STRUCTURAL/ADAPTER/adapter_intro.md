# Adapter Design Pattern in C++

## **Overview**

The **Adapter Design Pattern** is a **structural design pattern** that allows two incompatible interfaces to work together. It acts as a bridge between an existing class and a client that expects a different interface. This pattern is particularly useful when integrating third-party libraries, legacy code, or systems with different interfaces.

---

### **Key Concepts:**

1. **Adapter**:
   - The class that translates one interface into another.
2. **Target**:
   - The interface that the client expects.
3. **Adaptee**:
   - The existing class with an incompatible interface.

---

### **Real-Life Use Cases:**

1. **Media Player**:
   - You have an advanced audio player class that can only play `.mp3` files, but your application requires it to support `.mp4` and `.vlc` formats. You can use an adapter to translate requests for `.mp4` or `.vlc` into something the existing `.mp3` player understands.

2. **Payment Gateways**:
   - If an application needs to integrate multiple payment gateways (e.g., PayPal, Stripe), and each gateway has its unique API, you can use an adapter to create a uniform interface for your application.

3. **Legacy System Integration**:
   - Adapting a legacy system's API to work with modern software.

4. **Graphics Rendering**:
   - Bridging between different graphical APIs, e.g., translating OpenGL calls to DirectX.

---

### **Example in C++**

#### Scenario:
Suppose we have a legacy logging system (Adaptee) that uses a specific method for logging messages, but our application expects a different interface.

```cpp
#include <iostream>
#include <string>
using namespace std;

// Target interface expected by the client
class ILogger {
public:
    virtual void LogMessage(const string& message) = 0;
    virtual ~ILogger() = default;
};

// Adaptee: The existing class with an incompatible interface
class LegacyLogger {
public:
    void WriteLog(const string& logMessage) {
        cout << "Legacy Logger: " << logMessage << endl;
    }
};

// Adapter: Bridges the gap between Target and Adaptee
class LoggerAdapter : public ILogger {
private:
    LegacyLogger* legacyLogger;

public:
    LoggerAdapter(LegacyLogger* logger) : legacyLogger(logger) {}

    void LogMessage(const string& message) override {
        // Adapting the interface
        legacyLogger->WriteLog(message);
    }
};

// Client code
void ClientCode(ILogger* logger) {
    logger->LogMessage("Adapter Design Pattern example in C++");
}

int main() {
    LegacyLogger* legacyLogger = new LegacyLogger();
    ILogger* logger = new LoggerAdapter(legacyLogger);

    ClientCode(logger);

    delete logger;
    delete legacyLogger;

    return 0;
}
```

---

### **How It Works:**

1. **Client Code**:
   - Expects an `ILogger` interface.
2. **Legacy Logger**:
   - Uses a different method (`WriteLog`) to log messages.
3. **Adapter**:
   - Implements the `ILogger` interface, internally using the `LegacyLogger`'s `WriteLog` method to adapt the call.

---

### **Benefits of the Adapter Pattern:**

1. **Reusability**:
   - Enables reuse of existing classes even when their interfaces don't match the current requirements.
2. **Interoperability**:
   - Allows systems with incompatible interfaces to work together.
3. **Decoupling**:
   - Isolates the client code from the specific implementation of the Adaptee.

---

### **Drawbacks:**

1. **Increased Complexity**:
   - Adding an adapter adds an extra layer of abstraction.
2. **Performance Overhead**:
   - If the adapter involves complex transformations, it may slightly impact performance.
