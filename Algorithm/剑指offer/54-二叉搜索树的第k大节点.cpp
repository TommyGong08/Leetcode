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
    vector<int> res; //用于储存二叉树数字
    TreeNode* dfs(TreeNode* root){
        if(root ==NULL) return root;
        res.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
        return root;
    }
    int kthLargest(TreeNode* root, int k) {
        dfs(root);
        sort(res.begin(), res.end());
        return res[res.size() - k];
    }
};