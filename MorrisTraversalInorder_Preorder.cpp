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
//Morris Inorder Traversal
//There are three steps for morris traversal 
//1->If left child is not there ,then we have to just print data in current node and then simply move towards right side
//2->If left child is there ,then find predecessor of current node in left subtree and then link predecessotr with the current node
void InorderMorris(Node* root){
    if(root==NULL){
        return;
    }
    Node* curr=root;
    while(curr!=NULL){
        if(curr->left==NULL){
            cout<<curr->data<<" ";
            curr=curr->right;
        }
        else{
            Node* prev=curr->left;
            //go to the rightmost node of current node.Second condition for checking whether it is already threaded or not
            while(prev->right!=NULL && prev->right!=curr){
                prev=prev->right;
            }
            //this is the case when tree is not threaded already
            if(prev->right==NULL){
                prev->right=curr;
                curr=curr->left;
            }
            //this is the case when tree is threaded already
            else{
                prev->right=NULL;
                cout<<curr->data<<" ";
                curr=curr->right;
            }
        }
    }
}
//Moris preorder traversal
void PreorderMorris(Node* root){
    if(root==NULL){
        return;
    }
    Node* curr=root;
    while(curr!=NULL){
        if(curr->left==NULL){
            cout<<curr->data<<" ";
            curr=curr->right;
        }
        else{
            Node* prev=curr->left;
            //go to the rightmost node of current node.Second condition for checking whether it is already threaded or not
            while(prev->right!=NULL && prev->right!=curr){
                prev=prev->right;
            }
            //this is the case when tree is not threaded already
            if(prev->right==NULL){
                prev->right=curr;
                //just print data first
                cout<<curr->data<<" ";
                curr=curr->left;
            }
            //this is the case when tree is threaded already
            else{
                prev->right=NULL;
                curr=curr->right;
            }
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
//Generating mirror image of a binary tree
Node* MirrorBinaryTree(Node* root){
    if(root==NULL){
        return root;
    }
    Node* newNode= GetNewNode(root->data);
    newNode->right=MirrorBinaryTree(root->left);
    newNode->left=MirrorBinaryTree(root->right);
    return newNode;
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
    cout<<"Inorder ->";
    InorderMorris(root);
    cout<<endl;
    cout<<"Preorder ->";
    PreorderMorris(root);
    cout<<endl;
    
    Node* newroot=MirrorBinaryTree(root);
    cout<<"Mirror image ->";
    InorderMorris(newroot);

    return 0;
}