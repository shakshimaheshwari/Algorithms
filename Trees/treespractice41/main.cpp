#include <iostream>
#include <queue>
#include <stack>

using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int value)
{
    Node *n = new Node();
    n->data = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}
void reverselevelorder(Node* root)
{
    queue<Node*>q;
    stack<Node*>s;

    q.push(root);
    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        s.push(temp);

        if(temp->right)
            q.push(temp->right);
        if(temp->left)
            q.push(temp->left);

    }

    while(!s.empty())
    {
        Node *temp = s.top();
        cout<<temp->data<<"   ";
        s.pop();

    }
}
int main()
{
    Node* root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->right->left  = newNode(6);
    root->right->right = newNode(7);

    reverselevelorder(root);
    return 0;
}
