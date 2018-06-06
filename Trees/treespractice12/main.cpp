#include <iostream>
#include <queue>

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

void levelordertraversal(Node *root)
{
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            Node *temp = q.front();
            q.pop();

            cout<<temp->data<< "   ";
            if(temp->left != NULL)
                q.push(temp->left);
            if(temp->right != NULL)
                q.push(temp->right);
        }
}
int main()
{
    Node *root= newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    levelordertraversal(root);
    return 0;
}
