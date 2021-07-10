#include<bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }

};
//Iterative Inorder Traversal
void InorderIterative(Node* root){
    stack<Node*> st;
    Node* curr=root;
    while(!st.empty()|| curr!=NULL){
        while(curr!=NULL){
            st.push(curr);
            curr=curr->left;
        }
        curr=st.top();
        st.pop();
        cout<<curr->data<<" ";
        curr=curr->right;  
    }

}
//Preoder Traversal Iterative->Space Complexity is O
void PreorderIterative(Node* root){
    stack<Node*> st;
    Node* curr=root;
   
    while(!st.empty()|| curr!=NULL){
        while(curr!=NULL){
            cout<<curr->data<<" ";
            if(curr->right){
                st.push(curr->right);
            }
            curr=curr->left;
        }
        if(st.empty()==false){
            curr=st.top();
            st.pop();
        }

    }
}

Node* GetNewNode(int data){
    Node* newNode=new Node(data);
    return newNode;
}
Node* Insert(Node*root,int data){
    if(root==NULL){
        root=GetNewNode(data);
    }
    else if(data<=root->data){
        root->left=Insert(root->left,data);
    }
    else{
        root->right=Insert(root->right,data);
    }
    return root;
    
}



int main(){
    Node* root =NULL;
    root=Insert(root,15);
    root=Insert(root,16);
    root=Insert(root,12);
    root=Insert(root,8);
    root=Insert(root,22);
    root=Insert(root,11);
    root=Insert(root,28);
    root=Insert(root,10);
    InorderIterative(root);
    return 0;
}