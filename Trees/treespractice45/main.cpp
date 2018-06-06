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

int searchinorder(int *in, int value, int n)
{
    for(int i=0;i<n;i++)
        if(in[i] == value)
            return i;

    return -1;
}
void printPostOrder(int *in, int *pre, int n)
{
    int index = searchinorder(in, pre[0],n);
    if(index!=0)
        printPostOrder(in, pre+1, index);

    if(index != n-1)
        printPostOrder(in+index+1, pre+index+1, n-index-1);

    cout<<pre[0]<<"    ";
}
int main()
{
   int in[] = {4, 2, 5, 1, 3, 6};
   int pre[] =  {1, 2, 4, 5, 3, 6};
   int n = sizeof(in)/sizeof(in[0]);
   cout << "Postorder traversal " << endl;
   printPostOrder(in, pre, n);
    return 0;
}
