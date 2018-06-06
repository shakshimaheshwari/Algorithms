#include <iostream>

using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x): val(x), left(NULL), right(NULL){}
};
int helper(TreeNode* root, int &l , int &r){
        if(root == NULL) return 0;
        int ll =0 ;
        int lr = 0;
        int rl = 0;
        int rr = 0;
        l = helper(root->left, ll, lr);
        r = helper(root->right, rl , rr);
        return max(root->val+ll+lr+rl+rr, l+r);
    }
int rob(TreeNode* root) {
        if(root == NULL) return 0;
        int l =0 ;
        int r = 0;
        return helper(root, l, r);
    }
int main()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);

    int sum = rob(root);
    cout<<sum<<endl;
    return 0;
}
