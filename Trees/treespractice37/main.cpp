#include <iostream>
#include <queue>

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
    n->right =NULL;
    return n;
}

bool isCompleteBT(Node* root)
{
    queue<Node*>q;
    bool flag = false;

    q.push(root);
    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if(temp->left != NULL)
        {
            if(flag == true)
                return false;

            q.push(temp->left);
        }
        else
            flag = true;

        if(temp->right != NULL)
        {
            if(flag == true)
                return false;

            q.push(temp->right);
        }
        else
            flag = true;
    }

   return true;
}
int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
    if(isCompleteBT(root) == true)
    {
        cout<<"Its a complete binary tree";
    }
    else{
        cout<<"Not a complete binary tree";
    }
    return 0;
}
