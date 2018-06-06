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

int decimalValue(Node* head)
{
    int res =0;
    while(head!=NULL)
    {
        res = res*2 + head->data;
        head= head->next;
    }
    return res;
}
int main()
{
    struct Node* head = newNode(1);
    head->next = newNode(0);
    head->next->next = newNode(1);
    head->next->next->next = newNode(1);

    cout << "Decimal value is "
         << decimalValue(head);
    return 0;
}
