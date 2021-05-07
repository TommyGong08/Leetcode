/*
 * @lc app=leetcode.cn id=504 lang=cpp
 *
 * [504] 七进制数
 *
 * https://leetcode-cn.com/problems/base-7/description/
 *
 * algorithms
 * Easy (50.11%)
 * Likes:    83
 * Dislikes: 0
 * Total Accepted:    24.1K
 * Total Submissions: 48.2K
 * Testcase Example:  '100'
 *
 * 给定一个整数，将其转化为7进制，并以字符串形式输出。
 * 
 * 示例 1:
 * 
 * 
 * 输入: 100
 * 输出: "202"
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: -7
 * 输出: "-10"
 * 
 * 
 * 注意: 输入范围是 [-1e7, 1e7] 。
 * 
 */

// @lc code=start
class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0) return "0";
        string ans="";
        int n;
        if(num > 0){
            while(num >= 7){
                n = num % 7;
                num = num / 7;
                ans += to_string(n);
            }
            ans += to_string(num);
        }
        else{
            num = -num;
            while(num >= 7){
                n = num % 7;
                num = num / 7;
                ans += to_string(n);
            }
            ans += to_string(num);
            ans += "-";
        }
        //字符串反转
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
// @lc code=end


