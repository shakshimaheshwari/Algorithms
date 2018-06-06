#include <iostream>

using namespace std;
struct Node{
    int data;
    Node* small;
    Node* large;
};

Node* newNode(int value)
{
    Node *n = new Node();
    n->data = value;
    n->small = NULL;
    n->large = NULL;
    return n;
}
void join(Node *a, Node *b)
{
    a->large = b;
    b->small = a;
}
Node* append(Node* a, Node* b)
{
    Node *aLast, *bLast;
    if(a == NULL) return b;
    if(b == NULL) return a;

    aLast = a->small;
    bLast = b->small;

    join(aLast, b);
    join(bLast, a);

    return (a);
}

Node* treeToList(Node *root)
{
    Node *aList, *bList;
    if(root == NULL)
        return NULL;

    aList= treeToList(root->small);
    bList = treeToList(root->large);

    root->small = root;
    root->large = root;

    aList = append(aList, root);
    aList = append(aList,bList);

    return aList;


}

void printList(Node* head)
{
    Node * current = head;

    while(current!= NULL)
    {
        cout<< current->data<<"  ";
        current = current->large;
        if(current == head)break;
    }
}
int main()
{
    Node *root = newNode(4);
    root->small = newNode(2);
    root->large = newNode(5);
    root->small->small = newNode(1);
    root->small->large  = newNode(3);

    Node *head = treeToList(root);

    printList(head);
    return 0;
}
