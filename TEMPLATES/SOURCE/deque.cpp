#include <iostream>
#include <stdexcept>

template <typename T>
class Deque {
private:
    static const size_t BLOCK_SIZE = 4; // Fixed size of each block
    T** blocks;                        // Array of pointers to blocks
    size_t frontIndex, backIndex;      // Indices for front and back elements
    size_t capacity;                   // Total number of blocks
    size_t size;                       // Current number of elements

    void allocateBlocks(size_t newCapacity) {
        T** newBlocks = new T * [newCapacity];
        for (size_t i = 0; i < newCapacity; ++i) {
            newBlocks[i] = nullptr;
        }

        size_t offset = (newCapacity - capacity) / 2;
        for (size_t i = 0; i < capacity; ++i) {
            newBlocks[i + offset] = blocks[i];
        }

        delete[] blocks;
        blocks = newBlocks;
        capacity = newCapacity;
        frontIndex += offset;
        backIndex += offset;
    }

    void resizeIfNeeded() {
        if (frontIndex == 0 || backIndex == capacity - 1) {
            allocateBlocks(capacity * 2);
        }
    }

public:
    Deque()
        : frontIndex(1), backIndex(0), capacity(2), size(0) {
        blocks = new T * [capacity];
        for (size_t i = 0; i < capacity; ++i) {
            blocks[i] = nullptr;
        }
    }

    ~Deque() {
        for (size_t i = 0; i < capacity; ++i) {
            delete[] blocks[i];
        }
        delete[] blocks;
    }

    void push_front(const T& value) {
        resizeIfNeeded();
        if (blocks[frontIndex - 1] == nullptr) {
            blocks[--frontIndex] = new T[BLOCK_SIZE];
        }
        else {
            --frontIndex;
        }
        blocks[frontIndex][0] = value;
        ++size;
    }

    void push_back(const T& value) {
        resizeIfNeeded();
        if (blocks[backIndex + 1] == nullptr) {
            blocks[++backIndex] = new T[BLOCK_SIZE];
        }
        else {
            ++backIndex;
        }
        blocks[backIndex][0] = value;
        ++size;
    }

    void pop_front() {
        if (size == 0) {
            throw std::underflow_error("Deque is empty");
        }
        delete[] blocks[frontIndex];
        blocks[frontIndex] = nullptr;
        ++frontIndex;
        --size;
    }

    void pop_back() {
        if (size == 0) {
            throw std::underflow_error("Deque is empty");
        }
        delete[] blocks[backIndex];
        blocks[backIndex] = nullptr;
        --backIndex;
        --size;
    }

    T& front() const {
        if (size == 0) {
            throw std::underflow_error("Deque is empty");
        }
        return blocks[frontIndex][0];
    }

    T& back() const {
        if (size == 0) {
            throw std::underflow_error("Deque is empty");
        }
        return blocks[backIndex][0];
    }

    size_t getSize() const {
        return size;
    }

    bool isEmpty() const {
        return size == 0;
    }
};

int main() {
    Deque<int> deque;

    deque.push_back(10);
    deque.push_back(20);
    deque.push_front(5);

    std::cout << "Front: " << deque.front() << "\n";
    std::cout << "Back: " << deque.back() << "\n";

    deque.pop_front();
    std::cout << "After popping front, front: " << deque.front() << "\n";

    deque.pop_back();
    std::cout << "After popping back, back: " << deque.back() << "\n";

    return 0;
}

