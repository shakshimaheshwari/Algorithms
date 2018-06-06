#include <iostream>
#include <stdlib.h>

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
    n->right =NULL;
    return n;
}
int height (Node *root)
{
    if(root == NULL)
        return 0;

    else return(1+ max(height(root->left), height(root->right)));
}
int isBalancedTree(Node *root)
{
    int lh, rh;
    if(root == NULL)
        return 1;

    lh = height(root->left);
    rh = height(root->right);

    if(abs(lh-rh)<=1 && isBalancedTree(root->left) && isBalancedTree(root->right))
        return 1;

    return 0;

}
int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(8);

    if(isBalancedTree(root))
        cout<<"Height balanced tree";
    else
        cout<<"Not a height balanced tree";
    return 0;
}
