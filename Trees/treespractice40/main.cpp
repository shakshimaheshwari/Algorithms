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
    n->data  = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}
void morrisTraversalPreorder(Node* root)
{
    while(root)
    {
        if(root->left == NULL)
        {
            cout<<root->data<<"  ";
            root= root->right;
        }
        else
        {
            Node* current = root->left;
            while(current->right && current->right != root)
                current = current->right;

            if(current->right == root)
            {
                current->right = NULL;
                root= root->right;
            }

            else
            {
                cout<<root->data<<"   ";
                current->right = root;
                root = root->left;
            }
        }
    }
}
void preorder(Node* root)
{
    if(root)
    {
        cout<<root->data<<"   ";
        preorder(root->left);
        preorder(root->right);
    }
}
int main()
{
    Node* root =newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    root->left->left = newNode(4);
    root->left->right = newNode(5);

    root->right->left = newNode(6);
    root->right->right = newNode(7);

    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);

    root->left->right->left = newNode(10);
    root->left->right->right = newNode(11);

    morrisTraversalPreorder(root);

    cout<<"The tree traversal is::";
    preorder(root);
    return 0;
}
