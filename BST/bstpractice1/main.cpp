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

void insertintoBST(Node*& n, int data, Node*& succ)
{
    if(n == NULL)
        n = newNode(data);

    if(data < n->data)
    {
        succ = n;
        insertintoBST(n->left, data, succ);
    }
    else if(data> n->data)
       insertintoBST(n->right, data, succ);
}

void replaceelements(int *a, int n)
{
    Node* root = NULL;
    for(int i=n-1;i>=0;i--)
    {
        Node* succ = NULL;
        insertintoBST(root,a[i],succ);

        if(succ)
            a[i]= succ->data;
        else
            a[i] = -1;
    }
}
int main()
{
    int n;
    cout<<"Enter the number of elements::";
    cin>>n;

    int *a = new int[n];
    cout<<"Enter the elements::";
    for(int i=0;i<n;i++)
        cin>>a[i];

    replaceelements(a,n);

    cout<<"The array elements are::";
    for(int i=0;i<n;i++)
        cout<<a[i]<<"  ";
    return 0;
}
