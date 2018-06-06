#include <iostream>

using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};
Node *newNode(int value)
{
    Node *n = new Node();
    n->data = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}
int sum(Node *root)
{
    if(root == NULL)
        return 0;
    else return(sum(root->left)+root->data + sum(root->right));
}
int isSumTree(Node *root)
{
    int ls, rs;

    if(root == NULL || (root->left==NULL && root->right ==NULL))
        return 1;

    ls = sum(root->left);
    rs = sum(root->right);

    if(root->data - ls- rs == 0 && isSumTree(root->left)&& isSumTree(root->right))
        return 1;

    return 0;
}
int main()
{

    Node *root  = newNode(26);
    root->left         = newNode(10);
    root->right        = newNode(3);
    root->left->left   = newNode(4);
    root->left->right  = newNode(6);
    root->right->right = newNode(3);

    if(isSumTree(root))
        cout<<"Yes a sum tree";
    else
        cout<<"No";
    return 0;
}
