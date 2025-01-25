# Strategy Pattern

The **Strategy Pattern** is a behavioral design pattern that allows you to define a family of algorithms, encapsulate them, and make them interchangeable. It lets the algorithm vary independently from the clients that use it, promoting open/closed principles (open for extension, closed for modification).

## Key Concepts:
1. **Context**: Maintains a reference to a strategy object and interacts with it exclusively through the strategy interface.
2. **Strategy Interface**: Defines a common interface for all supported algorithms.
3. **Concrete Strategies**: Implement different algorithms that share the same interface.

---

## Real-Life Use Case

Imagine a payment processing system in an e-commerce application where users can pay through various methods, such as:
1. Credit Card
2. PayPal
3. Google Pay

The strategy pattern allows you to encapsulate the logic for each payment method in separate classes, making it easier to add or modify payment options without altering the core payment flow.

---

## Implementation in C++

Here is an example that illustrates the Strategy Pattern for the payment system:

```cpp
#include <iostream>
#include <memory>
#include <string>

// Step 1: Strategy Interface
class PaymentStrategy {
public:
    virtual void pay(int amount) const = 0;
    virtual ~PaymentStrategy() = default;
};

// Step 2: Concrete Strategies
class CreditCardPayment : public PaymentStrategy {
public:
    void pay(int amount) const override {
        std::cout << "Paid " << amount << " using Credit Card.\\n";
    }
};

class PayPalPayment : public PaymentStrategy {
public:
    void pay(int amount) const override {
        std::cout << "Paid " << amount << " using PayPal.\\n";
    }
};

class GooglePayPayment : public PaymentStrategy {
public:
    void pay(int amount) const override {
        std::cout << "Paid " << amount << " using Google Pay.\\n";
    }
};

// Step 3: Context
class PaymentContext {
private:
    std::unique_ptr<PaymentStrategy> strategy;

public:
    void setStrategy(std::unique_ptr<PaymentStrategy> newStrategy) {
        strategy = std::move(newStrategy);
    }

    void executePayment(int amount) const {
        if (strategy) {
            strategy->pay(amount);
        } else {
            std::cout << "No payment strategy set.\\n";
        }
    }
};

// Step 4: Demonstration
int main() {
    PaymentContext context;

    std::cout << "Using Credit Card Payment:\\n";
    context.setStrategy(std::make_unique<CreditCardPayment>());
    context.executePayment(100);

    std::cout << "\\nUsing PayPal Payment:\\n";
    context.setStrategy(std::make_unique<PayPalPayment>());
    context.executePayment(200);

    std::cout << "\\nUsing Google Pay Payment:\\n";
    context.setStrategy(std::make_unique<GooglePayPayment>());
    context.executePayment(300);

    return 0;
}

Code Breakdown
1. Strategy Interface:
	PaymentStrategy is an abstract base class with the pay method.
	All payment methods implement this interface.

2. Concrete Strategies:
	CreditCardPayment, PayPalPayment, and GooglePayPayment classes provide specific implementations for the pay method.

3. Context:
	PaymentContext manages a PaymentStrategy object.
	The setStrategy method allows the strategy to be changed dynamically.
	The executePayment method delegates the payment execution to the current strategy.

Advantages
	Open/Closed Principle: Easily add new payment methods without modifying existing code.
	Encapsulation: Payment logic is encapsulated within specific classes.
	Flexibility: Dynamically switch strategies at runtime.

Other Real-Life Use Cases
	Sorting Algorithms:
	Allowing a program to dynamically choose between QuickSort, MergeSort, or BubbleSort.

Compression:
	Providing multiple compression strategies like Zip, RAR, or Gzip.

Navigation Systems:
	Supporting different route calculation strategies (e.g., shortest path, fastest route, scenic route).

This pattern is widely applicable wherever you want to define multiple behaviors for a task and switch them seamlesslyCode Breakdown
Strategy Interface:
