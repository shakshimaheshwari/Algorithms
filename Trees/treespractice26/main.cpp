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

int levelofNodeUtil(Node *root, int number, int level)
{
    if(root == NULL)
        return 0;

    if(root->data == number)
        return level;

    int downlevel = levelofNodeUtil(root->left, number, level+1);
    if(downlevel!=0)
    return downlevel;

    downlevel = levelofNodeUtil(root->right, number, level+1);
    return downlevel;

}

int levelofNode(Node *root, int number)
{
    return levelofNodeUtil(root, number, 1);
}
int main()
{
    int number;
    Node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->right  = newNode(4);
    root->right->left = newNode(5);
    cout<<"Enter the data wich you want to search::";
    cin>>number;
    int d = levelofNode(root, number);
    cout<<"Level of the node is::"<<d;
    return 0;
}
