/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 *
 * https://leetcode-cn.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (47.10%)
 * Likes:    373
 * Dislikes: 0
 * Total Accepted:    226.4K
 * Total Submissions: 480.6K
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
 * 
 * 说明：本题中，我们将空字符串定义为有效的回文串。
 * 
 * 示例 1:
 * 
 * 输入: "A man, a plan, a canal: Panama"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "race a car"
 * 输出: false
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        //采用双指针
        //先提取出数字和字母，放进一个字符串中
        string ss;
        for(char ch:s){
            if(isalnum(ch)){//是数字或者字母
                ss += tolower(ch); //全部转化为小写，放进ss中
            }
        }
        int len = ss.size();
        int left = 0, right = len-1;
        while(left < right){
            if(ss[left] != ss[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;


    }
};
// @lc code=end

