/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 *
 * https://leetcode-cn.com/problems/largest-number/description/
 *
 * algorithms
 * Medium (40.97%)
 * Likes:    763
 * Dislikes: 0
 * Total Accepted:    114.3K
 * Total Submissions: 278.8K
 * Testcase Example:  '[10,2]'
 *
 * 给定一组非负整数 nums，重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数。
 * 
 * 注意：输出结果可能非常大，所以你需要返回一个字符串而不是整数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [10,2]
 * 输出："210"
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [3,30,34,5,9]
 * 输出："9534330"
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1]
 * 输出："1"
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：nums = [10]
 * 输出："10"
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
    static int cmp(const int num1,const int num2){
        long sx = 10, sy = 10;
        while(sx <= num1){
            sx *= 10;
        }
        while(sy <= num2){
            sy *= 10;
        }
        return sy * num1 + num2 > sx * num2 + num1;
    }
    string largestNumber(vector<int>& nums) {
        string ans;
        if(nums.size() == 1){
            ans = to_string(nums[0]);
        }
        sort(nums.begin(), nums.end(),cmp);
        if(nums[0] == 0) return "0";
        ans = "";
        for(int i = 0; i < nums.size(); i++){
            ans += to_string(nums[i]); 
        }
        return ans;
    }
};
// @lc code=end

