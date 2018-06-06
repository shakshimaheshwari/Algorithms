#include <iostream>
#include <stack>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
};

Node* newNode(int value)
{
    Node *n = new Node();
    n->data = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void spirallevelordertraversal(Node *root)
{
    if(root == NULL) return;
    stack<Node*>s1;
    stack<Node*>s2;

    s1.push(root);

    while(!s1.empty() || !s2.empty())
    {
       while(!s1.empty()){
        Node *temp = s1.top();
        s1.pop();
        cout<<temp->data <<"   ";

        if(temp->right != NULL)
            s2.push(temp->right);
        if(temp->left != NULL)
            s2.push(temp->left);

       }

       while(!s2.empty()){
        Node *temp = s2.top();
        s2.pop();
        cout<<temp->data<<"   ";

        if(temp->left != NULL)
            s1.push(temp->left);
        if(temp->right != NULL)
            s1.push(temp->right);
       }


    }

}
int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left  = newNode(7);
    root->left->right = newNode(6);
    root->right->left  = newNode(5);
    root->right->right = newNode(4);

    spirallevelordertraversal(root);
    return 0;
}
