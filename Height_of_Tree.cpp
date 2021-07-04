#include<bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
    Node(int val){
        data =val;
        left=NULL;
        right=NULL;
    }

};
//Function for creating new node
Node* GetNewNode(int data){
    Node* newNode=new Node(data);
    return newNode;
}
//Function for inserting new node in binary tree
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
//Function for finding height of a tree
int Height(Node* root){
    if(root==NULL)
        return -1;
    int lefth=Height(root->left);  //This will return height of left subtree
    int righth=Height(root->right); //This will return height of right subtree
    return max(lefth,righth)+1;
}

int main(){
  
     Node* root =NULL;
    root=Insert(root,15);
    root=Insert(root,16);
    root=Insert(root,12);
    root=Insert(root,8);
    root=Insert(root,22);
    root=Insert(root,11);
    int height=Height(root);
    cout<<height;

    return 0;
}