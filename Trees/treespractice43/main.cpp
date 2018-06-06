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
    n->right = NULL;
    return n;

}
int iterativeheight(Node* root)
{
    if(root == NULL)
        return 0;

    queue<Node*>q;

    q.push(root);
    int height =0;

    while(1)
    {
        int nodecount = q.size();
        if(nodecount == 0)
            return height;
        height++;
        while(nodecount>0)
        {
            Node *temp = q.front();
            q.pop();
            if(temp->left != NULL)
                q.push(temp->left);
            if(temp->right != NULL)
                q.push(temp->right);

            nodecount--;
        }
    }
}
int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    int h = iterativeheight(root);
    cout<<"The iterative height of the binary tree is::"<<h;
    return 0;
}
