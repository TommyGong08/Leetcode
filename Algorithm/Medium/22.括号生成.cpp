/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (77.23%)
 * Likes:    1855
 * Dislikes: 0
 * Total Accepted:    295.5K
 * Total Submissions: 382.6K
 * Testcase Example:  '3'
 *
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 3
 * 输出：["((()))","(()())","(())()","()(())","()()()"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：["()"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void backtrack(string& temp_ans,vector<string>& ans,int left,int right,int& n){
        if(temp_ans.length() == 2*n){
            //串符合长度
            ans.push_back(temp_ans);
            return ;
        }
        if(left < n){
            temp_ans += "(";
            backtrack(temp_ans,ans,left+1,right,n);
            temp_ans.pop_back();
        }
        if(right < left){
            temp_ans += ")";
            backtrack(temp_ans,ans,left,right+1,n);
            temp_ans.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if(n == 1) {
            ans.push_back("()");
            return ans;
        }
        //在中间嵌套
        string temp_ans= "";
        backtrack(temp_ans,ans,0,0,n);
        return ans;
    }
};
// @lc code=end

