#include <iostream>

using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* newNode(int value)
{
    Node* n = new Node();
    n->data = value;
    n->next = NULL;
    return n;
}
void sortList(Node** head)
{
    Node* prev = (*head);
    Node* curr = (*head)->next;

    while(curr!=NULL)
    {
        if(curr->data < prev->data)
        {
            prev->next = curr->next;
            curr->next = (*head);
            (*head) = curr;

            curr = prev;
        }

        else
            prev = curr;

        curr = curr->next;
    }
}
void printList(Node* root)
{
    while(root!=NULL)
    {
        cout<<root->data<<"  ";
        root = root->next;

    }
}
int main()
{
    Node *root = newNode(0);
    root->next = newNode(1);
    root->next->next = newNode(-2);
    root->next->next->next = newNode(3);
    root->next->next->next->next = newNode(4);
    root->next->next->next->next->next = newNode(5);
    root->next->next->next->next->next->next = newNode(-5);

    cout<<"Original list::";
    printList(root);
    sortList(&root);
    cout<<"Modified department::";
    printList(root);
    return 0;
}
