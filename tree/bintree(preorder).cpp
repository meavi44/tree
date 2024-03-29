#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to insert values into the binary tree recursively
TreeNode* insert(TreeNode* root, vector<int>& values, int index) {
    // Base case: if index exceeds the size of the values array, return nullptr
    if (index >= values.size())
        return nullptr;

    // Create a new node with the value at the current index
    TreeNode* newNode = new TreeNode(values[index]);

    // Recursively insert left and right children
    newNode->left = insert(nullptr, values, 2 * index + 1);
    newNode->right = insert(nullptr, values, 2 * index + 2);

    return newNode;
}
int maxdepth(TreeNode*&root){
    if(root==NULL){
        return 0;
    }
    int lh=maxdepth(root->left);
    int rh=maxdepth(root->right);
    return 1+max(lh,rh);

}

int main() {
    // Values to insert into the binary tree
    vector<int> values = {1, 2, 3, 4, 5, 6};

    // Creating the binary tree
    TreeNode* root = insert(nullptr, values, 0);

    // Now you have the binary tree created with the given values
    // You can perform any operations or traversals on this tree
    cout<<maxdepth(root);
    return 0;
}
