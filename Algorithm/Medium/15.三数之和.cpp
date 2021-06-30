/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (31.89%)
 * Likes:    3350
 * Dislikes: 0
 * Total Accepted:    512.8K
 * Total Submissions: 1.6M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0
 * 且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [-1,0,1,2,-1,-4]
 * 输出：[[-1,-1,2],[-1,0,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [0]
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * -10^5 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp_ans;
        if(nums.size() <= 2) return ans;

        //先将num从小到达排序
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size() ; i++){
            //如果a不同
            int k = nums.size() - 1;
            if(i == 0 || nums[i]!=nums[i-1]){
                for(int j = i+1; j < nums.size(); j++){//第二个循环
                    if (j > i + 1 && nums[j] == nums[j - 1]) {
                        continue;
                    }
                    // 需要保证 b 的指针在 c 的指针的左侧
                    while (j < k && nums[j] + nums[k] + nums[i] > 0) {
                        --k;
                    }
                    if (j == k) {
                        break;
                    }
                    if (nums[j] + nums[k] + nums[i] == 0) {
                        ans.push_back({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

//可以发现，如果我们固定了前两重循环枚举到的元素 aa 和 bb，
//那么只有唯一的 cc 满足 a+b+c=0a+b+c=0。当第二重循环往后枚举一个元素 b'b  时，
//由于 b' > bb >b，那么满足 a+b'+c'=0a+b ′+c′=0 的 c'c ′ 一定有 c' < cc ′ <c，
//即 c'c ′在数组中一定出现在 cc 的左侧。也就是说，我们可以从小到大枚举 bb，同时从大到小枚举 cc，
//即第二重循环和第三重循环实际上是并列的关系。
/*
nums.sort()
for first = 0 .. n-1
    if first == 0 or nums[first] != nums[first-1] then
        // 第三重循环对应的指针
        third = n-1
        for second = first+1 .. n-1
            if second == first+1 or nums[second] != nums[second-1] then
                // 向左移动指针，直到 a+b+c 不大于 0
                while nums[first]+nums[second]+nums[third] > 0
                    third = third-1
                // 判断是否有 a+b+c==0
                check(first, second, third)
*/

