#include <iostream>

using namespace std;
struct Node{
    int data;
    Node* next;
};

Node* newNode(int value)
{
    Node* n = new Node();
    n->data= value;
    n->next = NULL;
    return n;
}

void mergeList(Node* head1, Node* &head2)
{
    while(head1 && head2)
    {
        if(head1->data > head2->data)
        {
            swap(head1->data, head2->data);
            Node* temp = head2;

            if(head2->next && head2->data > head2->next->data)
            {
                head2 = head2->next;
                Node* ptr = head2;
                Node* prev = NULL;
                while(ptr!= NULL && ptr->data < temp->data)
                {
                    prev = ptr;
                    ptr = ptr->next;
                }

                prev->next = temp;
                temp->next = ptr;
            }
        }

        head1 = head1->next;
    }
}
void printList(Node* head1)
{
    while(head1 != NULL)
    {
        cout<<head1->data<<"  ";
        head1 = head1->next;
    }
    cout<<endl;
}
int main()
{
    Node *root1 = newNode(10);
    root1->next = newNode(8);
    root1->next->next = newNode(7);
    root1->next->next->next = newNode(4);
    root1->next->next->next->next = newNode(2);

    Node *root2 = newNode(12);
    root2->next = newNode(3);
    root2->next->next = newNode(1);

    mergeList(root1,root2);

    printList(root1);
    printList(root2);
    return 0;
}
