#include <iostream>

using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};
int isFoldableUtil(Node *n1 , Node* n2)
{
    if(n1 == NULL && n2  == NULL)
        return 1;
    else if(n1 == NULL || n2 == NULL)
        return 0;

    return (isFoldableUtil(n1->left,n2->right) && isFoldableUtil(n1->right, n2->left));
}
int isFoldable(Node *root)
{
    if(root == NULL)
        return 1;

    return isFoldableUtil(root->left, root->right);
}
Node* newNode(int value)
{
    Node *n = new Node();
    n->data = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}
int main()
{
    Node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->right  = newNode(4);
  root->right->left = newNode(5);
   if(isFoldable(root))
    cout<<"Yes";
   else
    cout<<"No";
    return 0;
}
