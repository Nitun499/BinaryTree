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
Node* prevous=NULL;
int ans=INT_MAX;
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    if(prevous!=NULL){
        ans=min(ans,(root->data-prevous->data));
    }
    prevous=root;
    inorder(root->right);
}
int MinimumDifference(Node* root){

   inorder(root);
   return ans;

}


int main(){
      Node* root =NULL;
    root=Insert(root,16);
    root=Insert(root,15);
    root=Insert(root,12);
    root=Insert(root,8);
    root=Insert(root,22);
    root=Insert(root,11);
    root=Insert(root,28);
    root=Insert(root,10);
    int res=MinimumDifference(root);
    cout<<res;
    
    return 0;
}