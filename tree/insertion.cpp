#include <iostream>
#include <vector>

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

    // Function to build a tree from inorder and preorder traversals
    Node* buildTree(vector<int>& inorder, vector<int>& preorder, int inStart, int inEnd, int preStart) {
        if (inStart > inEnd)
            return nullptr;

        // Find the root node (first element in the preorder)
        Node* root = new Node(preorder[preStart]);

        // Find the position of the root in the inorder traversal
        int rootIndex;
        for (int i = inStart; i <= inEnd; ++i) {
            if (inorder[i] == preorder[preStart]) {
                rootIndex = i;
                break;
            }
        }

        // Recursively build left and right subtrees
        root->left = buildTree(inorder, preorder, inStart, rootIndex - 1, preStart + 1);
        root->right = buildTree(inorder, preorder, rootIndex + 1, inEnd, preStart + (rootIndex - inStart) + 1);

        return root;
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
void printpreorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    printpreorder(root->left);
    printpreorder(root->right);
}

int main() {
    vector<int> inorder = {4, 2, 5, 1, 6, 3};
    vector<int> preorder = {1, 2, 4, 5, 3, 6};

    BinaryTree tree;
    tree.root = tree.buildTree(inorder, preorder, 0, inorder.size() - 1, 0);

    // Print inorder traversal of the constructed binary tree
    cout << "Inorder traversal of binary tree: ";
    tree.printInorder();
    printpreorder(tree.root);

    return 0;
}
