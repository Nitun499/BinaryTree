#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node *GetNewNode(int data)
{
    Node *newNode = new Node(data);
    return newNode;
}
//Function for inserting node in binary tree
Node *Insert(Node *root, int data)
{
    if (root == NULL)
    {
        root = GetNewNode(data);
    }
    else if (data <= root->data)
    {
        root->left = Insert(root->left, data);
    }
    else
    {
        root->right = Insert(root->right, data);
    }
    return root;
}

//Recursive way->O(nLogn)
//Problem is that it will not print nodes in same order as they appears in level
void Findmap(Node* root,int hd,map<int,vector<int>> &m){
    if(root==NULL){
        return;
    }
    m[hd].push_back(root->data);
    Findmap(root->left,hd-1,m);
    Findmap(root->right,hd+1,m);
}
void VerticalView(Node* root){
    map<int,vector<int>> mp;
    int hd=0;
    Findmap(root,hd,mp);
    for(auto it=mp.begin(); it !=mp.end();it++){
        for(int i=0;i<it->second.size(); i++){
            cout<<it->second[i]<<" ";
        }
        cout<<endl;
    }
}
//Iterative Way ->Level Order Traversal
void VerticalIterative(Node* root){
    if(root==NULL){
        return;
    }
    map<int,vector<int>> mp;
    queue<pair<Node*,int>> q;
    int hd=0;
    q.push(make_pair(root,hd));
    while(!q.empty()){
        pair<Node* ,int> p=q.front();
        q.pop();
        hd=p.second;
        Node* node=p.first;
        mp[hd].push_back(node->data);
        if(node->left){
            q.push({node->left,hd-1});
        }
          if(node->right){
            q.push({node->right,hd+1});
        }
    }
    for(auto it=mp.begin(); it !=mp.end();it++){
        for(int i=0;i<it->second.size(); i++){
            cout<<it->second[i]<<" ";
        }
        cout<<endl;
    }
    
}
//Top view of binary tree
void TopView(Node* root){
    map<int,int> mp;
    queue<pair<Node*,int>> q;
    int hd=0;
    q.push({root,hd});
    while(!q.empty()){
        auto top=q.front();
        q.pop();
        int hd=top.second;
        Node* node=top.first;
        if(mp.count(hd)==0){
            mp[hd]=node->data;
        }
        if(node->left){
            q.push({node->left,hd-1});
        }
         if(node->right){
            q.push({node->right,hd+1});
        }
    }
    for(auto i : mp){
        cout<<i.second<<" ";
    }
}
//Bottom view
void BottomView(Node* root){
    map<int,int> mp;
    queue<pair<Node*,int>> q;
    int hd=0;
    q.push({root,hd});
    while(!q.empty()){
        auto top=q.front();
        q.pop();
        int hd=top.second;
        Node* node=top.first;
        
        mp[hd]=node->data;
        
        if(node->left){
            q.push({node->left,hd-1});
        }
         if(node->right){
            q.push({node->right,hd+1});
        }
    }
    for(auto i : mp){
        cout<<i.second<<" ";
    }
}

int main()
{
     Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right =new Node(8);
    root->right->right->right = new Node(9);
    // LevelOrder(root);
    VerticalIterative(root);
    cout<<"Top view ->";
    TopView(root);
    cout<<endl;
     cout<<"Bottom view ->";
     BottomView(root);
    
    return 0;
}
