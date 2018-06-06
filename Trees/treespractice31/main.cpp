#include <iostream>

using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node* next;
};

Node* newNode(int value)
{
    Node *n = new Node();
    n->data =value;
    n->left = NULL;
    n->right = NULL;
    n->next = NULL;
    return n;
}

void populateNext(Node* root)
{
    static Node* next = NULL;

    if(root)
    {
        populateNext(root->right);
        root->next = next;
        next = root;
        populateNext(root->left);
    }
}
int main()
{
    Node *root = newNode(10);
    root->left        = newNode(8);
    root->right       = newNode(12);
    root->left->left  = newNode(3);

    // Populates nextRight pointer in all nodes
    populateNext(root);

    // Let us see the populated values
    struct Node *ptr = root->left->left;
    while(ptr)
    {
        // -1 is printed if there is no successor
        cout<<"Next of " << ptr->data<<" is:: "<<(ptr->next? ptr->next->data: -1)<<endl;
        ptr = ptr->next;
    }
    return 0;
}
