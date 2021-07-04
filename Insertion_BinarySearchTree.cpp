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
bool Search(Node* root ,int data){
    if(root==NULL){
        cout<<"Not Fpund "<<endl;
        return false;
    }
    else if(root->data==data){
        cout<<"Found "<<endl;
    }else if(data<=root->data){
        Search(root->left,data);
    }else{
        Search(root->right,data);
    }
    return false;
}

int main(){
    Node* root =NULL;
    root=Insert(root,15);
    root=Insert(root,16);
    root=Insert(root,12);
    root=Insert(root,8);
    root=Insert(root,22);
    root=Insert(root,11);
    bool ans=Search(root,28);
    cout<<ans;
    


    return 0;
}