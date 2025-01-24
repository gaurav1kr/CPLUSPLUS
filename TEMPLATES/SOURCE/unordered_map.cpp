#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <functional>

template <typename Key, typename Value>
class UnorderedMap 
{
private:
    // Node for the hashmap's buckets
    struct Node 
    {
        Key key;
        Value value;
    };

    // Vector of buckets (each bucket is a list of nodes)
    std::vector<std::list<Node>> buckets;
    size_t bucketCount;  // Number of buckets
    size_t size;         // Total number of elements
    float loadFactor;    // Maximum load factor

    // Hash function
    size_t hashFunction(const Key& key) const 
    {
        return std::hash<Key>{}(key) % bucketCount;
    }

    // Rehash to increase the bucket count and redistribute elements
    void rehash() 
    {
        size_t newBucketCount = bucketCount * 2;
        std::vector<std::list<Node>> newBuckets(newBucketCount);

        for (const auto& bucket : buckets) 
        {
            for (const auto& node : bucket) 
            {
                size_t newIndex = std::hash<Key>{}(node.key) % newBucketCount;
                newBuckets[newIndex].emplace_back(node);
            }
        }

        buckets = std::move(newBuckets);
        bucketCount = newBucketCount;
    }

public:
    // Constructor
    UnorderedMap(size_t initialBucketCount = 8, float maxLoadFactor = 0.75)
        : bucketCount(initialBucketCount), size(0), loadFactor(maxLoadFactor) {
        buckets.resize(bucketCount);
    }

    // Insert or update a key-value pair
    void insert(const Key& key, const Value& value)
    {
        size_t index = hashFunction(key);

        // Check if the key already exists and update it
        for (auto& node : buckets[index]) 
        {
            if (node.key == key) 
            {
                node.value = value;
                return;
            }
        }

        // Insert new node
        buckets[index].emplace_back(Node{ key, value });
        size++;

        // Check load factor and rehash if necessary
        if (static_cast<float>(size) / bucketCount > loadFactor) 
        {
            rehash();
        }
    }

    // Find a value by key
    Value* find(const Key& key) 
    {
        size_t index = hashFunction(key);

        for (auto& node : buckets[index]) 
        {
            if (node.key == key) 
            {
                return &node.value;
            }
        }
        return nullptr; // Key not found
    }

    // Erase a key-value pair by key
    void erase(const Key& key) 
    {
        size_t index = hashFunction(key);

        for (auto it = buckets[index].begin(); it != buckets[index].end(); ++it) 
        {
            if (it->key == key) 
            {
                buckets[index].erase(it);
                size--;
                return;
            }
        }
    }

    // Access or insert a key-value pair using []
    Value& operator[](const Key& key) 
    {
        size_t index = hashFunction(key);

        // Check if the key already exists
        for (auto& node : buckets[index]) 
        {
            if (node.key == key) 
            {
                return node.value;
            }
        }

        // Insert a new default value for the key
        buckets[index].emplace_back(Node{ key, Value{} });
        size++;

        // Check load factor and rehash if necessary
        if (static_cast<float>(size) / bucketCount > loadFactor) 
        {
            rehash();
        }

        return buckets[index].back().value;
    }

    // Get the number of elements
    size_t getSize() const 
    {
        return size;
    }
};

int main() 
{
    UnorderedMap<std::string, int> umap;

    // Insert elements
    umap.insert("Alice", 30);
    umap.insert("Bob", 25);
    umap.insert("Charlie", 35);

    // Access using find
    if (auto val = umap.find("Bob")) 
    {
        std::cout << "Bob's age: " << *val << std::endl;
    }
    else 
    {
        std::cout << "Bob not found!" << std::endl;
    }

    // Erase an element
    umap.erase("Alice");

    // Access using operator[]
    umap["David"] = 40;
    std::cout << "David's age: " << umap["David"] << std::endl;

    // Print all elements
    std::cout << "Size: " << umap.getSize() << std::endl;

    umap.erase("David");
    
    std::cout << "Size: " << umap.getSize() << std::endl;
    return 0;
}

//Features of This Implementation:
//Hash Function: Uses std::hash to generate hash values for keys.
//Collision Resolution: Uses chaining with linked lists.
//Dynamic Resizing: Rehashes the table when the load factor exceeds a threshold.
//
//Core Operations:
//insert: Adds or updates a key-value pair.
//find: Retrieves a value by key.
//erase: Deletes a key-value pair.
//operator[]: Access or insert a value by key.
//Load Factor Management: Ensures efficient lookups and inserts.
//Key Points:
//
//Performance: This implementation ensures 
//O(1) average-time complexity for insertions, deletions, and lookups.
//
//Scalability: Resizes automatically to maintain performance as the number of elements grows.
//Default Values: Uses Value{} as the default when accessing keys that do not exist.
