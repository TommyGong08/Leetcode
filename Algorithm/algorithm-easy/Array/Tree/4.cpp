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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        queue<TreeNode*> q;//a使用队列
        q.push(root);
       
        while(!q.empty()){//q非空
            int current_size = q.size();
            ans.push_back(vector<int> ());
            for(int i=0 ;i<current_size;i++){
                TreeNode* node = q.front();
                q.pop();
                ans.back().push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right); 
            }
        }
        return ans;
    }
};