#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
};
ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL)
        return head;
        if(m == n)return head;
        ListNode *c = head;
        int length =1;
        while(c!= NULL)
        {

            if(length == m)
            {
                ListNode *forward = c->next;
                ListNode *current = c;
                ListNode *prev = c;
                ListNode *track = c;
                while(m!=n && forward)
                {
                    current = forward;
                    forward = forward->next;
                    current->next = prev;
                    prev = current;
                    cout<<prev->val;
                    m++;
                }
                track->next = forward;
                if(forward == NULL){
                head = prev;
                }
                else
                    head->next = prev;
                break;

            }
            else{
            length++;
            c= c->next;
            }
        }
        return head;

    }

ListNode* newNode(int val)
{
    ListNode *n = new ListNode();
    n->val = val;
    n->next = NULL;
    return n;
}

void print(ListNode* n)
{

    while(n!= NULL)
    {
        cout<<n->val<<"   ";
        n = n->next;
    }
}
int main()
{
    int m,x;
    cin>>m>>x;
    ListNode *n = newNode(1);
    n->next = newNode(2);
    n->next->next = newNode(3);
    /*n->next->next->next = newNode(4);
    n->next->next->next->next = newNode(5);*/
    n  = reverseBetween(n,m,x);
    print(n);
    return 0;
}

