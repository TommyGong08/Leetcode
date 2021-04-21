class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9]={0};
        int col[9][9]={0};
        int box[9][9]={0};
        int num;
        //遍历board每一个元素
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                else{
                    num = board[i][j]-'0';
                    num--;
                    if( row[i][num]==1 )    return false;
                    if( col[j][num]==1 )    return false;
                    if( box[(i/3)*3+j/3][num]==0 ){//没有数字
                        row[i][num]=1;
                        col[j][num]=1;
                        box[j/3+(i/3)*3][num]=1;
                    }       
                    else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};