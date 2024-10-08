class Solution {
public:
    bool isValid(char c,vector<vector<char>>& board,int row,int col){
        for(int i=0;i<9;i++){
            if(board[row][i]==c or board[i][col]==c) return false;
            if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)]==c) return false;
        }
        return true;
    }
    
    bool solve(vector<vector<char>>& board,int row){
        for(int i=row;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(isValid(c,board,i,j)){
                            board[i][j]=c;
                            if(solve(board,i)){
                                return true;
                            }
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0);
    }
};