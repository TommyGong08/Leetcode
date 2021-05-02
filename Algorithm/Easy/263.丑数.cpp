/*
 * @lc app=leetcode.cn id=263 lang=cpp
 *
 * [263] 丑数
 *
 * https://leetcode-cn.com/problems/ugly-number/description/
 *
 * algorithms
 * Easy (51.44%)
 * Likes:    249
 * Dislikes: 0
 * Total Accepted:    94.5K
 * Total Submissions: 183.6K
 * Testcase Example:  '6'
 *
 * 给你一个整数 n ，请你判断 n 是否为 丑数 。如果是，返回 true ；否则，返回 false 。
 * 
 * 丑数 就是只包含质因数 2、3 和/或 5 的正整数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 6
 * 输出：true
 * 解释：6 = 2 × 3
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 8
 * 输出：true
 * 解释：8 = 2 × 2 × 2
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：n = 14
 * 输出：false
 * 解释：14 不是丑数，因为它包含了另外一个质因数 7 。
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：n = 1
 * 输出：true
 * 解释：1 通常被视为丑数。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * -2^31 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isUgly(int n) {
        if(n <= 0) return false;
        vector<int> v;
        v.push_back(2);
        v.push_back(3);
        v.push_back(5);
        for(int i =0;i < v.size();i++){
            while(n%v[i] ==0){
                n /= v[i];
            }
        }
        if(n == 1) return true;
        else return false;
    }
};
// @lc code=end

/*
根据丑数的定义，00 和负整数一定不是丑数。

当 n>0n>0 时，若 nn 是丑数，则 nn 可以写成 n = 2^a \times 3^b \times 5^cn
  的形式，其中 a,b,ca,b,c 都是非负整数。特别地，当 a,b,ca,b,c 都是 00 时，n=1n=1。

为判断 nn 是否满足上述形式，可以对 nn 反复除以 2,3,5,2,3,5，直到 nn 不再包含质因数 2,3,52,3,5。若剩下的数等于 11，则说明 nn 不包含其他质因数，是丑数；否则，说明 nn 包含其他质因数，不是丑数
*/
