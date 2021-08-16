/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 *
 * https://leetcode-cn.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (44.14%)
 * Likes:    1425
 * Dislikes: 0
 * Total Accepted:    277.5K
 * Total Submissions: 628.5K
 * Testcase Example:  '[1,2,5]\n11'
 *
 * 给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
 * 
 * 计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。
 * 
 * 你可以认为每种硬币的数量是无限的。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：coins = [1, 2, 5], amount = 11
 * 输出：3 
 * 解释：11 = 5 + 5 + 1
 * 
 * 示例 2：
 * 
 * 
 * 输入：coins = [2], amount = 3
 * 输出：-1
 * 
 * 示例 3：
 * 
 * 
 * 输入：coins = [1], amount = 0
 * 输出：0
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：coins = [1], amount = 1
 * 输出：1
 * 
 * 
 * 示例 5：
 * 
 * 
 * 输入：coins = [1], amount = 2
 * 输出：2
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * 0 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        vector<int> dp(10000,0);
        for(int i = 0 ; i< coins.size(); i++){
            if(coins[i] > 10001) continue;
            else dp[coins[i]] = 1;
        }
        for(int i = 1 ; i<= amount; i++){
            if(dp[i] > 0) continue;
            int temp_dp = 10001;
            for(int j = 0; j < coins.size();j++){
                if(i - coins[j] > 0){
                     if(dp[i - coins[j]] > 0){
                        temp_dp = min(temp_dp, dp[i-coins[j]]+1);
                    }
                }
            }
            dp[i] = temp_dp;
        }
        if(dp[amount] > 0 && dp[amount] < 10001) return dp[amount];
        return -1;
    }
};
// @lc code=end

