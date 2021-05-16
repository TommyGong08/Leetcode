/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (34.04%)
 * Likes:    3646
 * Dislikes: 0
 * Total Accepted:    583.3K
 * Total Submissions: 1.7M
 * Testcase Example:  '"babad"'
 *
 * 给你一个字符串 s，找到 s 中最长的回文子串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "babad"
 * 输出："bab"
 * 解释："aba" 同样是符合题意的答案。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "cbbd"
 * 输出："bb"
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "a"
 * 输出："a"
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：s = "ac"
 * 输出："a"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 仅由数字和英文字母（大写和/或小写）组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() == 1 || s.size() == 0) return s;
        int start = 0;//记录最大子串的起始位置
        int max_len = 1; //记录最大回文串的长度
        int len = s.size();
        vector<vector<int>> dp(len,vector<int>(len));
        for(int i = 0 ; i < len ;i++){
            dp[i][i] = 1;
            if(i < len -1 && s[i] == s[i+1]){
                dp[i][i+1] = 1;
                start = i;
                max_len = 2;
            }
        }
        for(int l = 3; l <= len ;l++){
            for(int i = 0; i+l-1 < len ;i++){
                int j = i+l-1;
                if(s[i] == s[j] && dp[i+1][j-1] == 1){
                    dp[i][j] = 1;
                    max_len = l;
                    start = i;
                }
            }
        }
        return s.substr(start,max_len);
    }
};
// @lc code=end
/*
动态规划：dp[i][j] = dp[i+1][j-1] ^ (s[i] == s[j])
需要注意边界条件的确定
*/

