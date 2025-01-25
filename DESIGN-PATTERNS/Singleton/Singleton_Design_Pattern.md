
# Singleton Design Pattern

The Singleton Design Pattern ensures that a class has only one instance throughout the application and provides a global access point to that instance. It is widely used in scenarios where only one instance of a class is needed to coordinate actions, such as logging, database connections, or configuration management.

## Key Characteristics of Singleton:
1. **Single Instance:** Ensures only one instance of the class is created.
2. **Global Access Point:** Provides a way to access this instance.
3. **Lazy Initialization:** The instance is created only when needed (optional but common).

---
A generic implementation of singleton looks like below -

```
#include <iostream>

class Singleton {
public:
    // Static method to access the singleton instance
    static Singleton& getInstance()
    {
        // If the instance doesn't exist, create it
        if (!instance) {
            instance = new Singleton();
        }
        return *instance;
    }

    // Public method to perform some operation
    void someOperation()
    {
        std::cout
            << "Singleton is performing some operation."
            << std::endl;
    }

    // Delete the copy constructor and assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

private:
    // Private constructor to prevent external instantiation
    Singleton()
    {
        std::cout << "Singleton instance created."
                  << std::endl;
    }

    // Private destructor to prevent external deletion
    ~Singleton()
    {
        std::cout << "Singleton instance destroyed."
                  << std::endl;
    }

    // Private static instance variable
    static Singleton* instance;
};

// Initialize the static instance variable to nullptr
Singleton* Singleton::instance = nullptr;

int main()
{
    // Access the Singleton instance
    Singleton& singleton = Singleton::getInstance();

    // Use the Singleton instance
    singleton.someOperation();

    // Attempting to create another instance will not work
    // Singleton anotherInstance; // This line would not
    // compile

    return 0;
}

```
## Real-World Example: Logger Class

In many applications, a logging utility is required to write logs to a file or console. Using a singleton ensures that all parts of the application use the same logging instance, avoiding file corruption or duplication of resources.

### Implementation in C++

```cpp
#include <iostream>
#include <fstream>
#include <memory>
#include <mutex>
#include <string>

// Logger Singleton Class
class Logger {
private:
    static std::unique_ptr<Logger> instance; // Unique instance of Logger
    static std::mutex mutex;                // Mutex for thread safety
    std::ofstream logFile;                  // Log file stream

    // Private constructor to prevent direct instantiation
    Logger() {
        logFile.open("app.log", std::ios::app);
        if (!logFile.is_open()) {
            throw std::runtime_error("Unable to open log file.");
        }
    }

public:
    // Deleted copy constructor and assignment operator to prevent duplication
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    // Destructor to close the log file
    ~Logger() {
        if (logFile.is_open()) {
            logFile.close();
        }
    }

    // Static method to get the single instance of Logger
    static Logger* getInstance() {
        std::lock_guard<std::mutex> lock(mutex);
        if (instance == nullptr) {
            instance.reset(new Logger());
        }
        return instance.get();
    }

    // Method to log a message
    void log(const std::string& message) {
        std::lock_guard<std::mutex> lock(mutex);
        if (logFile.is_open()) {
            logFile << message << std::endl;
        }
    }
};

// Initialize static members
std::unique_ptr<Logger> Logger::instance = nullptr;
std::mutex Logger::mutex;

// Example usage
int main() {
    Logger* logger = Logger::getInstance();
    logger->log("Application started.");
    logger->log("Performing some operations...");
    logger->log("Application ended.");

    return 0;
}
```

---

## Explanation:
1. **Private Constructor:** The constructor is private to prevent direct instantiation of the class.
2. **Static Instance:** A static `unique_ptr` is used to hold the single instance of the class.
3. **Thread-Safety:** A `std::mutex` ensures thread safety when creating the instance or writing to the log file.
4. **Deleted Copy Constructor:** Prevents copying or assignment of the singleton instance, ensuring only one instance exists.

---

## Real Scenario in Action:
- **Logging:** Used in real-world applications like logging frameworks (e.g., `log4j`, `spdlog`).
- **Database Connection Pooling:** Ensures a single connection pool instance is shared across threads.
- **Configuration Management:** Centralizes application settings in a single instance.

This implementation ensures thread safety, lazy initialization, and clean resource management.
