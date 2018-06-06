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
void inOrder(Node *root)
{
    if(root == NULL)
        return;
    else
    {
        inOrder(root->left);
        cout<<root->data<<"   ";
        inOrder(root->right);
    }
}

void mirrorsolution(Node *root)
{
    if(root == NULL)
        return;
    else
    {
        Node *temp = new Node();
        mirrorsolution(root->left);
        mirrorsolution(root->right);
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}
int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    inOrder(root);
    mirrorsolution(root);
    inOrder(root);
    return 0;
}
