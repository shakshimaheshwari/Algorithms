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

int toSumTree(Node* root)
{
    if(root == NULL)
        return 0;

    int node_data_old = root->data;
    root->data = toSumTree(root->left) + toSumTree(root->right);
    return root->data+node_data_old;
}
void inOrder(Node* root)
{
    if(root == NULL) return;
    else{
        inOrder(root->left);
        cout<<root->data<<"   ";
        inOrder(root->right);
    }
}
int main()
{
    Node* root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(6);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);
    root->right->left = newNode(7);
    root->right->right = newNode(5);

    cout<<"The tree before conversion::";
    inOrder(root);
    toSumTree(root);
    cout<<"The tree after conversion::";
    inOrder(root);
    return 0;
}
