# Composite Design Pattern

## Overview

The **Composite Design Pattern** is a structural design pattern that allows you to compose objects into tree structures to represent part-whole hierarchies. It lets clients treat individual objects and compositions of objects uniformly.

---

## Purpose

The Composite Pattern allows you to create tree structures where individual objects (leaves) and groups of objects (composites) can be treated uniformly. This is especially useful when dealing with hierarchies, where the exact nature of the object (whether it’s a simple or complex object) doesn’t need to concern the client.

---

## Key Components

1. **Component**
   - Defines the interface for all objects in the composition.
   - Declares common operations like `add`, `remove`, or `display`.

2. **Leaf**
   - Represents a single object that does not have any children.
   - Implements all operations defined by the `Component`.

3. **Composite**
   - Represents a complex object (a group of components).
   - Stores child components and implements operations to manage them (e.g., `add`, `remove`).

4. **Client**
   - Interacts with the objects through the `Component` interface without worrying about whether it’s dealing with a leaf or a composite.

---

## Real-Life Example: File System

A **file system** is a perfect example:
- **Leaf**: Individual files (e.g., `file1.txt`).
- **Composite**: Directories, which can contain files or other directories.
- **Component**: Abstracts both files and directories under a common interface so that the client can perform operations like `display` or `calculate size`.

---

## C++ Implementation

Here’s how you can implement a file system hierarchy using the Composite Design Pattern:

```cpp

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <algorithm> // Ensure this header is included

// Component: Abstract base class for both Files and Directories
class FileSystemComponent {
public:
    virtual void display(int indent = 0) const = 0; // For hierarchy visualization
    virtual ~FileSystemComponent() = default;
};

// Leaf: Represents a single file
class File : public FileSystemComponent {
private:
    std::string name;

public:
    explicit File(const std::string& fileName) : name(fileName) {}

    void display(int indent = 0) const override {
        std::cout << std::string(indent, '-') << "File: " << name << "\n";
    }
};

// Composite: Represents a directory
class Directory : public FileSystemComponent {
private:
    std::string name;
    std::vector<std::shared_ptr<FileSystemComponent>> children;

public:
    explicit Directory(const std::string& dirName) : name(dirName) {}

    void add(const std::shared_ptr<FileSystemComponent>& component) {
        children.push_back(component);
    }

    void remove(const std::shared_ptr<FileSystemComponent>& component) {
        children.erase(std::remove(children.begin(), children.end(), component), children.end());
    }

    void display(int indent = 0) const override {
        std::cout << std::string(indent, '-') << "Directory: " << name << "\n";
        for (const auto& child : children) {
            child->display(indent + 2); // Indent to show hierarchy
        }
    }
};

int main() {
    // Create individual files
    auto file1 = std::make_shared<File>("file1.txt");
    auto file2 = std::make_shared<File>("file2.txt");
    auto file3 = std::make_shared<File>("file3.txt");

    // Create directories
    auto dir1 = std::make_shared<Directory>("Folder1");
    auto dir2 = std::make_shared<Directory>("Folder2");
    auto rootDir = std::make_shared<Directory>("Root");

    // Compose hierarchy
    dir1->add(file1);
    dir1->add(file2);

    dir2->add(file3);

    rootDir->add(dir1);
    rootDir->add(dir2);

    // Display the structure
    rootDir->display();

    return 0;
}

```

---

## Explanation of the Code

1. **FileSystemComponent**: 
   - Defines the abstract interface (`display`) that is implemented by both `File` and `Directory`.

2. **File**:
   - Represents the leaf. It provides its own implementation of `display`.

3. **Directory**:
   - Represents the composite. It contains a list of `FileSystemComponent` objects (both files and directories).
   - Provides methods to `add` and `remove` components and recursively calls `display` on its children.

4. **Main Function**:
   - Demonstrates how to build a hierarchy (files and directories) and how the client can treat everything uniformly via the `FileSystemComponent` interface.

---

## Output

```
Directory: Root
--Directory: Folder1
----File: file1.txt
----File: file2.txt
--Directory: Folder2
----File: file3.txt
```

---

## Benefits

1. Simplifies code that uses object hierarchies.
2. Easy to add new types of components (e.g., symbolic links in a file system).
3. Reduces conditional logic by relying on polymorphism.

---
