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
    n->right =NULL;
    return n;
}

void preOrder(Node* root)
{
    if(root == NULL)
        return;
    else{
        cout<<root->data;
        preOrder(root->left);
        preOrder(root->right);
    }
}
void preOrderWithoutRecursion(Node* root)
{
    if(root == NULL)
        return;

    else{
        stack<Node *> s;
        s.push(root);
        while(!s.empty())
        {
            Node *tmp = s.top();
            s.pop();
            cout<<tmp->data;

            if(tmp->right != NULL)
            {
                s.push(tmp->right);
            }
            if(tmp->left != NULL)
            {
                s.push(tmp->left);
            }
        }
    }
}
int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout<<"The preorder traversal is::";
    preOrder(root);
    cout<<" The preorder traversal without recursion is::";
    preOrderWithoutRecursion(root);
    return 0;
}
