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
//Function for left view iteratively using Level Order Traversal
void LeftViewIterative(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        //size of queue indicates number of nodes on current level
        //and first node or u can say if value of i =1 then that will be the left most node on current level
        int n=q.size();
        Node* curr=NULL;
        for(int i=1;i<=n;i++){
            curr=q.front();
            q.pop();
            if(i==1){
                cout<<curr->data<<" ";
            }
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
    }
}
//Recursive approach TC->O(n) ,SC ->O(1)
void LeftView(Node* root,int level,int &maxlevel){
    if(root==NULL){
        return;
    }
    if(maxlevel<level){
        cout<<root->data<<" ";
        maxlevel=level;
    }
    LeftView(root->left,level+1,maxlevel);
    LeftView(root->right,level+1,maxlevel);
}

// Node* GetNewNode(int data){
//     Node* newNode=new Node(data);
//     return newNode;
// }
// Node* Insert(Node*root,int data){
//     if(root==NULL){
//         root=GetNewNode(data);
//     }
//     else if(data<=root->data){
//         root->left=Insert(root->left,data);
//     }
//     else{
//         root->right=Insert(root->right,data);
//     }
//     return root;
    
// }



int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
   
    InorderIterative(root);
    cout<<endl;
    cout<<"Left view of binary tree ->";
    int maxlev=0;
    LeftView(root,1,maxlev);
    cout<<endl;
    cout<<"Left view using iterative methode->";
    LeftViewIterative(root);
    return 0;
}
