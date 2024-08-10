class Solution {
public:
    bool isValid(int col,int row,vector<string>&board){
        int c=col;
        int r=row;
        while(col>=0){
            if(board[row][col]=='Q') return false;
            col--;
        }
        col=c;
        row=r;
        while(row<board.size() and col>=0){
            if(board[row][col]=='Q') return false;
            row++;
            col--;
        }
        col=c;
        row=r;
        while(row>=0 and col>=0){
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }
        return true;
    }
    
    void recur(int col,int n,vector<string>&board,vector<vector<string>>&ans){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){
            if(isValid(col,i,board)){
                board[i][col]='Q';
                recur(col+1,n,board,ans);
                board[i][col]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        recur(0,n,board,ans);
        return ans;
    }
};