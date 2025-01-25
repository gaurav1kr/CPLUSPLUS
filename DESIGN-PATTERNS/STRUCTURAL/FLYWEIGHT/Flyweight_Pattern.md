
# Flyweight Design Pattern

The **Flyweight Pattern** is a structural design pattern that aims to minimize memory usage by sharing as much data as possible with similar objects. It is particularly useful when an application needs to create a large number of similar objects. Instead of creating new instances of objects that have identical or similar properties, the pattern shares the common state (intrinsic state) among multiple objects while maintaining a unique state (extrinsic state) outside.

---

## Key Concepts
1. **Intrinsic State**: The part of the object’s state that can be shared because it is independent of the context.
2. **Extrinsic State**: The part of the object’s state that depends on the context and cannot be shared. It is passed to the object externally.

---

## Real-Life Use Cases
1. **Text Editors**: A text editor with many characters on the screen can use a flyweight pattern to share font and style data among identical characters.
2. **Gaming**: In games like chess or checkers, you can use the Flyweight pattern to share common properties of pieces (e.g., color and type).
3. **Document Rendering**: Reuse formatting and font information across multiple paragraphs or pages in a document.
4. **Caching Systems**: Caching frequently used objects like icons or configuration settings.
5. **Particle Systems**: In animations, where many similar particles need to be rendered.

---

## C++ Implementation

Here’s an example of implementing the Flyweight pattern using a **game where multiple trees are drawn on a map**. Each tree shares its **type**, **texture**, and **color** (intrinsic state), but each tree has a unique position (extrinsic state).

### Code Example

```cpp
#include <iostream>
#include <unordered_map>
#include <vector>
#include <memory>
#include <string>

// Flyweight class
class TreeType {
    std::string name;
    std::string color;
    std::string texture;

public:
    TreeType(const std::string& name, const std::string& color, const std::string& texture)
        : name(name), color(color), texture(texture) {}

    void display(int x, int y) const {
        std::cout << "Drawing tree of type [" << name
                  << "] with color [" << color
                  << "] and texture [" << texture
                  << "] at position (" << x << ", " << y << ")\n";
    }
};

// Flyweight Factory
class TreeFactory {
    std::unordered_map<std::string, std::shared_ptr<TreeType>> treeTypes;

public:
    std::shared_ptr<TreeType> getTreeType(const std::string& name, const std::string& color, const std::string& texture) {
        std::string key = name + "_" + color + "_" + texture;
        if (treeTypes.find(key) == treeTypes.end()) {
            treeTypes[key] = std::make_shared<TreeType>(name, color, texture);
            std::cout << "Creating new TreeType: " << key << "\n";
        }
        return treeTypes[key];
    }
};

// Context (contains extrinsic state)
class Tree {
    int x, y;                              // Extrinsic state
    std::shared_ptr<TreeType> treeType;    // Intrinsic state

public:
    Tree(int x, int y, std::shared_ptr<TreeType> treeType)
        : x(x), y(y), treeType(treeType) {}

    void display() const {
        treeType->display(x, y);
    }
};

// Forest class (manages trees)
class Forest {
    std::vector<std::shared_ptr<Tree>> trees;
    TreeFactory treeFactory;

public:
    void plantTree(int x, int y, const std::string& name, const std::string& color, const std::string& texture) {
        auto treeType = treeFactory.getTreeType(name, color, texture);
        trees.push_back(std::make_shared<Tree>(x, y, treeType));
    }

    void display() const {
        for (const auto& tree : trees) {
            tree->display();
        }
    }
};

int main() {
    Forest forest;

    // Plant trees
    forest.plantTree(10, 20, "Oak", "Green", "Rough");
    forest.plantTree(15, 25, "Pine", "Dark Green", "Smooth");
    forest.plantTree(10, 20, "Oak", "Green", "Rough");  // Shared instance
    forest.plantTree(50, 70, "Pine", "Dark Green", "Smooth"); // Shared instance

    // Display all trees
    forest.display();

    return 0;
}
```

---

### How the Flyweight Pattern Works Here
1. **Intrinsic State**: The tree type (name, color, texture) is shared and reused by multiple `Tree` objects.
2. **Extrinsic State**: The position (x, y) of each tree is stored individually in each `Tree` object.
3. **TreeFactory**: Ensures that no duplicate `TreeType` objects are created, conserving memory.

---

### Output

```plaintext
Creating new TreeType: Oak_Green_Rough
Creating new TreeType: Pine_Dark Green_Smooth
Drawing tree of type [Oak] with color [Green] and texture [Rough] at position (10, 20)
Drawing tree of type [Pine] with color [Dark Green] and texture [Smooth] at position (15, 25)
Drawing tree of type [Oak] with color [Green] and texture [Rough] at position (10, 20)
Drawing tree of type [Pine] with color [Dark Green] and texture [Smooth] at position (50, 70)
```

---

## Benefits
1. **Memory Optimization**: Reduces memory usage by sharing objects.
2. **Performance**: Minimizes object creation overhead.
3. **Reusability**: Encourages the reuse of intrinsic state across multiple contexts.

## Drawbacks
1. **Complexity**: Adds extra layers (factory and shared objects) to the code.
2. **Thread Safety**: Sharing objects across threads requires synchronization to avoid issues.

---

This pattern is especially useful when dealing with resource-intensive objects in systems with limited memory or performance constraints, such as game development or GUI frameworks.
