/*
 * @lc app=leetcode.cn id=371 lang=cpp
 *
 * [371] 两整数之和
 *
 * https://leetcode-cn.com/problems/sum-of-two-integers/description/
 *
 * algorithms
 * Medium (57.69%)
 * Likes:    393
 * Dislikes: 0
 * Total Accepted:    48.8K
 * Total Submissions: 84.5K
 * Testcase Example:  '1\n2'
 *
 * 不使用运算符 + 和 - ​​​​​​​，计算两整数 ​​​​​​​a 、b ​​​​​​​之和。
 * 
 * 示例 1:
 * 
 * 输入: a = 1, b = 2
 * 输出: 3
 * 
 * 
 * 示例 2:
 * 
 * 输入: a = -2, b = 3
 * 输出: 1
 * 
 */

// @lc code=start
class Solution {
public:
    int getSum(int a, int b) {
        while(b!= 0){
            auto mark = ((unsigned int) (a & b)) << 1;
            a = a^b;
            b = mark;
        }
        return a;
    }
};
// @lc code=end

/*
用mark记录两数相加产生的进位
a = a^b 能够计算出无进位的加法结果
可以用3+6=9 也就是011+110=1001来验证一下
*/

