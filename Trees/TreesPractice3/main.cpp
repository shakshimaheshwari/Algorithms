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
    n->left =NULL;
    n->right = NULL;
    return n;
}

void inOrderTraversal(Node* root)
{
    if(root == NULL)
        return;

    else{
        inOrderTraversal(root->left);
        cout<<root->data<<"   ";
        inOrderTraversal(root->right);
    }
}

void inOrderTraversalWithoutRecursion(Node *root)
{
    stack<Node*>s;
    bool done =0;
    Node *current = root;
    while(!done)
    {
        if(current!=NULL){
        s.push(current);
        current = current->left;
        }
        else{
            if(!s.empty()){
            current = s.top();
            s.pop();
            cout<<current->data<<"  ";
            current= current->right;
        }
        else
            done =1;
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

    inOrderTraversal(root);
    inOrderTraversalWithoutRecursion(root);
    return 0;
}
