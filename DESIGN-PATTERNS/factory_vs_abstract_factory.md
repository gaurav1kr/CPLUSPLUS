# Difference Between Factory Method and Abstract Factory Design Patterns

## Factory Method Pattern

### **Purpose**
- Provides a way to create objects without specifying the exact class of the object that will be created.
- Relies on subclasses to determine which concrete class to instantiate.

### **Implementation**
- A single factory method is defined in the base class (or interface).
- Subclasses override this factory method to create specific objects.

### **Structure**
- You have one abstract method (e.g., `createProduct`) in the base class, and subclasses implement it.

### **Use Case**
- When a class cannot anticipate the type of objects it needs to create.
- When the responsibility of object creation needs to be delegated to subclasses.

### **Example**
```cpp
class Product {
public:
    virtual void use() = 0;
    virtual ~Product() = default;
};

class ConcreteProductA : public Product {
public:
    void use() override { std::cout << "Using Product A\n"; }
};

class Creator {
public:
    virtual Product* factoryMethod() = 0;
    virtual ~Creator() = default;
};

class ConcreteCreatorA : public Creator {
public:
    Product* factoryMethod() override {
        return new ConcreteProductA();
    }
};
```

---

## Abstract Factory Pattern

### **Purpose**
- Provides an interface to create **families of related or dependent objects** without specifying their concrete classes.
- Ensures that objects from the same family are used together.

### **Implementation**
- A set of related factory methods is encapsulated in a single factory interface.
- Concrete factories implement the interface to create specific families of products.

### **Structure**
- You have multiple factory methods to create different products (e.g., `createProductA`, `createProductB`), and concrete factories implement these methods.

### **Use Case**
- When your system needs to work with multiple families of related products.
- When ensuring that a set of related objects (e.g., a GUI theme or database access layer) is used consistently.

### **Example**
```cpp
class AbstractProductA {
public:
    virtual void use() = 0;
    virtual ~AbstractProductA() = default;
};

class AbstractProductB {
public:
    virtual void interact(AbstractProductA* a) = 0;
    virtual ~AbstractProductB() = default;
};

class ConcreteProductA1 : public AbstractProductA {
public:
    void use() override { std::cout << "Using Product A1\n"; }
};

class ConcreteProductB1 : public AbstractProductB {
public:
    void interact(AbstractProductA* a) override {
        std::cout << "Product B1 interacts with ";
        a->use();
    }
};

class AbstractFactory {
public:
    virtual AbstractProductA* createProductA() = 0;
    virtual AbstractProductB* createProductB() = 0;
    virtual ~AbstractFactory() = default;
};

class ConcreteFactory1 : public AbstractFactory {
public:
    AbstractProductA* createProductA() override {
        return new ConcreteProductA1();
    }

    AbstractProductB* createProductB() override {
        return new ConcreteProductB1();
    }
};
```

---

## Key Differences

| **Aspect**             | **Factory Method**                                      | **Abstract Factory**                                      |
|------------------------|--------------------------------------------------------|----------------------------------------------------------|
| **Purpose**            | Creates a single product.                              | Creates families of related products.                   |
| **Granularity**        | Focuses on one product type.                           | Focuses on a group of related products.                 |
| **Class Hierarchy**    | Relies on subclassing to provide specific implementations. | Relies on concrete factories to provide specific implementations. |
| **Flexibility**        | Easier to extend for a single product.                 | Ensures compatibility between related products.         |
| **Example Scenario**   | A document editor creating different types of documents (e.g., Word, PDF). | A GUI toolkit ensuring a consistent theme for widgets (e.g., buttons, textboxes). |
