class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //先求转置，再求行翻转
        int temp;
        int len = matrix[0].size();
        //先求转置
        for(int i=0;i<len;i++){
            for(int j=i;j<len;j++){
                temp = matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
        for(int i=0;i<len;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};