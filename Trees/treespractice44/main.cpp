#include <iostream>
#include <queue>

using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int value)
{
    Node* n = new Node();
    n->data = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}
int getLevelDiff1(Node *root)
{
    int level =0;
    int sum_odd =0, sum_even =0;
    queue<Node*>q;
    q.push(root);
    level++;
    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if(level%2 == 0)
            sum_even+=temp->data;
        else
            sum_odd+=temp->data;

        if(temp->left != NULL)
            q.push(temp->left);
        if(temp->right != NULL)
            q.push(temp->right);

        level++;


    }

    return(sum_even - sum_odd);
}
int getLevelDiff(Node* root)
{
    if(root == NULL)
        return 0;

    return root->data - getLevelDiff(root->left) - getLevelDiff(root->right);
}
int main()
{
    Node* root = newNode(5);
    root->left = newNode(2);
    root->right = newNode(6);
    root->left->left  = newNode(1);
    root->left->right = newNode(4);
    root->left->right->left = newNode(3);
    root->right->right = newNode(8);
    root->right->right->right = newNode(9);
    root->right->right->left = newNode(7);

    int h = getLevelDiff(root);
    int h1 = getLevelDiff1(root);
    cout<<"The level diff is::"<<h<<endl;
    cout<<"The level diff using level order traversal is::"<<h1;
    return 0;
}
