# Template Method Design Pattern

The **Template Method Design Pattern** is a behavioral design pattern that defines the skeleton of an algorithm in a base class and allows subclasses to override specific steps of the algorithm without changing its structure.

---

## Key Features:
1. **Skeleton of an Algorithm**: The base class defines the template method that outlines the overall steps of the algorithm.
2. **Customization through Subclasses**: Subclasses override specific steps while keeping the algorithm structure intact.
3. **Reuse**: Common code is reused in the base class, reducing duplication.

---

## Real-Life Example: Coffee Making Process
Consider the process of making coffee. The general steps are:
1. Boil water.
2. Brew the coffee.
3. Pour into a cup.
4. Add condiments (like sugar, milk, etc.).

The overall steps remain the same, but the way we brew coffee or add condiments may vary (e.g., espresso vs. instant coffee). This is where the **Template Method Pattern** fits.

---

## Steps in Template Method Pattern:
1. **Define Abstract Base Class**: Contains the template method and abstract steps.
2. **Implement Concrete Subclasses**: Override abstract steps as needed.

---

## UML Representation:
- **Abstract Class**: Contains the `templateMethod()` and abstract steps.
- **Concrete Subclasses**: Implement specific steps.

---

## Example: Coffee-Making in C++

Here’s how we can implement this example in C++:

```cpp

#include <iostream>
using namespace std;

// Abstract base class defining the template method
class CoffeeTemplate {
public:
    // Template Method
    void makeCoffee() {
        boilWater();
        brew();
        pourInCup();
        addCondiments();
    }

    // Common steps
    void boilWater() {
        cout << "Boiling water...\n";
    }

    void pourInCup() {
        cout << "Pouring into the cup...\n";
    }

    // Steps to be implemented by subclasses
    virtual void brew() = 0;
    virtual void addCondiments() = 0;

    virtual ~CoffeeTemplate() {}
};

// Concrete class for making espresso
class Espresso : public CoffeeTemplate {
public:
    void brew() override {
        cout << "Brewing espresso coffee...\n";
    }

    void addCondiments() override {
        cout << "Adding sugar and milk to espresso...\n";
    }
};

// Concrete class for making instant coffee
class InstantCoffee : public CoffeeTemplate {
public:
    void brew() override {
        cout << "Adding instant coffee powder...\n";
    }

    void addCondiments() override {
        cout << "Adding sugar only...\n";
    }
};

int main() {
    cout << "Making Espresso:\n";
    CoffeeTemplate* espresso = new Espresso();
    espresso->makeCoffee();
    delete espresso;

    cout << "\nMaking Instant Coffee:\n";
    CoffeeTemplate* instantCoffee = new InstantCoffee();
    instantCoffee->makeCoffee();
    delete instantCoffee;

    return 0;
}
```

```
Output :-
Making Espresso:
Boiling water...
Brewing espresso coffee...
Pouring into the cup...
Adding sugar and milk to espresso...

Making Instant Coffee:
Boiling water...
Adding instant coffee powder...
Pouring into the cup...
Adding sugar only...
```

```
Use Cases of Template Method Pattern:
	Game Development: The flow of a game (initialize, run, shutdown) is defined, and specific behaviors for different games are implemented in subclasses.
	Data Parsing: Parsing data from different formats (CSV, JSON, XML) while keeping the general process (read, parse, validate) the same.
	UI Frameworks: Rendering elements on the screen may follow a similar flow, but specific rendering logic is overridden for different components.
This pattern is particularly useful when you want to ensure a consistent process while allowing variations in specific steps.
```
