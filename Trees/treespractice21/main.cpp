#include <iostream>

using namespace std;
struct Node{
    char data;
    Node *left;
    Node *right;
};

Node *newNode(char value)
{
    Node *n  = new Node();
    n->data = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}
int searchInorder(char *in, int inStart, int inEnd, char value)
{
    int i;
    for(i= inStart;i<=inEnd;i++)
    {
        if(in[i] == value)
            return i;
    }
}
Node* buildTree(char* in, char* pre, int inStart, int inEnd)
{
    static int preIndex=0;
    if(inStart > inEnd)
        return NULL;
    Node *tNode = newNode(pre[preIndex++]);
    if(inStart == inEnd)
        return tNode;
    int inIndex = searchInorder(in, inStart, inEnd, tNode->data);
    tNode->left = buildTree(in,pre,inStart,inIndex-1);
    tNode->right = buildTree(in, pre, inIndex+1, inEnd);
    return tNode;
}
void printInOrder(Node *root)
{
    if(root == NULL)
        return ;
    else{
        printInOrder(root->left);
        cout<<root->data<<"   ";
        printInOrder(root->right);
    }
}
int main()
{
    char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
    char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
    int len = sizeof(in)/sizeof(in[0]);
    Node *root = buildTree(in, pre, 0, len - 1);
    cout<<"InOrder traversal";
    printInOrder(root);
    return 0;
}
