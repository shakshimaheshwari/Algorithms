/* Program to remove duplicates in an unsorted
linked list */
#include<bits/stdc++.h>
using namespace std;

/* A linked list node */
struct Node
{
	int data;
	struct Node *next;
};

// Utility function to create a new Node
struct Node *newNode(int data)
{
Node *temp = new Node;
temp->data = data;
temp->next = NULL;
return temp;
}

/* Function to remove duplicates from a
unsorted linked list */
void removeDuplicates(Node* head){
    if(head == NULL) return;
    if(head->next == NULL) return;
    vector<bool>visited(256,false);
    Node* current = head;
    Node* prev = current;
    while(head->next!=NULL){
        while(head->next->next && visited[head->data] == true){
            if(head->next)swap(head->data, head->next->data);
            head->next = head->next->next;
        }
        visited[head->data] = true;
        prev = head;
        head = head->next;

    }
    if(head->next == NULL && visited[head->data] == true){
        cout<<"Entry in last node";
        prev->next = NULL;
    }
}

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
}

/* Druver program to test above function */
int main()
{
	/* The constructed linked list is:
	10->12->11->11->12->11->10*/
	struct Node *start = newNode(10);
	start->next = newNode(12);
	start->next->next = newNode(11);
	start->next->next->next = newNode(11);
	start->next->next->next->next = newNode(12);
	start->next->next->next->next->next =
									newNode(11);
	start->next->next->next->next->next->next =
									newNode(10);

	printf("Linked list before removing duplicates ");
	printList(start);

	removeDuplicates(start);

	printf("\nLinked list after removing duplicates ");
	printList(start);

	return 0;
}
