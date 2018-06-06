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


int countLeafNodes(Node *root)
{
    if(root == NULL)return 0;
    if (root->left == NULL && root->right == NULL) return 1;

    else return(countLeafNodes(root->left)+ countLeafNodes(root->right));
}
int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);

    int counter = countLeafNodes(root);

    cout<<"The number of leaf nodes is::"<<counter;
    return 0;
}
