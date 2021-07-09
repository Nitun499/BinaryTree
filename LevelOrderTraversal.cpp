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
    Node *root = NULL;
    root = Insert(root, 15);
    root = Insert(root, 16);
    root = Insert(root, 12);
    root = Insert(root, 8);
    root = Insert(root, 22);
    root = Insert(root, 11);
    LevelOrder(root);
    return 0;
}
