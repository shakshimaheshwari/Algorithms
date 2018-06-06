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
    n->right= NULL;
    return n;
}

int hasPathSum(Node *root, int sum)
{
    if(root == NULL)
        return (sum == 0);
    else
    {

        int subSum = sum - root->data;
        if(subSum == 0 && root->left == NULL && root->right == NULL)
            return 1;
        if(root->left != NULL)
            return(hasPathSum(root->left, subSum));

        if(root->right != NULL)
            return(hasPathSum(root->right, subSum));

    }

}
int main()
{
  int x;
  Node *root = newNode(10);
  root->left        = newNode(8);
  root->right       = newNode(2);
  root->left->left  = newNode(3);
  root->left->right = newNode(5);
  root->right->left = newNode(2);

  cout<<"Enter the sum which you want to search for::";
  cin>>x;
    int ans = hasPathSum(root, x);

    if(ans)
        cout<<"Path exist";
    else
        cout<<"Path does not exist";
    return 0;
}
