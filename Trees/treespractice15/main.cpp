#include <iostream>

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
int isSumProperty(Node *root)
{
    int left_data =0, right_data =0;
    if(root == NULL || (root->left == NULL && root->right == NULL))
        return 1;

    else
    {
        if(root->left != NULL)
            left_data = root->left->data;

        if(root->right != NULL)
            right_data = root->right->data;

        if((root->data == left_data+right_data)&& isSumProperty(root->left) && isSumProperty(root->right))
            return 1;
        else
            return 0;
    }

}
int main()
{
    Node *root = newNode(10);
    root->left = newNode(8);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(5);
    root->right->right = newNode(1);

    if(isSumProperty(root)){
        cout<<"Yes";
    }
    else
        cout<<"No";
    return 0;
}
