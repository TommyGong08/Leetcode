class Solution {
public:
    bool dfs(int i, int j, string word,vector<vector<char>>& board,int k){
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j]!= word[k]){
            return false;
        }
        if(k == word.size()-1) return true;
        board[i][j] = '#';
        bool res = dfs(i,j+1,word,board,k+1) || dfs(i,j-1,word,board,k+1) || dfs(i+1,j,word,board,k+1) || 
            dfs(i-1,j,word,board,k+1);
        board[i][j] = word[k];
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        //dfs+ 回溯
        int cols = board.size();
        int rows = board[0].size();
        for(int i = 0; i < cols;i++){
            for(int j = 0; j < rows; j++){
                if (dfs(i,j,word,board,0)) return true;
            }
        }
        return false;
    }
};