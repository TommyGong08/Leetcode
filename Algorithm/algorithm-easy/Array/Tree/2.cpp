/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int BSTUtil(TreeNode* root,long long min,long long max){
        if(root == nullptr) return 1;
        if(root->val <= min || root ->val >=  max) return 0;
        return BSTUtil(root->left , min ,root ->val)&&
                BSTUtil(root->right,root->val,max);
    }
    bool isValidBST(TreeNode* root) {
        return BSTUtil(root,LONG_MIN,LONG_MAX);
    }
};