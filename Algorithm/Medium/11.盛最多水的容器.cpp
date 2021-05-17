/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 *
 * https://leetcode-cn.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (64.19%)
 * Likes:    2459
 * Dislikes: 0
 * Total Accepted:    438.1K
 * Total Submissions: 683.9K
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * 给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为
 * (i, ai) 和 (i, 0) 。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
 * 
 * 说明：你不能倾斜容器。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：[1,8,6,2,5,4,8,3,7]
 * 输出：49 
 * 解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
 * 
 * 示例 2：
 * 
 * 
 * 输入：height = [1,1]
 * 输出：1
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：height = [4,3,2,1,4]
 * 输出：16
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：height = [1,2,1]
 * 输出：2
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n = height.length
 * 2 
 * 0 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0; //左指针
        int r = height.size() -1;//右指针
        int ans = 0;
        while(l < r){
            ans = max(ans,min(height[r],height[l]) * (r-l));
            if(height[r] <= height[l]){
                r++;
            }
            else{
                l--;
            }
        }
        return ans;
    }
};
// @lc code=end

/**
采用双指针，开始时左右指针分别位于数组边界
如果右边界小于左边界，那么右指针左移。
如果左边界小于右边界，那么左指针右移 
*/
