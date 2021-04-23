/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (43.98%)
 * Likes:    2351
 * Dislikes: 0
 * Total Accepted:    611.4K
 * Total Submissions: 1.4M
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "()"
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "()[]{}"
 * 输出：true
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "(]"
 * 输出：false
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：s = "([)]"
 * 输出：false
 * 
 * 
 * 示例 5：
 * 
 * 
 * 输入：s = "{[]}"
 * 输出：true
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 仅由括号 '()[]{}' 组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        if(s.length()%2 == 1) return false;
        stack<char> ch_st;
        for(int i = 0; i < s.length(); i++){
            if(ch_st.empty()){
                ch_st.push(s[i]);
            }
            else{
                //非空
                char st_top = ch_st.top();
                if((st_top=='(' && s[i]==')') || (st_top == '{' && s[i] == '}') || (s[i] ==']' && st_top == '[')){
                    ch_st.pop();
                    continue;
                }
                else{
                    ch_st.push(s[i]);
                }
            }
        }
       return ch_st.empty();
    }
};
// @lc code=end

