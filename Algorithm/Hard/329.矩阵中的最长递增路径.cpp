/*
 * @lc app=leetcode.cn id=329 lang=cpp
 *
 * [329] 矩阵中的最长递增路径
 *
 * https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/description/
 *
 * algorithms
 * Hard (48.11%)
 * Likes:    508
 * Dislikes: 0
 * Total Accepted:    51.9K
 * Total Submissions: 107.8K
 * Testcase Example:  '[[9,9,4],[6,6,8],[2,1,1]]'
 *
 * 给定一个 m x n 整数矩阵 matrix ，找出其中 最长递增路径 的长度。
 * 
 * 对于每个单元格，你可以往上，下，左，右四个方向移动。 你 不能 在 对角线 方向上移动或移动到 边界外（即不允许环绕）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix = [[9,9,4],[6,6,8],[2,1,1]]
 * 输出：4 
 * 解释：最长递增路径为 [1, 2, 6, 9]。
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = [[3,4,5],[3,2,6],[2,2,1]]
 * 输出：4 
 * 解释：最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：matrix = [[1]]
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 
 * 0 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
     const int direct[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int colunms;
    int rows;
    int dfs(vector<vector<int>>& matrix, int i, int j,vector<vector<int>>& mem_matrix){
        if(mem_matrix[i][j]!=0) return mem_matrix[i][j];
        //没访问过的点深度搜索
        mem_matrix[i][j]++;
        for(int k = 0 ; k < 4; k++){
            int new_rows = i + direct[k][0];
            int new_col = j + direct[k][1];
            if(new_col >= 0 && new_col < colunms && new_rows < rows && new_rows >=0 && matrix[new_rows][new_col] > matrix[i][j])
            {
                mem_matrix[i][j] = max(mem_matrix[i][j], dfs(matrix, new_rows, new_col, mem_matrix) + 1);
            }
        }
        return mem_matrix[i][j] ;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0|| matrix[0].size() == 0) return 0;
        int ans = 0;
        //创建一个记忆矩阵
        rows = matrix.size();
        colunms = matrix[0].size();
        auto mem_matrix =  vector<vector<int>> (rows, vector<int>(colunms));
        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < colunms ; j ++){
                ans = max(ans, dfs(matrix, i, j, mem_matrix));
            }
        }
        return ans;

    }
};
// @lc code=end

