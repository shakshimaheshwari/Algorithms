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

void postOrder(Node *root)
{
    if(root == NULL)
        return;
    else{
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<"  ";
    }
}

void postOrderWithoutRecursion(Node *root)
{
    if(root == NULL)
        return;

    stack<Node*>s;
    s.push(root);
    Node *prev = NULL;
    while(!s.empty()){
        Node *curr = s.top();

        if(!prev || prev->left == curr || prev->right == curr)
        {
            if(curr->left)
                s.push(curr->left);
            else if(curr->right)
                s.push(curr->right);
        }
        else if(curr->left == prev)
        {
            if(curr->right)
                s.push(curr->right);
        }
        else {
            cout<<curr->data<< " ";
             s.pop();
        }
        prev = curr;
    }

}
int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout<<"The postorder traversal is::";
    postOrder(root);
    postOrderWithoutRecursion(root);
    return 0;
}
