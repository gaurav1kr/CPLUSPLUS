#include <iostream>
#include <memory>
#include <algorithm> // For std::max

template <typename T>
class MySet 
{
    private:
    struct Node 
    {
        T value;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;
        int height;

        Node(const T& val) : value(val), left(nullptr), right(nullptr), height(1) {}
    };

    std::unique_ptr<Node> root;

    // Get height of a node
    int getHeight(const std::unique_ptr<Node>& node) const 
    {
        return node ? node->height : 0;
    }

    // Calculate balance factor of a node
    int getBalanceFactor(const std::unique_ptr<Node>& node) const 
    {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    // Rotate right
    std::unique_ptr<Node> rotateRight(std::unique_ptr<Node> y) 
    {
        auto x = std::move(y->left);
        auto T2 = std::move(x->right);

        x->right = std::move(y);
        x->right->left = std::move(T2);

        // Update heights
        x->right->height = std::max(getHeight(x->right->left), getHeight(x->right->right)) + 1;
        x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    // Rotate left
    std::unique_ptr<Node> rotateLeft(std::unique_ptr<Node> x) 
    {
        auto y = std::move(x->right);
        auto T2 = std::move(y->left);

        y->left = std::move(x);
        y->left->right = std::move(T2);

        // Update heights
        y->left->height = std::max(getHeight(y->left->left), getHeight(y->left->right)) + 1;
        y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    // Insert helper with AVL balancing
    std::unique_ptr<Node> insertHelper(std::unique_ptr<Node> node, const T& value, bool& inserted) 
    {
        if (!node) 
        {
            inserted = true;
            return std::make_unique<Node>(value);
        }

        if (value < node->value) 
        {
            node->left = insertHelper(std::move(node->left), value, inserted);
        }
        else if (value > node->value) 
        {
            node->right = insertHelper(std::move(node->right), value, inserted);
        }
        else 
        {
            // Duplicate values are not allowed
            inserted = false;
            return node;
        }

        // Update height of the current node
        node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;

        // Balance the node
        int balance = getBalanceFactor(node);

        // Left Left Case
        if (balance > 1 && value < node->left->value)
            return rotateRight(std::move(node));

        // Right Right Case
        if (balance < -1 && value > node->right->value)
            return rotateLeft(std::move(node));

        // Left Right Case
        if (balance > 1 && value > node->left->value) 
        {
            node->left = rotateLeft(std::move(node->left));
            return rotateRight(std::move(node));
        }

        // Right Left Case
        if (balance < -1 && value < node->right->value) 
        {
            node->right = rotateRight(std::move(node->right));
            return rotateLeft(std::move(node));
        }

        return node;
    }

    // Find the minimum value node in a subtree
    Node* findMin(Node* node) const 
    {
        while (node->left) 
        {
            node = node->left.get();
        }
        return node;
    }

    // Erase helper with AVL balancing
    std::unique_ptr<Node> eraseHelper(std::unique_ptr<Node> node, const T& value, bool& erased) 
    {
        if (!node) 
        {
            erased = false;
            return nullptr; // Value not found
        }

        if (value < node->value) 
        {
            node->left = eraseHelper(std::move(node->left), value, erased);
        }
        else if (value > node->value) 
        {
            node->right = eraseHelper(std::move(node->right), value, erased);
        }
        else 
        {
            // Node to be deleted found
            erased = true;

            if (!node->left || !node->right) 
            {
                return std::move(node->left ? node->left : node->right);
            }
            else 
            {
                Node* minNode = findMin(node->right.get());
                node->value = minNode->value;
                node->right = eraseHelper(std::move(node->right), minNode->value, erased);
            }
        }

        if (!node) return nullptr;

        // Update height
        node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;

        // Balance the node
        int balance = getBalanceFactor(node);

        // Left Left Case
        if (balance > 1 && getBalanceFactor(node->left) >= 0)
            return rotateRight(std::move(node));

        // Left Right Case
        if (balance > 1 && getBalanceFactor(node->left) < 0) 
        {
            node->left = rotateLeft(std::move(node->left));
            return rotateRight(std::move(node));
        }

        // Right Right Case
        if (balance < -1 && getBalanceFactor(node->right) <= 0)
            return rotateLeft(std::move(node));

        // Right Left Case
        if (balance < -1 && getBalanceFactor(node->right) > 0) 
        {
            node->right = rotateRight(std::move(node->right));
            return rotateLeft(std::move(node));
        }

        return node;
    }

    // In-order traversal
    void inOrderTraversal(const std::unique_ptr<Node>& node) const 
    {
        if (!node) return;

        inOrderTraversal(node->left);
        std::cout << node->value << " ";
        inOrderTraversal(node->right);
    }

public:
    MySet() : root(nullptr) {}

    // Insert a value
    bool insert(const T& value) 
    {
        bool inserted = false;
        root = insertHelper(std::move(root), value, inserted);
        return inserted;
    }

    // Erase a value
    bool erase(const T& value) 
    {
        bool erased = false;
        root = eraseHelper(std::move(root), value, erased);
        return erased;
    }

    // Check if a value exists
    bool contains(const T& value) const 
    {
        Node* current = root.get();
        while (current) 
        {
            if (value < current->value) 
            {
                current = current->left.get();
            }
            else if (value > current->value) 
            {
                current = current->right.get();
            }
            else 
            {
                return true;
            }
        }
        return false;
    }

    // Display the set (in-order traversal)
    void display() const 
    {
        inOrderTraversal(root);
        std::cout << std::endl;
    }
};

int main() 
{
    MySet<int> mySet;

    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(30);
    mySet.insert(40);
    mySet.insert(50);
    mySet.insert(25);

    std::cout << "Set after insertions: ";
    mySet.display();

    mySet.erase(10);
    std::cout << "Set after erasing 10: ";
    mySet.display();

    mySet.erase(40);
    std::cout << "Set after erasing 40: ";
    mySet.display();

    return 0;
}
