/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 *
 * https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/description/
 *
 * algorithms
 * Easy (57.83%)
 * Likes:    507
 * Dislikes: 0
 * Total Accepted:    213.8K
 * Total Submissions: 369.8K
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * 给定一个已按照 升序排列  的整数数组 numbers ，请你从数组中找出两个数满足相加之和等于目标数 target 。
 * 
 * 函数应该以长度为 2 的整数数组的形式返回这两个数的下标值。numbers 的下标 从 1 开始计数 ，所以答案数组应当满足 1  。
 * 
 * 你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：numbers = [2,7,11,15], target = 9
 * 输出：[1,2]
 * 解释：2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：numbers = [2,3,4], target = 6
 * 输出：[1,3]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：numbers = [-1,0], target = -1
 * 输出：[1,2]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 
 * -1000 
 * numbers 按 递增顺序 排列
 * -1000 
 * 仅存在一个有效答案
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> hashmap;
        int left;
        vector<int> ans;
        for(int i = 0; i < numbers.size(); i++){
            left = target - numbers[i];
            //如果hashmap中没有数字
            if(hashmap.find(left) == hashmap.end()){
                //hashmap以数组形式插入
                hashmap[numbers[i]] = i+1;
            }
            else{
                //hashmap中找到left
               for(auto iter = hashmap.begin() ; iter!= hashmap.end();iter++){
                   if(iter->first == left){
                       ans.push_back(iter->second);
                       break;
                   }
                }
                ans.push_back(i+1);
                break;
            }
        }
        return ans;
    }
};
// @lc code=end
/*
上面解法是用unordered_map做的


官方题解用的双指针
初始时两个指针分别指向第一个元素位置和最后一个元素的位置。每次计算两个指针指向的两个元素之和，并和目标值比较。如果两个元素之和等于目标值，则发现了唯一解。如果两个元素之和小于目标值，则将左侧指针右移一位。如果两个元素之和大于目标值，则将右侧指针左移一位。移动指针之后，重复上述操作，直到找到答案。
作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/solution/liang-shu-zhi-he-ii-shu-ru-you-xu-shu-zu-by-leet-2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

