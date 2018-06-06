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

int treesidentical(Node *root, Node *root1)
{
        if(root == NULL && root1 == NULL)
            return 1;

        if(root!=NULL && root1!=NULL)
        {
            return(root->data == root1->data && treesidentical(root->left, root1->left) && treesidentical(root->right, root1->right));
        }
    return 0;
}
int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    Node *root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);

    int x = treesidentical(root, root1);

    if(x)
        cout<<"Trees are identical";
    else
        cout<<"The trees are not identical";

    return 0;
}
