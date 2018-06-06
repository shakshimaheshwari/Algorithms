#include <iostream>

using namespace std;
struct Node{
    int data;
    Node* next;
};

Node* newNode(int value)
{
    Node *n = new Node();
    n->data = value;
    n->next = NULL;
    return n;
}
Node* addOne(Node* head)
{
    int carry =0;
}
int main()
{
    Node *head = newNode(1);
    head->next = newNode(9);
    head->next->next = newNode(9);
    head->next->next->next = newNode(9);

    printf("List is ");
    printList(head);
    head = addOne(head);
    return 0;
}
