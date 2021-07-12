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
//Function for traversal (LevelOrder or Breadth-first traversal)
void LevelOrder(Node *root)
{
    if (root == NULL)
    {
        cout << "List is Empty" << endl;
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *current = q.front();
        cout << current->data << " ";
        if (current->left != NULL)
            q.push(current->left);
        if (current->right != NULL)
            q.push(current->right);
        q.pop();
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
