#include <iostream>

using namespace std;
struct Node{
    int data;
    Node *next;
};

void insertBeginning(Node **head, int value)
{
        Node *n = new Node();
        n->data = value;
        n->next = *head;
        *head = n;
}

void deleteBeginning(Node *head)
{
    if (head == NULL) return;
    else{
        Node *temp = head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
}
int main()
{
    Node* head = NULL;
    insertBeginning(&head, 2);
    insertBeginning(&head, 3);
    insertBeginning(&head, 4);
    insertBeginning(&head, 5);
    deleteBeginning(head);
    return 0;
}
