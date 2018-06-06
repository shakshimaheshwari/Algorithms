#include <iostream>

using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int value)
{
    Node *n = new Node();
    n->data  = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}
int diameter(Node *root, int *height)
{
        int rh =0;
        int lh =0;
        int ldiameter =0;
        int rdiameter=0;
        if(root == NULL)
        {
            *height =0;
            return 0;
        }

        ldiameter = diameter(root->left, &lh);
        rdiameter = diameter(root->right, &rh);

        *height = max(rh, lh)+1;
        return max(1+rh+lh, max(ldiameter, rdiameter));
}
int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    int height =0;
    int d = diameter(root, &height);
    cout<<"The diameter of the tree is::"<<d;
    return 0;
}
