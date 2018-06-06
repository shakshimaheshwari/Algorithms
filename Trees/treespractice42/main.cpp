#include <iostream>

using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};

struct linklist{
    int data;
    linklist* next;
};

bool isIsomorphic(Node* n1, Node* n2)
{
    if(n1 == NULL && n2 == NULL)
        return true;

    if(n1 == NULL || n2 == NULL)
        return false;

    return ((isIsomorphic(n1->left, n2->left) && isIsomorphic(n1->right, n2->right))||
    (isIsomorphic(n1->left, n2->right) && isIsomorphic(n1->right, n2->left)));
}

Node* newNode(int value)
{
    Node *n = new Node();
    n->data = value;
    n->left = NULL;
    n->right =NULL;
    return n;
}
int main()
{
    Node* n1 = newNode(1);
    n1->left        = newNode(2);
    n1->right       = newNode(3);
    n1->left->left  = newNode(4);
    n1->left->right = newNode(5);
    n1->right->left  = newNode(6);
    n1->left->right->left = newNode(7);
    n1->left->right->right = newNode(8);

    Node *n2 = newNode(1);
    n2->left         = newNode(3);
    n2->right        = newNode(2);
    n2->right->left   = newNode(4);
    n2->right->right   = newNode(5);
    n2->left->right   = newNode(6);
    n2->right->right->left = newNode(8);
    n2->right->right->right = newNode(7);

    if(isIsomorphic(n1,n2) == true)
    {
        cout<<"The trees are isomorphic to each other";
    }
    else{
        cout<<"Non isomorphic";
    }
    return 0;
}
