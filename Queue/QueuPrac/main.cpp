#include <iostream>

using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){}
};
ListNode* swapNodes(ListNode* head, int k) {
        if(head == NULL) return NULL;
        ListNode* new_head = new ListNode(0);
        new_head->next = head;
        ListNode* prev1 = new_head;

        for(int i=0;i<k-1;i++){
            prev1 = prev1->next;
        }
        cout<<prev1->val;
        ListNode* cur1 = prev1->next;
        ListNode* forward1 = cur1->next;
        int length =0;
        ListNode* current =head;
        while(current){
            length++;
            current  = current->next;
        }

        int diff = length - k;

        ListNode* prev2 = head;
        for(int i=0;i<diff-1;i++){
            prev2 = prev2->next;
        }
        cout<<prev2->val;
        ListNode* cur2 = prev2->next;
        ListNode* forward2 = cur2->next;

        ListNode* temp = cur1;
        prev1->next = cur2;
        cur2->next = forward1;
        prev2->next = temp;
        temp->next = forward2;
        return new_head->next;
    }
int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head = swapNodes(head, 4);
    while(head){
        cout<<head->val<<" ";
        head = head->next;
    }
}
