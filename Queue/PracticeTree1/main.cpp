#include <iostream>
#include <climits>

using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x): val(x), left(NULL),right(NULL){}
};
int max_sum = INT_MIN;
int helper(TreeNode* root){
    if(root == NULL) return 0;
    int leftVal = max(0,helper(root->left));
    int rightVal = max(0,helper(root->right));
    max_sum = max(max_sum, leftVal+rightVal+root->val);
    return max(leftVal, rightVal) + root->val;
}
int maxPathSum(TreeNode* root){
    if(root == NULL) return 0;
    helper(root);
    return max_sum;
}
int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    int sum = maxPathSum(root);
    cout<<sum<<endl;
    return 0;
}
