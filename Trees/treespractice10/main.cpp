#include <iostream>

using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
};

Node* newNode(int value)
{
    Node *n = new Node();
    n->data = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

Node* lca(Node *root, int n1, int n2)
{
    if(root == NULL)return NULL;
    if(root->data > n1 && root->data >n2)
        return lca(root->left, n1, n2);

    if(root->data <n1 && root->data < n2)
        return lca(root->right, n1, n2);

    return root;
}
int main()
{
    Node *root        = newNode(20);
    root->left               = newNode(8);
    root->right              = newNode(22);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->right->left  = newNode(10);
    root->left->right->right = newNode(14);
    int n1=10, n2 =14;
    Node *temp =lca(root,n1,n2);
    cout<<"The ancestor of "<<n1<<" and "<<n2<< "is"<<temp->data;
    return 0;
}
