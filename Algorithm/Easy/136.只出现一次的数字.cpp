/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 *
 * https://leetcode-cn.com/problems/single-number/description/
 *
 * algorithms
 * Easy (71.28%)
 * Likes:    1830
 * Dislikes: 0
 * Total Accepted:    387.1K
 * Total Submissions: 543.1K
 * Testcase Example:  '[2,2,1]'
 *
 * 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
 * 
 * 说明：
 * 
 * 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
 * 
 * 示例 1:
 * 
 * 输入: [2,2,1]
 * 输出: 1
 * 
 * 
 * 示例 2:
 * 
 * 输入: [4,1,2,1,2]
 * 输出: 4
 * 
 */

// @lc code=start
class Solution {
public:
/*
    int singleNumber(vector<int>& nums) {
        //使用哈希表
        set<int> hashmap;
        for(int i = 0 ;i < nums.size() ; i++){
            //set中有该元素,弹出
            if(hashmap.find(nums[i]) != hashmap.end()){
                hashmap.erase(nums[i]);
            }
            else{//没有该元素，加入set中
                hashmap.insert(nums[i]);
            }
        }
        return *hashmap.begin();
    }
    */
    int singleNumber(vector<int>& nums) {
        //使用异或运算
        int ans = 0;
        for(auto it:nums){
            ans ^=it;
        }
        return ans;
    }
};
// @lc code=end
/*
用set也需要O(n)的空间的，与题目要求不符我们只能用第二种方法：位运算

*/
