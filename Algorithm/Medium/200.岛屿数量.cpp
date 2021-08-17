/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 *
 * https://leetcode-cn.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (54.95%)
 * Likes:    1284
 * Dislikes: 0
 * Total Accepted:    298.7K
 * Total Submissions: 543.3K
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
 * 
 * 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
 * 
 * 此外，你可以假设该网格的四条边均被水包围。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：grid = [
 * ⁠ ["1","1","1","1","0"],
 * ⁠ ["1","1","0","1","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","0","0","0"]
 * ]
 * 输出：1
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：grid = [
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","1","0","0"],
 * ⁠ ["0","0","0","1","1"]
 * ]
 * 输出：3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 
 * grid[i][j] 的值为 '0' 或 '1'
 * 
 * 
 */

// @lc code=start
class Solution {
public:
   const int direct[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    int rows;
    int cols;
    void dfs(vector<vector<char>>& grid, int i, int j){
        grid[i][j] = '0';
        for(int k = 0; k < 4; k++){
            int new_rows = i + direct[k][0];
            int new_cols = j + direct[k][1];
            if( new_rows>=0 && new_rows < rows && new_cols >=0&&new_cols < cols && grid[new_rows][new_cols] == '1'){
                dfs(grid, new_rows, new_cols);
            }  
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0 || grid[0].size()== 0) return 0;
        rows = grid.size();
        cols = grid[0].size();
        int ans = 0 ;
        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < cols;j++){
                if(grid[i][j] == '1'){
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;

    }
};
// @lc code=end

