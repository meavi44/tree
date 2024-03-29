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
Node* findlast(Node* root){
    if(root->right==NULL){
        return root;
    }
    return findlast(root->right);
}

Node* helper(Node*root){
    if(root->left==NULL){
        return root->right;
    }
   else if(root->right==NULL){
    return root->left;
   }
   Node* rightchild=root->right;
   Node* lastright=findlast(root->left);
   lastright->right=rightchild;
   return root->left;
}
Node* deleteNode(Node*root,int key){
    if(root==NULL){
        return NULL;
    }
    if(root->val==key){
        return helper(root);
    }
    Node*temp=root;
    while(root!=NULL){
        if(root->val>key){
            if(root->left!=NULL&&root->left->val==key){
                root->left=helper(root->left);
            }
            else{
                root=root->left;
            }
        }
        else{
             if(root->right!=NULL&&root->right->val==key){
                root->right=helper(root->right);
            }
            else{
                root=root->right;
            }
        }
    }
    return temp;

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
       deleteNode(root,8);
       inorder(root);


}
