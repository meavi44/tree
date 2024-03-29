// evaluation of postfix expression

#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* next;
    Node(int a){
        val=a;
        next=NULL;
    }
};
struct Stack{
    
    Node* head;
    Stack(){
        
        head=NULL;

    }
    void push(int val){
        
        Node* newnode=new Node(val);
        newnode->next=head;
        head=newnode;
        return;

    }
    void pop(){
        if(head==NULL){
            cout<<"invalid"<<endl;
            return;
        }
        Node* temp=head;
        head=head->next;
        free(temp);

    }
    int top(){
        if(head==NULL){
            cout<<" invalid";
            return -3;
        }
        return head->val;
    }
    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
double postfix(string s){
    Stack st;
    for(int i=0;i<s.size();i++){
        char ch=s[i];
        if(ch>='0'&&ch<='9'){
            double k=ch-'0';
            st.push(k);
        }
        else{
            double a=st.top();
            st.pop();
            double b=st.top();
            st.pop();
            if(ch=='*'){
                double result=b*a;
                st.push(result);
            }
            if(ch=='/'){
                double result=a/b;
                st.push(result);
            }
            if(ch=='+'){
                double result=b+a;
                st.push(result);
            }
            if(ch=='-'){
                double result=a-b;
                st.push(result);
            }
            if(ch=='^'){
                double result=pow(a,b);
                st.push(result);
            }
        }
    }
    return st.top();
}

int main(){
    string s;
    cin>>s;
    double result=postfix(s);
    cout<<result;
}