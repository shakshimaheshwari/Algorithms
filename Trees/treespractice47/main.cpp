#include <iostream>
#include <queue>

using namespace std;
struct ListNode{
    int data;
    ListNode* next;
};
struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
};

ListNode* newListNode(int value)
{
    ListNode *n = new ListNode();
    n->data = value;
    n->next = NULL;
    return n;
}

TreeNode* newTreeNode(int value)
{
    TreeNode *n = new TreeNode();
    n->data = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void convertList2Binary(ListNode* head, TreeNode*& root)
{
    queue<TreeNode*> q;

    if(head == NULL)
    {
        root = NULL;
        return;
    }
    root = newTreeNode(head->data);
    q.push(root);

    head = head->next;

    while(head)
    {
        TreeNode* parent = q.front();
        q.pop();

        TreeNode* leftChild = NULL;
        TreeNode* rightChild = NULL;

        leftChild = newTreeNode(head->data);
        q.push(leftChild);
        head = head->next;
        if(head)
        {
            rightChild = newTreeNode(head->data);
            q.push(rightChild);
            head= head->next;
        }
        parent->left = leftChild;
        parent->right = rightChild;
    }

}

void printInorder(TreeNode* root)
{
    if(root == NULL)
        return;
    else
    {
        printInorder(root->left);
        cout<<root->data<<"   ";
        printInorder(root->right);
    }
}
int main()
{
    ListNode* head = newListNode(10);
    head->next = newListNode(12);
    head->next->next = newListNode(15);
    head->next->next->next = newListNode(25);
    head->next->next->next->next = newListNode(30);
    head->next->next->next->next->next = newListNode(36);

    TreeNode *root;

    convertList2Binary(head, root);

    cout<<"The inorder traversal of the tree is::";
    printInorder(root);
    return 0;
}
