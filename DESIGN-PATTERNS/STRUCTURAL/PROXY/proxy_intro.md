# Proxy Pattern in C++

The **Proxy Pattern** is a structural design pattern that provides a substitute or placeholder for another object. 
A proxy controls access to the original object, allowing you to add extra functionality without modifying the original object's code.

## Real-World Analogy
Think of a proxy pattern as a **credit card** acting as a proxy for your bank account. Instead of directly interacting with your bank (the real subject), you use the credit card to handle transactions (access control, logging, etc.).

---

## Common Use Cases
1. **Remote Proxy**:
   - Used to represent an object located in a different address space (e.g., network communication).
   - Example: A client accessing a remote service via Remote Procedure Call (RPC) or gRPC.

2. **Virtual Proxy**:
   - Used to manage the creation and initialization of resource-intensive objects.
   - Example: Loading large images on-demand in a graphics application.

3. **Protection Proxy**:
   - Used to control access to sensitive objects based on permissions.
   - Example: Restricting access to a shared document based on user roles.

4. **Logging Proxy**:
   - Used to log requests to the actual object.
   - Example: Logging all queries made to a database.

5. **Caching Proxy**:
   - Used to cache results of expensive operations.
   - Example: Caching API responses in a web application.

---

## Structure
- **Subject Interface**: Common interface for the RealSubject and Proxy.
- **RealSubject**: The real object that the Proxy represents.
- **Proxy**: Intercepts requests to the RealSubject and may add extra behavior.

---

## Example in C++: Protection Proxy

Imagine a scenario where an employee system restricts access to confidential data based on their role.

### Code

```cpp
#include <iostream>
#include <string>
#include <memory>

// Subject Interface
class IEmployeeData {
public:
    virtual void accessData() const = 0;
    virtual ~IEmployeeData() = default;
};

// Real Subject
class EmployeeData : public IEmployeeData {
public:
    void accessData() const override {
        std::cout << "Accessing confidential employee data...\\n";
    }
};

// Proxy
class EmployeeDataProxy : public IEmployeeData {
private:
    std::unique_ptr<EmployeeData> realEmployeeData;
    std::string role;

public:
    explicit EmployeeDataProxy(const std::string& userRole)
        : realEmployeeData(std::make_unique<EmployeeData>()), role(userRole) {}

    void accessData() const override {
        if (role == "Manager" || role == "Admin") {
            std::cout << "Permission granted. ";
            realEmployeeData->accessData();
        } else {
            std::cout << "Permission denied. You do not have access to this data.\\n";
        }
    }
};

int main() {
    // Role-based access
    std::unique_ptr<IEmployeeData> proxy1 = std::make_unique<EmployeeDataProxy>("Manager");
    proxy1->accessData();

    std::unique_ptr<IEmployeeData> proxy2 = std::make_unique<EmployeeDataProxy>("Employee");
    proxy2->accessData();

    return 0;
}

Explanation of Code
1. Interface (IEmployeeData):
	Defines the common interface for both the real object (EmployeeData) and the proxy (EmployeeDataProxy).

2. RealSubject (EmployeeData):
	Implements the core functionality of accessing data.

3. Proxy (EmployeeDataProxy):
	Adds role-based access control before delegating requests to the real subject.

4. Client:
	Uses the proxy object, which enforces access control without directly interacting with the real subject.

Outputs
Permission granted. Accessing confidential employee data...
Permission denied. You do not have access to this data.
