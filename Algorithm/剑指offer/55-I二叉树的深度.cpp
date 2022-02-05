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
    int res = 0;
    int findDepth(TreeNode* root, int depth){
        //depth：当前深度
        if(root==NULL) return res;
        if(res < depth) res++;
        findDepth(root->left,depth+1);
        findDepth(root->right,depth+1);
        return res;
    }
    int maxDepth(TreeNode* root) {
        findDepth(root,1);
        return res;
    }
};