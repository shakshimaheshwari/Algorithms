#include <iostream>

using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int value)
{
    Node *n = new Node();
    n->data = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void printLeaf(Node *root)
{
    if(root)
    {
        printLeaf(root->left);
        if(root->left== NULL && root->right == NULL)
        {
            cout<<root->data<<"   ";
        }
        printLeaf(root->right);
    }
}
void printBoundaryRight(Node* root)
{
    if(root)
    {
        if(root->right)
        {
            printBoundaryRight(root->right);
            cout<<root->data<<"   ";
        }
        else if(root->left)
        {
            printBoundaryRight(root->left);
            cout<<root->data<<"   ";
        }
    }
}
void printBoundaryLeft(Node* root)
{
    if(root)
    {
        if(root->left)
        {
            cout<<root->data<<"  ";
            printBoundaryLeft(root->left);
        }
        else if(root->right)
        {
            cout<<root->data<<"  ";
            printBoundaryLeft(root->right);
        }
    }
}

void printBoundary(Node* root)
{
    if(root != NULL)
    {
        cout<<root->data<<"  ";
        printBoundaryLeft(root->left);
        printLeaf(root->left);
        printLeaf(root->right);
        printBoundaryRight(root->right);
    }
}
int main()
{
    Node* root         = newNode(20);
    root->left                = newNode(8);
    root->left->left          = newNode(4);
    root->left->right         = newNode(12);
    root->left->right->left   = newNode(10);
    root->left->right->right  = newNode(14);
    root->right               = newNode(22);
    root->right->right        = newNode(25);

    printBoundary(root);
    return 0;
}
