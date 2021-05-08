/*
 * @lc app=leetcode.cn id=821 lang=cpp
 *
 * [821] 字符的最短距离
 *
 * https://leetcode-cn.com/problems/shortest-distance-to-a-character/description/
 *
 * algorithms
 * Easy (68.83%)
 * Likes:    180
 * Dislikes: 0
 * Total Accepted:    20.7K
 * Total Submissions: 30K
 * Testcase Example:  '"loveleetcode"\n"e"'
 *
 * 给你一个字符串 s 和一个字符 c ，且 c 是 s 中出现过的字符。
 * 
 * 返回一个整数数组 answer ，其中 answer.length == s.length 且 answer[i] 是 s 中从下标 i 到离它 最近
 * 的字符 c 的 距离 。
 * 
 * 两个下标 i 和 j 之间的 距离 为 abs(i - j) ，其中 abs 是绝对值函数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "loveleetcode", c = "e"
 * 输出：[3,2,1,0,1,0,0,1,2,2,1,0]
 * 解释：字符 'e' 出现在下标 3、5、6 和 11 处（下标从 0 开始计数）。
 * 距下标 0 最近的 'e' 出现在下标 3 ，所以距离为 abs(0 - 3) = 3 。
 * 距下标 1 最近的 'e' 出现在下标 3 ，所以距离为 abs(1 - 3) = 3 。
 * 对于下标 4 ，出现在下标 3 和下标 5 处的 'e' 都离它最近，但距离是一样的 abs(4 - 3) == abs(4 - 5) = 1 。
 * 距下标 8 最近的 'e' 出现在下标 6 ，所以距离为 abs(8 - 6) = 2 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "aaab", c = "b"
 * 输出：[3,2,1,0]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s[i] 和 c 均为小写英文字母
 * 题目数据保证 c 在 s 中至少出现一次
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> ans;
        //先遍历一遍数组，找到s里面有多少个c
        vector<int> local;
        for(int i = 0 ;i < s.size() ;i++){
            if(s[i] == c){
                local.push_back(i);//第n个字符c出现在i位置
            }
        }
        int min_dis = INT_MAX;
        int dis;
        for(int i = 0 ; i < s.size() ;i++){
            //计算与vector中元素的最近距离
            for(int j = 0 ; j < local.size() ; j++){
                dis = abs(i - local[j]);
                if(dis < min_dis){
                    min_dis = dis;
                }
            }
            ans.push_back(min_dis);
            min_dis = INT_MAX;
        }
        return ans;
    }
};
// @lc code=end

