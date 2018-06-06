#include <iostream>

using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};

void increment(Node* root, int diff)
{
    if(root->left != NULL)
    {
        root->left->data = root->left->data +diff;
        increment(root->left, diff);
    }
    else if(root->right != NULL)
    {
        root->right->data = root->right->data+diff;
        increment(root->right, diff);
    }
}
void convertTree(Node *root)
{
    int left_data =0, right_data =0, diff;

    if(root == NULL || (root->left == NULL && root->right == NULL ))
        return;
    else{

        convertTree(root->left);
        convertTree(root->right);


        if(root->left != NULL)
            left_data = root->left->data;

        if(root->right != NULL)
            right_data = root->right->data;

        diff = left_data+right_data - root->data;

        if(diff > 0)
            root->data = root->data+diff;
        if(diff < 0)
            increment(root, -diff);
    }
}
Node* newNode(int value)
{
    Node* n = new Node();
    n->data = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}
void printInorder(Node *root)
{
    if(root == NULL)
        return;

    else{
        printInorder(root->left);
        cout<<root->data<<"   ";
        printInorder(root->right);
    }
}
int main()
{
    Node *root = newNode(50);
  root->left        = newNode(7);
  root->right       = newNode(2);
  root->left->left  = newNode(3);
  root->left->right = newNode(5);
  root->right->left  = newNode(1);
  root->right->right = newNode(30);
  cout<<" Inorder traversal before conversion";
  printInorder(root);
  convertTree(root);
  cout<<"Inorder traversal after conversion";
  printInorder(root);
    return 0;
}
