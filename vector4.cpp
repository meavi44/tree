#include <iostream>

using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Binary Tree class
class BinaryTree {
private:
    Node* root;

public:
    // Constructor
    BinaryTree() {
        root = nullptr;
    }

    // Function to insert a node
    void insert(int value) {
        root = insertRecursive(root, value);
    }

    // Recursive function to insert a node
    Node* insertRecursive(Node* current, int value) {
        if (current == nullptr) {
            return new Node(value);
        }

        // Inserting node in level order
        if (current->left == nullptr) {
            current->left = insertRecursive(current->left, value);
        } else if (current->right == nullptr) {
            current->right = insertRecursive(current->right, value);
        } else {
            // Traverse down the tree in level order
            if (current->left->left == nullptr || current->left->right == nullptr) {
                return insertRecursive(current->left, value);
            } else {
                return insertRecursive(current->right, value);
            }
        }

        return current;
    }

    // Function to print the tree inorder
    void printInorder() {
        printInorderRecursive(root);
        cout << endl;
    }

    // Recursive function to print the tree inorder
    void printInorderRecursive(Node* current) {
        if (current != nullptr) {
            printInorderRecursive(current->left);
            cout << current->data << " ";
            printInorderRecursive(current->right);
        }
    }
};

// Main function
int main() {
    BinaryTree tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);

    cout << "Inorder traversal of binary tree: ";
    tree.printInorder();

    return 0;
}
