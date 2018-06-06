#include <iostream>

using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
};

Node* newNode(int value){
    Node *n = new Node();
    n->data = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}
int height(Node *root)
{
    if(root == NULL)
        return 0;

    else
        return(1+ max(height(root->left), height(root->right)));
}
int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    int h = height(root);
    cout<<"The height of the tree is ::"<<h;
    return 0;
}
