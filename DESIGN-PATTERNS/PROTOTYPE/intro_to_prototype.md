# Prototype Design Pattern

The **Prototype Design Pattern** is a creational design pattern that allows creating new objects by copying an existing object (the prototype) rather than creating new objects from scratch. This pattern is particularly useful when object creation is expensive or complex.

---

## Key Concepts
1. **Prototype Interface**: Declares a `clone` method for copying itself.
2. **Concrete Prototype**: Implements the `clone` method to create a copy of itself.
3. **Client**: Uses the `clone` method to duplicate objects.

---

## Advantages
- Reduces the need for subclasses by cloning existing instances.
- Avoids the cost of reinitializing objects when copying is sufficient.
- Simplifies the process of creating objects with complex states.

---

## Real-life Example
Imagine a **resume cloning system** in a job portal. Users can create a new resume by duplicating an existing one and modifying only the details they want to change.

---

## Prototype Pattern with Real-life Example (C++ Code)

```cpp
#include <iostream>
#include <memory>
#include <string>
using namespace std;

// Step 1: Prototype Interface
class Resume {
public:
    virtual ~Resume() {}
    virtual unique_ptr<Resume> clone() const = 0;
    virtual void showDetails() const = 0;
};

// Step 2: Concrete Prototype
class JobSeekerResume : public Resume {
private:
    string name;
    string experience;
    string skills;

public:
    JobSeekerResume(const string& name, const string& experience, const string& skills)
        : name(name), experience(experience), skills(skills) {}

    // Copy Constructor for cloning
    JobSeekerResume(const JobSeekerResume& other)
        : name(other.name), experience(other.experience), skills(other.skills) {}

    // Implementing clone method
    unique_ptr<Resume> clone() const override {
        return make_unique<JobSeekerResume>(*this);
    }

    void setName(const string& newName) { name = newName; }
    void setExperience(const string& newExperience) { experience = newExperience; }
    void setSkills(const string& newSkills) { skills = newSkills; }

    void showDetails() const override {
        cout << "Name: " << name << "\nExperience: " << experience << "\nSkills: " << skills << endl;
    }
};

// Step 3: Client Code
int main() {
    // Original Resume
    unique_ptr<Resume> originalResume = make_unique<JobSeekerResume>("John Doe", "5 years", "C++, Go, Rust");
    cout << "Original Resume Details:\n";
    originalResume->showDetails();

    // Clone the original resume and modify it
    unique_ptr<Resume> clonedResume = originalResume->clone();
    dynamic_cast<JobSeekerResume*>(clonedResume.get())->setName("Jane Smith");
    dynamic_cast<JobSeekerResume*>(clonedResume.get())->setExperience("3 years");
    dynamic_cast<JobSeekerResume*>(clonedResume.get())->setSkills("Python, JavaScript");

    cout << "\nCloned and Modified Resume Details:\n";
    clonedResume->showDetails();

    return 0;
}
```

---

## Explanation of Code
1. **Prototype Interface**: `Resume` declares the `clone` method.
2. **Concrete Prototype**: `JobSeekerResume` implements `clone` using a copy constructor to duplicate itself.
3. **Client**: The `main` function demonstrates how to clone an object and modify its properties without creating a new object from scratch.

---

## Output
```
Original Resume Details:
Name: John Doe
Experience: 5 years
Skills: C++, Go, Rust

Cloned and Modified Resume Details:
Name: Jane Smith
Experience: 3 years
Skills: Python, JavaScript
```

---

## Use Cases
- Document templates (e.g., resumes, reports).
- Game objects where cloning entities is cheaper than initializing them.
- Creating large datasets with minor modifications.
