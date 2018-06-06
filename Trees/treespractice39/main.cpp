#include <iostream>

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
Node* constructTreeUtil(int *pre, int *post, int *preIndex, int l, int h, int len)
{
    if(*preIndex >= len || l>h)
        return NULL;

    Node* root = newNode(pre[*preIndex]);
    ++(*preIndex);

    if(l == h)
        return root;

    int i;
    for(i=l;i<=h;i++)
        if(pre[*preIndex] == post[i])
            break;


    if(i<=h)
    {
        root->left = constructTreeUtil(pre,post,preIndex,l,i,len);
        root->right = constructTreeUtil(pre, post,preIndex,i+1,h,len);
    }
    return root;

}
Node* constructTree(int *pre, int*post, int len)
{
    int preIndex = 0;
    return constructTreeUtil(pre, post,&preIndex,0,len-1, len);
}

void printInorder(Node* root)
{
    if(root)
    {
        printInorder(root->left);
        cout<<root->data<<"  ";
        printInorder(root->right);
    }
}
int main()
{
    int pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7};
    int post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
    int sizeofpre = sizeof( pre ) / sizeof( pre[0] );

    Node *root = constructTree(pre, post, sizeofpre);

    printInorder(root);
    return 0;
}
