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
    n->next =NULL;
    return n;
}
Node* deleteMid(Node* head)
{
    if(head == NULL)
        return NULL;
    if(head->next == NULL)
    {
        delete head;
        return NULL;
    }

    Node* slow_ptr = head;
    Node* fast_ptr = head;

    Node* prev;

    while(fast_ptr != NULL)
    {
        fast_ptr = fast_ptr->next->next;
        prev = slow_ptr;
        slow_ptr = slow_ptr->next;
    }

    prev->next = slow_ptr->next;
    delete slow_ptr;

    return head;
}

void printList(Node* head)
{
    while(head!= NULL)
    {
        cout<<head->data<<"   ";
        head = head->next;
    }
}
int main()
{
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);

    cout << "Gven Linked List\n";
    printList(head);

    head = deleteMid(head);

    cout << "Linked List after deletion of middle\n";
    printList(head);
    return 0;
}
