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
void MorrisTraversal(Node *root)
{

    Node *current, *pre;
    if(root == NULL)
        return;

    current = root;

    while(current != NULL)
    {
        if(current->left == NULL)
        {
            cout<<current->data<<"  ";
            current = current->right;
        }
        else{
            pre = current->left;
            while(pre->right!= NULL && pre->right != current)
                pre = pre->right;

            if(pre->right == NULL)
            {
                pre->right = current;
                current = current->left;
            }
            else
            {
                pre->right =NULL;
                cout<< current->data<<"   ";
                current = current->right;
            }
        }

    }
}

int main()
{
    Node *root  = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    MorrisTraversal(root);
    return 0;
}
