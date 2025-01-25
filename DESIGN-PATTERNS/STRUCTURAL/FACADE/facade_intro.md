# Facade Pattern in C++

## **Overview**
The **Facade Pattern** is a structural design pattern that provides a simplified interface to a larger and more complex subsystem. It hides the complexities of the system and provides a cleaner and more understandable way to interact with it. The facade itself does not perform the work but delegates the calls to the subsystem components.

---

### **Key Characteristics**
1. **Simplifies interaction**: Reduces the complexity of interacting with a subsystem.
2. **Promotes loose coupling**: The client code interacts with the facade, not directly with subsystem components, which minimizes dependencies.
3. **Improves maintainability**: Changes in the subsystem do not affect the client, as long as the facade interface remains the same.

---

### **Real-Life Analogy**
Think of a **universal remote control** for your TV, sound system, and gaming console:
- Without the remote, you would need to deal with individual controls for each device (e.g., turning on the TV, setting input modes, adjusting sound, etc.).
- The remote control acts as a **facade**, offering a simplified interface to manage these subsystems.

---

### **Use Cases**
1. **Library Management System**:
   - The subsystem includes book catalogs, member details, and borrowing rules.
   - A facade provides a simple interface for tasks like "borrow a book" or "return a book."

2. **Database Connection**:
   - Connecting to a database involves authentication, query preparation, and error handling.
   - A facade could offer a single `connect()` method that hides these complexities.

3. **Media Conversion Tool**:
   - Converting video/audio files involves multiple codecs, file format checks, and configurations.
   - A facade simplifies this process into a single `convert()` method.

---

## **C++ Implementation of Facade Pattern**

### **Scenario: Home Theater System**
```cpp
#include <iostream>
#include <string>

// Subsystem 1: Television
class Television {
public:
    void turnOn() { std::cout << "Television is ON.\n"; }
    void turnOff() { std::cout << "Television is OFF.\n"; }
};

// Subsystem 2: Sound System
class SoundSystem {
public:
    void setVolume(int level) { std::cout << "Sound System volume set to " << level << ".\n"; }
    void turnOn() { std::cout << "Sound System is ON.\n"; }
    void turnOff() { std::cout << "Sound System is OFF.\n"; }
};

// Subsystem 3: Streaming Service
class StreamingService {
public:
    void connectToService(const std::string &service) { std::cout << "Connected to " << service << " streaming service.\n"; }
    void playMovie(const std::string &movie) { std::cout << "Playing \"" << movie << "\".\n"; }
};

// Facade: Home Theater Facade
class HomeTheaterFacade {
private:
    Television tv;
    SoundSystem soundSystem;
    StreamingService streamingService;

public:
    void watchMovie(const std::string &movie, const std::string &service) {
        std::cout << "Setting up home theater to watch a movie...\n";
        tv.turnOn();
        soundSystem.turnOn();
        soundSystem.setVolume(15);
        streamingService.connectToService(service);
        streamingService.playMovie(movie);
        std::cout << "Enjoy the movie!\n";
    }

    void endMovie() {
        std::cout << "Shutting down home theater...\n";
        soundSystem.turnOff();
        tv.turnOff();
        std::cout << "Goodbye!\n";
    }
};

// Client Code
int main() {
    HomeTheaterFacade homeTheater;

    // Watch a movie
    homeTheater.watchMovie("Inception", "Netflix");

    // End the movie session
    homeTheater.endMovie();

    return 0;
}
```

---

### **How This Works**
1. **Subsystems (`Television`, `SoundSystem`, `StreamingService`)**:
   - Represent the complex parts of the system that the client would need to interact with directly without a facade.

2. **Facade (`HomeTheaterFacade`)**:
   - Simplifies the interaction by providing two main methods: `watchMovie()` and `endMovie()`.

3. **Client**:
   - Only interacts with the facade. The complexity of the subsystems is hidden.

---

### **Advantages**
- Simplifies client interactions with subsystems.
- Reduces dependency on subsystem details, making the system more flexible and easier to maintain.
- Improves readability and scalability.

