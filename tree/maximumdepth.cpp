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
};
int maxdepth(Node*&root){
    if(root==NULL){
        return 0;
    }
    int lh=maxdepth(root->left);
    int rh=maxdepth(root->right);
    return 1+max(lh,rh);

}
int main(){
    BinaryTree tree;
    int n;
    cin>>n;
    while(n--){
        int k;
        cin>>k;
        tree.insert(k);
    }
    cout<<maxdepth(tree.root);
}