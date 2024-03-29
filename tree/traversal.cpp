#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int a){
        val=a;
        left=right=NULL;
    }
};
struct BinaryTree{
    Node* root;
    BinaryTree(){
        root=NULL;
    }
     void insert(int val) {
        if (root == NULL) {
            root = new Node(val);
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            if (current->left == NULL) {
                current->left = new Node(val);
                return;
            } else {
                q.push(current->left);
            }

            if (current->right == NULL) {
                current->right = new Node(val);
                return;
            } else {
                q.push(current->right);
            }
        }
    }
    
};
void inorder(Node* root){
    if(root==NULL){
        return;
    }
     
        inorder(root->left);
       cout<<root->val<<" ";
        inorder(root->right);
}
void postorder(Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";

}
void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
    

}
vector<vector<int>> levelorder(Node*&root){
    vector<vector<int>> ans;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        vector<int>v;
        for(int i=0;i<size;i++){
            
            Node* temp=q.front();
            q.pop();
            if(temp->left!=NULL) q.push(temp->left);
             if(temp->right!=NULL) q.push(temp->right);
            v.push_back(temp->val);
        }
        ans.push_back(v);
    }
    return ans;
}
int main(){
    BinaryTree tree;
    tree.insert(3);
    tree.insert(7);
    tree.insert(9);
    tree.insert(4);
    tree.insert(1);
    tree.insert(10);
    tree.insert(23);
    tree.insert(34);
    tree.insert(42);
    tree.insert(11);
    inorder(tree.root);
    cout<<endl;
    vector<vector<int>> result=levelorder(tree.root);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}
