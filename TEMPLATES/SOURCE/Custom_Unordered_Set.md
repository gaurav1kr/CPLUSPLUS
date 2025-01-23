
# Custom Implementation of Unordered Set in C++

This document contains a custom implementation of an `unordered_set` in C++ using hash tables.

## Code

```cpp
#include <iostream>
#include <vector>
#include <list>
#include <functional>

template <typename KeyType>
class MyUnorderedSet {
private:
    static const size_t DEFAULT_BUCKET_COUNT = 16;
    static const double LOAD_FACTOR_THRESHOLD;

    std::vector<std::list<KeyType>> buckets; // Buckets for hash table
    size_t size;                             // Current number of elements

    // Hash function
    size_t getBucketIndex(const KeyType& key) const {
        return std::hash<KeyType>()(key) % buckets.size();
    }

    // Resize the table when load factor exceeds the threshold
    void rehash() {
        size_t newBucketCount = buckets.size() * 2;
        std::vector<std::list<KeyType>> newBuckets(newBucketCount);

        for (const auto& bucket : buckets) {
            for (const auto& key : bucket) {
                size_t newIndex = std::hash<KeyType>()(key) % newBucketCount;
                newBuckets[newIndex].push_back(key);
            }
        }

        buckets = std::move(newBuckets);
    }

public:
    MyUnorderedSet() : buckets(DEFAULT_BUCKET_COUNT), size(0) {}

    // Insert a key
    bool insert(const KeyType& key) {
        if (contains(key)) return false;

        size_t index = getBucketIndex(key);
        buckets[index].push_back(key);
        ++size;

        if (static_cast<double>(size) / buckets.size() > LOAD_FACTOR_THRESHOLD) {
            rehash();
        }

        return true;
    }

    // Check if a key exists
    bool contains(const KeyType& key) const {
        size_t index = getBucketIndex(key);
        for (const auto& item : buckets[index]) {
            if (item == key) {
                return true;
            }
        }
        return false;
    }

    // Erase a key
    bool erase(const KeyType& key) {
        size_t index = getBucketIndex(key);
        auto& bucket = buckets[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (*it == key) {
                bucket.erase(it);
                --size;
                return true;
            }
        }
        return false;
    }

    // Get current size
    size_t getSize() const {
        return size;
    }

    // Print all elements (for debugging)
    void print() const {
        for (size_t i = 0; i < buckets.size(); ++i) {
            std::cout << "Bucket " << i << ": ";
            for (const auto& key : buckets[i]) {
                std::cout << key << " ";
            }
            std::cout << "\n";
        }
    }
};

template <typename KeyType>
const double MyUnorderedSet<KeyType>::LOAD_FACTOR_THRESHOLD = 0.75;

int main() {
    MyUnorderedSet<int> mySet;

    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(30);

    mySet.print();

    std::cout << "Contains 20? " << (mySet.contains(20) ? "Yes" : "No") << "\n";
    std::cout << "Erasing 20...\n";
    mySet.erase(20);
    mySet.print();

    std::cout << "Contains 20? " << (mySet.contains(20) ? "Yes" : "No") << "\n";

    return 0;
}
```

## Explanation

### Key Components:
1. **Hash Table**: A vector of buckets, where each bucket is a linked list to store elements.
2. **Hash Function**: Computes the hash index for a given key using `std::hash`.
3. **Collision Resolution**: Uses separate chaining (linked list) to handle collisions.
4. **Dynamic Resizing**: Resizes the table when the load factor exceeds the threshold (0.75).

### Complexity:
- **Insert/Find/Erase**: Average-case \(O(1)\), worst-case \(O(n)\) due to collisions.
- **Space**: \(O(n + b)\), where \(b\) is the bucket count.
