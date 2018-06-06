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

bool printAncestors(Node *root, int target)
{
    if(root == NULL)
        return false;

    if(root->data  == target)
        return true;

    if(printAncestors(root->left, target)|| printAncestors(root->right, target))
    {
        cout<<root->data<<"   ";
        return true;
    }

    return false;
}
int main()
{
    int target;
    Node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left  = newNode(7);
    cout<<"Enter the target for which you want to find out the ancestors::";
    cin>>target;
    printAncestors(root,target);
    return 0;
}
