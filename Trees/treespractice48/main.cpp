#include <iostream>

using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int value)
{
    Node* n =new Node();
    n->data = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}
Node* binary2linklistUtil(Node* root)
{
    if(root == NULL)
        return root;

    if(root->left != NULL)
    {
        Node *left = binary2linklistUtil(root->left);

        while(left->right != NULL)
            left = left->right;

        left->right = root;
        root->left = left;
    }

    if(root->right != NULL)
    {
        Node *right = binary2linklistUtil(root->right);
        while(right->left != NULL)
            right = right->left;

        right->left = root;
        root->right = right;
    }

    return root;
}

Node* binary2linklist(Node* root)
{
    if(root == NULL)
        return NULL;

   root =  binary2linklistUtil(root);

   while(root->left != NULL)
    root= root->left;

   return root;
}

void printList(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"   ";
        head = head->right;
    }
}
int main()
{
    Node* root = newNode(10);
    root->left        = newNode(12);
    root->right       = newNode(15);
    root->left->left  = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);

    Node *head = binary2linklist(root);

    printList(head);
    return 0;
}
