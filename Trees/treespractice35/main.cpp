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
    n->right =NULL;
    return n;
}
int maxitem(int *inorder, int start, int endlen)
{
    int max_item = inorder[0];
    int max_index = start;
    for(int i=start+1;i<=endlen;i++)
    {
        if(inorder[i] > max_item)
        {
            max_item = inorder[i];
            max_index = i;
        }
    }
    return max_index;
}
Node* buildTree(int *inorder,int start, int endlen)
{
    if(start> endlen)
        return NULL;
    int mid;
    mid = maxitem(inorder, start, endlen);

    Node *root = newNode(inorder[mid]);
    if(start == endlen)
        return root;

    root->left = buildTree(inorder, start, mid-1);
    root->right = buildTree(inorder, mid+1, endlen);

    return root;

}

void printInOrder(Node *root)
{
    if(root == NULL)
        return;

    else{
        printInOrder(root->left);
        cout<<root->data<<"  ";
        printInOrder(root->right);
    }
}
int main()
{
    int inorder[] = {5, 10, 40, 30, 28};
    int n = sizeof(inorder)/sizeof(inorder[0]);
    Node *root = buildTree(inorder, 0, n-1);
    cout<<"The tree is::";

    printInOrder(root);


    return 0;
}
