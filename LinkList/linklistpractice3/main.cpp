#include <iostream>
#include <stdlib.h>

using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* newNode(int value)
{
    Node *n = new Node();
    n->data= value;
    n->next = NULL;
    return n;
}
int getLength(Node* head)
{
    int countofnode =0;
    while(head!= NULL)
    {
        countofnode++;
        head = head->next;
    }
    return countofnode;
}

Node* subtractLinkedListHelper(Node* lNode, Node*sNode, bool &borrow)
{

    if(lNode == NULL && sNode == NULL && borrow == 0)
        return NULL;

    Node *previous = subtractLinkedListHelper(lNode? lNode->next:NULL, sNode? sNode->next:NULL, borrow);
    int d1 = lNode->data;
    int d2 = sNode->data;
    int sub =0;
    if(borrow)
    {
        d1--;
        borrow = false;
    }

    if(d1 <d2)
    {
        borrow = true;
        d1 = d1+10;
    }
    sub = d1-d2;
    Node* current = newNode(sub);
    current->next = previous;
    return current;

}

Node* padZeroes(Node* sNode, int diff)
{
    if(sNode == NULL)
        return NULL;

    Node *zNode = newNode(0);
    diff--;
    Node *temp = zNode;
    while(diff--)
    {
        temp->next = newNode(0);
        temp = temp->next;
    }
    temp->next = sNode;
    return zNode;
}
Node* subtractLinkedList(Node*head1, Node*head2)
{
    if(head1 == NULL && head2 == NULL)
        return NULL;

    Node *head1dummy = head1;
    while(head1dummy!=NULL)
    {
        cout<<head1dummy->data;
        head1dummy = head1dummy->next;
    }
    Node* current1 = head1;
    Node* current2 = head2;
    int l1 = getLength(head1);
    int l2 = getLength(head2);
    Node* lNode = NULL;
    Node* sNode = NULL;

    if(l1!= l2)
    {
        lNode = (l1 > l2)? current1: current2;
        sNode = (l1 > l2)? current2: current1;
        sNode = padZeroes(sNode, abs(l1-l2));
    }

    else{
        while(current1 && current2)
        {
            if(current1->data != current2->data)
            {
                lNode = (current1->data > current2->data)? head1: head2;
                sNode = (current1->data > current2->data)? head2 : head1;
            }

            current1 = current1->next;
            current2 = current2->next;
        }
    }

    Node *sNodedummy = sNode;
    while(sNodedummy!= NULL)
    {
        cout<<sNodedummy->data<<"   ";
        sNodedummy = sNodedummy->next;
    }

    Node *lNodedummy = lNode;
    while(lNodedummy != NULL)
    {
        cout<<lNodedummy->data<<"  ";
        lNodedummy = lNodedummy->next;
    }
    bool borrow =false;
    return subtractLinkedListHelper(lNode, sNode, borrow);
}


void print(Node *result)
{
    while(result!= NULL)
    {
        cout<<result->data<<"   ";
        result = result->next;
    }
}
int main()
{
    Node* head1 = newNode(1);
    head1->next = newNode(0);
    head1->next->next = newNode(0);

    Node* head2 = newNode(1);

    Node* result = subtractLinkedList(head1, head2);

    print(result);
    return 0;
}
