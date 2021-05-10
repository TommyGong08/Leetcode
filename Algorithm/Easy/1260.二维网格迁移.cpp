/*
 * @lc app=leetcode.cn id=1260 lang=cpp
 *
 * [1260] 二维网格迁移
 *
 * https://leetcode-cn.com/problems/shift-2d-grid/description/
 *
 * algorithms
 * Easy (60.51%)
 * Likes:    45
 * Dislikes: 0
 * Total Accepted:    10.9K
 * Total Submissions: 18.1K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]\n1'
 *
 * 给你一个 m 行 n 列的二维网格 grid 和一个整数 k。你需要将 grid 迁移 k 次。
 * 
 * 每次「迁移」操作将会引发下述活动：
 * 
 * 
 * 位于 grid[i][j] 的元素将会移动到 grid[i][j + 1]。
 * 位于 grid[i][n - 1] 的元素将会移动到 grid[i + 1][0]。
 * 位于 grid[m - 1][n - 1] 的元素将会移动到 grid[0][0]。
 * 
 * 
 * 请你返回 k 次迁移操作后最终得到的 二维网格。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：grid = [[1,2,3],[4,5,6],[7,8,9]], k = 1
 * 输出：[[9,1,2],[3,4,5],[6,7,8]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入：grid = [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]], k = 4
 * 输出：[[12,0,21,13],[3,8,1,9],[19,7,2,5],[4,6,11,10]]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：grid = [[1,2,3],[4,5,6],[7,8,9]], k = 9
 * 输出：[[1,2,3],[4,5,6],[7,8,9]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 
 * 1 
 * -1000 
 * 0 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        queue<int> myQueue;
        vector<vector<int>>::iterator iter1;
        vector<int>::iterator iter2;
        vector<int> temp;
        int len = grid.size();
        for(int i = len -1  ;i >= 0;i--){
            for(int j = grid[0].size()-1; j >= 0 ; j--){
                myQueue.push(grid[i][j]);
            }
        }
        int temp_num = 0;
        while(k--){
            temp_num = myQueue.front();
            myQueue.push(temp_num);
            myQueue.pop();
        }
        stack<int> stack;
        while(!myQueue.empty()){
            temp_num = myQueue.front();
            stack.push(temp_num);
            myQueue.pop();
        }
        vector<vector<int>> ans;
        vector<int> temp_ans;
        int i = 1 ;
        while(!stack.empty()){
            if(i % (grid[0].size()) == 0){
                temp_num = stack.top();
                temp_ans.push_back(temp_num);
                stack.pop();
                ans.push_back(temp_ans);
                temp_ans.clear();
                i++;
            }
            else{
                temp_num = stack.top();
                temp_ans.push_back(temp_num);
                stack.pop();
                i++;
            }
        }
        return ans;
    }
};
// @lc code=end
/*
可以用队列实现，把所有的数放进一个队列里，之后将队头的数取出来放进队尾即可
*/
