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
void printArray(int *path,int pathLen)
{
    for(int i=0;i<pathLen;i++)
        cout<<path[i]<<"   ";
    cout<<endl;
}
void PrintPathsRecur(Node *root, int *path, int pathLen)
{
    if(root == NULL)
        return;
    path[pathLen] = root->data;
    pathLen++;

    if(root->left == NULL && root->right == NULL)
        printArray(path, pathLen);

    else
    {
        PrintPathsRecur(root->left, path, pathLen);
        PrintPathsRecur(root->right, path, pathLen);
    }
}


void printPaths(Node *root)
{
    int path[1000];
    PrintPathsRecur(root,path, 0);
}


int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    printPaths(root);
    return 0;
}
