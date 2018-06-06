#include <iostream>
#include <queue>

using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
};

Node* newNode(int value)
{
    Node *n = new Node();
    n->data  = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void BSTConverttoSortedLL(Node* root, Node** head)
{
    if(root == NULL)
        return;
    BSTConverttoSortedLL(root->right, head);
    root->right = *head;
    if(*head != NULL)
        (*head)->left = NULL;

    *head = root;
    BSTConverttoSortedLL(root->left, head);

}

void sortedLinkListToMinHeap(Node*& root, Node* head)
{
    if(head == NULL)
        return;
    queue<Node*> q;
    root = head;
    head = head->right;
    root->right = NULL;

    q.push(root)
    while(head)
    {
        Node *parent = q.front();
        q.pop();

        Node *leftchild = head;
        head = head->right;
        leftchild->right = NULL;
        q.push(leftchild);

        parent->left = leftchild;
        if(head)
        {
            Node *rightchild = head;
            head = head->right;
            rightchild->right =NULL;
            q.push(rightchild);

            parent->right = rightchild;
        }
    }
}
Node* BSTToMinHeap(Node*& root)
{
    Node *head = NULL;
    BSTCoverttoSortedLL(root, &head);


}
int main()
{
    Node* root = newNode(8);
    root->left = newNode(4);
    root->right = newNode(12);
    root->right->left = newNode(10);
    root->right->right = newNode(14);
    root->left->left = newNode(2);
    root->left->right = newNode(6);

    BSTToMinHeap(root);
    return 0;
}
