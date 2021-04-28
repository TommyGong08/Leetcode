/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 *
 * https://leetcode-cn.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (65.92%)
 * Likes:    965
 * Dislikes: 0
 * Total Accepted:    305.1K
 * Total Submissions: 462.7K
 * Testcase Example:  '[3,2,3]'
 *
 * 给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。
 * 
 * 你可以假设数组是非空的，并且给定的数组总是存在多数元素。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：[3,2,3]
 * 输出：3
 * 
 * 示例 2：
 * 
 * 
 * 输入：[2,2,1,1,1,2,2]
 * 输出：2
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 尝试设计时间复杂度为 O(n)、空间复杂度为 O(1) 的算法解决此问题。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> hashmap;
        int max_num = -1;
        int max_index = -1;
        for(int i = 0;i < nums.size() ;i++){
            //如果hashmap中没有该数
            if(hashmap.find(nums[i]) == hashmap.end()){
                hashmap[nums[i]] = 1;
            }
            else{
                //hashmap中有该数
                hashmap[nums[i]]++;
            }
            if(hashmap[nums[i]] >= max_num){
                max_num = hashmap[nums[i]];
                max_index = nums[i];
            }
        }
        return max_index;
    }
};
// @lc code=end
/*
注意，笔者刚开始用了两次遍历，第二遍特意遍历了一遍hashmap。
其实没必要，在第一次遍历过程中处理就行了
*/
