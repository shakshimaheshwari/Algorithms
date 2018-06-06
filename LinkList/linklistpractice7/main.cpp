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

bool isCircular(Node*head)
{
    if(head == NULL)
        return true;

    Node *current = head->next;
    while(current!= NULL && current!=head)
        current = current->next;

    return(head == current);
}
int main()
{
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);

    isCircular(head)? cout << "Yes\n" :
                      cout << "No\n" ;

    head->next->next->next->next = head;

    isCircular(head)? cout << "Yes\n" :
                      cout << "No\n" ;
    return 0;
}
