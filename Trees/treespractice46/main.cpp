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
    return n;
}

int height(Node* root)
{
    if(root == NULL)
        return 0;
    else
       return max(1+height(root->left),1+ height(root->right));
}
void printLevelOrderTraversal(Node* root, int i)
{
    if(root == NULL)
        return;
    if(i == 1)
        cout<<root->data <<"   ";
    else
    {
        printLevelOrderTraversal(root->left, i-1);
        printLevelOrderTraversal(root->right, i-1);
    }

}
void reverseOrderTraversal(Node* root)
{
    int h = height(root);
    for(int i=h;i>=1;i--)
    {
        printLevelOrderTraversal(root,i);
    }

}
int main()
{
    Node* root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    cout<<"The reverse order traversal of a tree is::";

    reverseOrderTraversal(root);
    return 0;
}
