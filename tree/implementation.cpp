#include <iostream>
#include <queue>

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
struct BinaryTree {

    Node* root;

    // Constructor
    BinaryTree() {
        root = nullptr;
    }

    // Function to insert a node
    void insert(int value) {
        if (root == nullptr) {
            root = new Node(value);
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            if (current->left == nullptr) {
                current->left = new Node(value);
                return;
            } else {
                q.push(current->left);
            }

            if (current->right == nullptr) {
                current->right = new Node(value);
                return;
            } else {
                q.push(current->right);
            }
        }
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
    tree.insert(10);
    tree.insert(7);
    tree.insert(8);

    cout << "Inorder traversal of binary tree: ";
    tree.printInorder();

    return 0;
}
