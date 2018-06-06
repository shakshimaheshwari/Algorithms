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

void printlist(Node* head)
{
    while(head != NULL)
    {
        cout<<head->data<<"   ";
        head= head->next;
    }
}
Node* sortedMerge(Node *a, Node *b)
{
    Node* result = NULL;
    if(a == NULL)
        return b;
    if(b == NULL)
        return a;

    if(a->data <= b->data)
    {
        result = a;
        result->next = sortedMerge(a->next, b);
    }
    else{
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    return result;
}
Node* mergeKLists(Node* arr[], int last)
{
    while(last!=0)
    {
        int i=0, j= last;
        while(i<j)
        {
            arr[i] = sortedMerge(arr[i], arr[j]);
            i++;
            j--;

            if(i>=j)
                last =j;
        }
    }

    return arr[0];
}
int main()
{
    int k = 4; // Number of linked lists
    int n = 4; // Number of elements in each list

    // an array of pointers storing the head nodes
    // of the linked lists
    Node* arr[k];

    arr[0] = newNode(1);
    arr[0]->next = newNode(6);
    arr[0]->next->next = newNode(9);
    arr[0]->next->next->next = newNode(12);

    arr[1] = newNode(2);
    arr[1]->next = newNode(5);
    arr[1]->next->next = newNode(8);
    arr[1]->next->next->next = newNode(11);

    arr[2] = newNode(0);
    arr[2]->next = newNode(3);
    arr[2]->next->next = newNode(7);
    arr[2]->next->next->next = newNode(10);

    arr[3] = newNode(14);
    arr[3]->next = newNode(16);
    arr[3]->next->next = newNode(18);
    arr[3]->next->next->next = newNode(20);

    // Merge all lists
    Node* head = mergeKLists(arr, k - 1);

    printlist(head);
    return 0;
}
