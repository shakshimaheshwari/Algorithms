#include <iostream>

using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};
Node* newNode(int value)
{
    Node* n = new Node();
    n->data =value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void doubleTree(Node* root)
{
    Node* oldLeft;
    if(root == NULL) return;

    doubleTree(root->left);
    doubleTree(root->right);

    oldLeft = root->left;
    root->left = newNode(root->data);
    root->left->left = oldLeft;
}

void inOrder(Node *root)
{
    if(root == NULL)
        return;
    else{
        inOrder(root->left);
        cout<<root->data<<"   ";
        inOrder(root->right);
    }
}
int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    cout<<"Printing before conversion::";
    inOrder(root);
    doubleTree(root);
    cout<<"\nPrinting after conversion::";
    inOrder(root);
    return 0;
}
