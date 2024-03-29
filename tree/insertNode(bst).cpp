#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node*left;
    Node*right;
    Node(int a){
        val=a;
        left=right=NULL;
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
Node* insert(Node* root,int key){
    if(root==NULL){
        return new Node(key);
    }
    Node* current=root;
    while(true){
        if(current->val<=key){
            if(current->right!=NULL){
                current=current->right;
            }
            else{
                current->right=new Node(key);
                break;
            }
        }
        else{
             if(current->left!=NULL){
                current=current->left;
            }
            else{
                current->left=new Node(key);
                break;
            }
        }
    }
    return root;
}
int main(){
    Node* root=new Node(6);
    root->left=new Node(3);
    root->right=new Node(8);
      root->left->left=new Node(2);
        root->left->right=new Node(4);
          root->right->left=new Node(7);
        inorder(root);
        cout<<endl;
        inorder(insert(root,5));


}