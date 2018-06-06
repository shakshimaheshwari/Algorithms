#include <iostream>

using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};
int height(Node *root)
{
    if(root == NULL)
        return 0;
    else return(1+ max(height(root->left), height(root->right)));
}
int getWidth(Node *root, int level)
{
    if(root == NULL)
        return 0;
    if(level == 1)
        return 1;

    else if(level >1)
        return (getWidth(root->left, level-1)+ getWidth(root->right, level-1));
}
int getMaxWidth(Node *root)
{
    int maxWidth =0;
    int width;
    int h = height(root);
    for(int i=1;i<=h;i++)
    {
        width = getWidth(root, i);

        if(maxWidth < width)
            maxWidth = width;
    }

    return maxWidth;
}
Node* newNode(int value)
{
    Node *n = new Node();
    n->data = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}
int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(8);
    root->right->right->left  = newNode(6);
    root->right->right->right  = newNode(7);

    int x = getMaxWidth(root);
    cout<<"The maximum width is::"<<x;
    return 0;
}
