/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
 *
 * https://leetcode-cn.com/problems/path-sum-iii/description/
 *
 * algorithms
 * Medium (56.62%)
 * Likes:    843
 * Dislikes: 0
 * Total Accepted:    77K
 * Total Submissions: 136K
 * Testcase Example:  '[10,5,-3,3,2,null,11,3,-2,null,1]\n8'
 *
 * 给定一个二叉树，它的每个结点都存放着一个整数值。
 * 
 * 找出路径和等于给定数值的路径总数。
 * 
 * 路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
 * 
 * 二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。
 * 
 * 示例：
 * 
 * root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
 * 
 * ⁠     10
 * ⁠    /  \
 * ⁠   5   -3
 * ⁠  / \    \
 * ⁠ 3   2   11
 * ⁠/ \   \
 * 3  -2   1
 * 
 * 返回 3。和等于 8 的路径有:
 * 
 * 1.  5 -> 3
 * 2.  5 -> 2 -> 1
 * 3.  -3 -> 11
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    unordered_map<int,int> prefix;
    void dfs(TreeNode* root,int targetSum, int curr_sum , int& ans){
        if(!root) return ;
        curr_sum += root->val;
        if(prefix.find(curr_sum-targetSum) != prefix.end()){
            //找得到
            ans += prefix[curr_sum-targetSum];
        }
        prefix[curr_sum]++;
        dfs(root->left,targetSum,curr_sum,ans);
        dfs(root->right,targetSum,curr_sum,ans);
        prefix[curr_sum]--;//回溯
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;//路径条数
        prefix[0] = 1;
        //curr_sum = 0
        dfs(root,targetSum,0,ans);
        return ans;
    }
};
// @lc code=end

/*
采用前缀和
看一下数中是否存在数值等于curr_sum-targetSum的节点
前缀和为0的路径只有一条，哪个节点都不选
*/


