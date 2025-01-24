#include <iostream>
#include <utility> // for std::pair

template <typename Key, typename Value>
class Map 
{
private:
    struct Node 
    {
        Key key;
        Value value;
        Node* left;
        Node* right;

        Node(const Key& k, const Value& v) : key(k), value(v), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // Helper function to insert a key-value pair
    Node* insert(Node* node, const Key& key, const Value& value) 
    {
        if (node == nullptr) 
        {
            return new Node(key, value);
        }

        if (key < node->key) 
        {
            node->left = insert(node->left, key, value);
        }
        else if (key > node->key) 
        {
            node->right = insert(node->right, key, value);
        }
        else 
        {
            // Key already exists, update the value
            node->value = value;
        }
        return node;
    }

    // Helper function to find a node by key
    Node* find(Node* node, const Key& key) const 
    {
        if (node == nullptr || node->key == key) 
        {
            return node;
        }

        if (key < node->key) 
        {
            return find(node->left, key);
        }
        else 
        {
            return find(node->right, key);
        }
    }

    // Find the minimum node in a subtree
    Node* findMin(Node* node) 
    {
        while (node && node->left != nullptr) 
        {
            node = node->left;
        }
        return node;
    }

    // Helper function to erase a node
    Node* erase(Node* node, const Key& key) 
    {
        if (node == nullptr) 
        {
            return nullptr; // Key not found
        }

        if (key < node->key) 
        {
            node->left = erase(node->left, key);
        }
        else if (key > node->key) 
        {
            node->right = erase(node->right, key);
        }
        else 
        {
            // Node to be deleted found
            if (node->left == nullptr && node->right == nullptr) 
            {
                // Case 1: No children
                delete node;
                return nullptr;
            }
            else if (node->left == nullptr) 
            {
                // Case 2: One child (right)
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) 
            {
                // Case 2: One child (left)
                Node* temp = node->left;
                delete node;
                return temp;
            }
            else 
            {
                // Case 3: Two children
                Node* successor = findMin(node->right);
                node->key = successor->key;
                node->value = successor->value;
                node->right = erase(node->right, successor->key);
            }
        }
        return node;
    }

    // Helper function for in-order traversal
    void inorder(Node* node) const 
    {
        if (node == nullptr) 
        {
            return;
        }

        inorder(node->left);
        std::cout << node->key << ": " << node->value << std::endl;
        inorder(node->right);
    }

    // Helper function to delete all nodes
    void destroy(Node* node) 
    {
        if (node) 
        {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }

public:
    Map() : root(nullptr) {}

    ~Map() 
    {
        destroy(root);
    }

    // Insert or update a key-value pair
    void insert(const Key& key, const Value& value) 
    {
        root = insert(root, key, value);
    }

    // Find the value associated with a key
    Value* find(const Key& key) const 
    {
        Node* node = find(root, key);
        if (node) 
        {
            return &node->value;
        }
        return nullptr;
    }

    // Erase a key-value pair by key
    void erase(const Key& key) 
    {
        root = erase(root, key);
    }

    // Print all key-value pairs (in-order traversal)
    void print() const 
    {
        inorder(root);
    }
};

int main() {
    Map<int, std::string> myMap;

    myMap.insert(10, "ten");
    myMap.insert(20, "twenty");
    myMap.insert(5, "five");
    myMap.insert(15, "fifteen");

    std::cout << "Before erasing:" << std::endl;
    myMap.print();

    myMap.erase(20); // Erase key 20
    std::cout << "\nAfter erasing 20:" << std::endl;
    myMap.print();

    myMap.erase(10); // Erase key 10
    std::cout << "\nAfter erasing 10:" << std::endl;
    myMap.print();

    return 0;
}

