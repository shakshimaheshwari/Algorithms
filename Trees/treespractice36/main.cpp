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
Node* constructTreeUtil(int *pre, char* preLN, int *index_ptr, int length)
{
    int index = *index_ptr;
    if(index == length)
        return NULL;

    Node* temp = newNode(pre[index]);
    (*index_ptr)++;

    if(preLN[index] == 'N')
    {
        temp->left = constructTreeUtil(pre, preLN,index_ptr, length);
        temp->right = constructTreeUtil(pre, preLN, index_ptr, length);
    }
    return temp;
}
Node* ConstructTree(int *pre, char* preLN, int length)
{
    int index =0;
    return constructTreeUtil(pre, preLN, &index, length);
}
void printTreeInorder(Node* root)
{
    if(root == NULL)
        return;

    else{
        printTreeInorder(root->left);
        cout<<root->data<<"  ";
        printTreeInorder(root->right);
    }

}
int main()
{
    int pre[] = {10, 30, 20, 5, 15};
    char preLN[] = {'N', 'N', 'L', 'L', 'L'};
    int n = sizeof(pre)/sizeof(pre[0]);
    Node* root = ConstructTree(pre, preLN,n);

    cout<<"The tree is::";
    printTreeInorder(root);
    return 0;
}
