#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x): val(x), left(NULL), right(NULL){}
};
TreeNode* inorderSucc(TreeNode* root, TreeNode* node){
    TreeNode* suc =  NULL;
    while(root){
        cout<<root->val;
        cout<<node->val;
        if(node->val >= root->val){
            root= root->right;
        }else{
            suc = root;
            root = root->left;
        }
    }
    return suc;
}
int main(){
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(7);

    TreeNode* node = root->left->right;
    TreeNode* successor = inorderSucc(root, node);
    if(successor){
        cout<<successor->val;
    }else{
        cout<<"No inorder successor";
    }

}
