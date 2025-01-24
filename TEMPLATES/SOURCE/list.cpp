#include <iostream>
#include <stdexcept>

template <typename T>
class MyList 
{
private:
    struct Node 
    {
        T data;
        Node* prev;
        Node* next;
        Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t size;

public:
    // Constructor
    MyList() : head(nullptr), tail(nullptr), size(0) {}

    // Destructor
    ~MyList() {
        clear();
    }

    // Push element to the back
    void push_back(const T& value) 
    {
        Node* newNode = new Node(value);
        if (!tail) 
        {
            head = tail = newNode;
        }
        else 
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        ++size;
    }

    // Push element to the front
    void push_front(const T& value) 
    {
        Node* newNode = new Node(value);
        if (!head) 
        {
            head = tail = newNode;
        }
        else 
        {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
        ++size;
    }

    // Pop element from the back
    void pop_back() 
    {
        if (!tail) throw std::runtime_error("List is empty");
        Node* temp = tail;
        if (tail->prev)
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else 
        {
            head = tail = nullptr;
        }
        delete temp;
        --size;
    }

    // Pop element from the front
    void pop_front() 
    {
        if (!head) throw std::runtime_error("List is empty");
        Node* temp = head;
        if (head->next) 
        {
            head = head->next;
            head->prev = nullptr;
        }
        else 
        {
            head = tail = nullptr;
        }
        delete temp;
        --size;
    }

    // Get the front element
    T& front() 
    {
        if (!head) throw std::runtime_error("List is empty");
        return head->data;
    }

    // Get the back element
    T& back() 
    {
        if (!tail) throw std::runtime_error("List is empty");
        return tail->data;
    }

    // Check if the list is empty
    bool empty() const 
    {
        return size == 0;
    }

    // Get the size of the list
    size_t get_size() const 
    {
        return size;
    }

    // Clear the list
    void clear() 
    {
        while (head) 
        {
            pop_front();
        }
    }

    // Print the list (for debugging)
    void print() const 
    {
        Node* current = head;
        while (current) 
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() 
{
    MyList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    list.print(); // Output: 1 2 3

    list.push_front(0);
    list.print(); // Output: 0 1 2 3

    list.pop_back();
    list.print(); // Output: 0 1 2

    list.pop_front();
    list.print(); // Output: 1 2

    std::cout << "Front: " << list.front() << std::endl; // Output: 1
    std::cout << "Back: " << list.back() << std::endl;   // Output: 2

    return 0;
}

