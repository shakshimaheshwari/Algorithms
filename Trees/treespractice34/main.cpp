#include <iostream>
#include <climits>
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
void getTargetLeaf(Node *root, int * max_sum, int curr_sum, Node **target_leaf)
{
    if(root == NULL)
        return;

    curr_sum = curr_sum + root->data;


    if(root->left == NULL && root->right == NULL)
    {
        if(curr_sum > *max_sum)
        {
            *max_sum = curr_sum;
            *target_leaf = root;
        }
    }

    getTargetLeaf(root->left, max_sum, curr_sum, target_leaf);
    getTargetLeaf(root->right,max_sum, curr_sum, target_leaf);
}
void printPath(Node *root, Node *target_leaf)
{
    if(root == NULL)
        return;

    if((root == target_leaf)|| printPath(root->left, target_leaf)|| printPath(root->right, target_leaf))
    {
        cout<< root->data<<"   ";
    }

}
int MaxSumToLeaf(Node *root){
    if(root == NULL)
        return 0;

    int max_sum = INT_MIN;
    Node *target_leaf;

    getTargetLeaf(root, &max_sum, 0, &target_leaf);

    printPath(root, target_leaf);

    return max_sum;
}
int main()
{
    Node *root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(7);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);

    int max_sum = MaxSumToLeaf(root);

    cout<<"Sum of the nodes is::"<<max_sum;
    return 0;
}
