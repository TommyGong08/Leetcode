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
    TreeNode* BSTbuild(vector<int>& nums,int left,int right){
        if(left > right) return nullptr;
        int mid = (left+right)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        //左边
        root->left = BSTbuild(nums,left,mid-1);
        //右边
        root->right = BSTbuild(nums,mid+1,right);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums){
        if(nums.size() == 0) return nullptr;
        int left = 0,right = nums.size()-1;
        int mid = (left + right) /2;
        TreeNode* root = BSTbuild(nums,left,right);
        return root;
    }
};