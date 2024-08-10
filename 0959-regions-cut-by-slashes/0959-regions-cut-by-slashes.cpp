class Solution {
public:
    const vector<vector<int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
    
    bool isValid(vector<vector<int>>&newGrid,int row,int col){
        int n=newGrid.size();
        return row>=0 and row<n and col>=0 and col<n and newGrid[row][col]==0;
    }
    
    void floodFill(vector<vector<int>>& newGrid,int row,int col){
        queue<pair<int,int>> q;
        newGrid[row][col]=1;
        q.push({row,col});
        while(!q.empty()){
            auto [cur_Row,cur_Col]=q.front();
            q.pop();
            for(auto& direction:directions){
                int newRow=cur_Row+direction[0];
                int newCol=cur_Col+direction[1];
                if(isValid(newGrid,newRow,newCol)){
                    newGrid[newRow][newCol]=1;
                    q.push({newRow,newCol});
                }
            }
        }
    }
    
    int regionsBySlashes(vector<string>& grid) {
        int size=grid.size();
        vector<vector<int>> newGrid(size*3,vector<int>(size*3,0));
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                int baseRow=i*3;
                int baseCol=j*3;
                if(grid[i][j]=='\\'){
                    newGrid[baseRow][baseCol]=1;
                    newGrid[baseRow+1][baseCol+1]=1;
                    newGrid[baseRow+2][baseCol+2]=1;
                }else if(grid[i][j]=='/'){
                    newGrid[baseRow][baseCol+2]=1;
                    newGrid[baseRow+1][baseCol+1]=1;
                    newGrid[baseRow+2][baseCol]=1;
                }
            }
        }
        int regions=0;
        for(int i=0;i<size*3;i++){
            for(int j=0;j<size*3;j++){
                if(newGrid[i][j]==0){
                    floodFill(newGrid,i,j);
                    regions+=1;
                }
            }
        }
        return regions;
    }
};