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
    n->right =NULL;
    return n;
}
int isIdentical(Node *T, Node* S)
{
    if(T == NULL && S== NULL)
        return 1;
    if(T == NULL || S == NULL)
        return 0;

    return (T->data == S->data && isIdentical(T->left,S->left)&& isIdentical(T->right, S->right));
}

bool isSubtree(Node* T, Node* S)
{
    if(T == NULL)
        return false;

    if(S == NULL)
        return true;

    if(isIdentical(T,S))
        return true;

    return isSubtree(T->left, S)|| isSubtree(T->right, S);


}
int main()
{
    Node *T = newNode(26);
    T->right              = newNode(3);
    T->right->right       = newNode(3);
    T->left               = newNode(10);
    T->left->left         = newNode(4);
    T->left->left->right  = newNode(30);
    T->left->right        = newNode(6);

    Node *S    = newNode(10);
    S->right          = newNode(6);
    S->left           = newNode(4);
    S->left->right    = newNode(30);

    if(isSubtree(T,S))
        cout<<"S is a subtree of T";
    else
        cout<<"S is not a subtree of T";
    return 0;
}
