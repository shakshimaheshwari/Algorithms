#include <iostream>
#include <string>

using namespace std;
struct TreeNode{
    char val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char c): val(c), left(NULL), right(NULL){}
};
TreeNode* helper(string s, int &i){
    TreeNode* root = new TreeNode(s[i]);
    i++;
    if(s[i] == '?'){
        root->left = helper(s, ++i);
    }else if(s[i] == ':'){
        root->right = helper(s, ++i);
    }
    return root;
}

TreeNode* convertToTree(string s){
    if(s.length() ==0 ) return NULL;
    int i=0;
    return helper(s,i);
}

void print(TreeNode* root){
    if(root){
        cout<<root->val<<" ";
        print(root->left);

        print(root->right);
    }
}
int main()
{
    string s = "a?b?c:d:e";
    TreeNode* root = convertToTree(s);
    print(root);
    return 0;
}
