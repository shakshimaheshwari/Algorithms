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

void printKDistant(Node *root, int k)
{
    if(root == NULL)
        return;
    if(k == 0 )
    {
        cout<< root->data<< "   ";
    }

    else{
        printKDistant(root->left, k-1);
        printKDistant(root->right, k-1);
    }

}
int main()
{
    int k;
    Node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(8);

    cout<<"Enter the value of k::";
    cin>>k;
    printKDistant(root, k);



    return 0;
}
