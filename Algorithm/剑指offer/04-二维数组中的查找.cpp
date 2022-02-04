class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        //横向二分搜索会超时
        bool flag = false;
        int i = matrix.size()-1;
        int j = 0;
        // 从左下角向右上角搜索
        while( i >= 0 && j < matrix[0].size()){
            if(matrix[i][j] > target) i--;
            else if(matrix[i][j] < target) j++;
            else return true;
        }
        return flag;
    }   
};