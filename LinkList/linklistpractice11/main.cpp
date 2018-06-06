#include <iostream>
#include <string>

using namespace std;
struct Node{
    string data;
    Node* next;
};

Node* newNode(string value)
{
    Node *n = new Node();
    n->data = value;
    n->next = NULL;
    return n;
}
bool isPalindromeUtil(string str)
{
    for(int i=0, j= str.length()-1; i<str.length()/2;i++, j--)
    {
        if(str[i] != str[j])
            return false;
    }
    return true;
}
bool isPalindrome(Node *head)
{
    Node *temp = head;
    string str = "";
    while(temp != NULL)
    {
        str+=temp->data;
        temp = temp->next;
    }

    return isPalindromeUtil(str);
}
int main()
{
    Node *head = newNode("a");
    head->next = newNode("bc");
    head->next->next = newNode("d");
    head->next->next->next = newNode("dcb");
    head->next->next->next->next = newNode("a");
    isPalindrome(head)? cout<<"true" : cout<<"false";
    return 0;
}
