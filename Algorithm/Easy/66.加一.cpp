/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 *
 * https://leetcode-cn.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (45.69%)
 * Likes:    679
 * Dislikes: 0
 * Total Accepted:    281.1K
 * Total Submissions: 615.3K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
 * 
 * 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
 * 
 * 你可以假设除了整数 0 之外，这个整数不会以零开头。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：digits = [1,2,3]
 * 输出：[1,2,4]
 * 解释：输入数组表示数字 123。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：digits = [4,3,2,1]
 * 输出：[4,3,2,2]
 * 解释：输入数组表示数字 4321。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：digits = [0]
 * 输出：[1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 0 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int len = digits.size();
        int flag = 1;//进位标识符
        int current_digit = digits[len-1] + 1;
        for(int i = len-1; i>=0; i--){
            if(flag == 1){
                current_digit = digits[i] + 1;
            }
            else if (flag == 0) current_digit = digits[i];
            if(current_digit >=0 && current_digit <= 9){
                flag = 0;
                ans.push_back(current_digit);
            }
            else if(current_digit == 10 && i != 0){
                //digits[i] = 0;
                current_digit = 0;
                flag = 1;
                ans.push_back(current_digit);
            }
            else if(current_digit==10 && i == 0){
                current_digit = 0;
                flag = 1;
                ans.push_back(current_digit);
                ans.push_back(1);
            }
        }
        //vector的反转函数
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
// @lc code=end

/*
【注】
1. vector的反转函数为reverse(vector.begin() , vector.end())
2. 考虑第一位需要进位的情况
*/