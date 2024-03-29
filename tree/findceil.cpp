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
int findCeil(Node* root,int key){   //ceil means root->val>=key
    int ceil=-1;
    while(root!=NULL){
        if(root->data==key){
            ceil=root->data;
            return ceil;
        }
       
      if(root->data<key){
            root=root->right;
        }
        else{
            ceil=root->data;
            root=root->left;
        }
        
    }
    return ceil;
}
int findfloor(Node* root,int key){   //floor means root->val<=key
    int floor=-1;
    while(root!=NULL){
        if(root->data==key){
            floor=root->data;
            return floor;
        }
       
      if(root->data<key){
       floor=root->data;
            root=root->right;
        }
        else{
            
            root=root->left;
        }
        
    }
    return floor;
}
int main(){
     BinaryTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(13);
    tree.insert(3);
    tree.insert(6);
    tree.insert(11);
    tree.insert(2);
      tree.insert(4);
        tree.insert(9);
    cout<<findCeil(tree.root,9);
}