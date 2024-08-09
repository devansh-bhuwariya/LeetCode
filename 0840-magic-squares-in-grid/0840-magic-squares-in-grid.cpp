class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int count=0;
        int row=grid.size();
        int col=grid[row-1].size();
        if(row<3 or col<3){
            return 0;
        }
        for(int i=0;i<row-2;i++){
            for(int j=0;j<col-2;j++){
                set<int> temp={grid[i][j],grid[i][j+1],grid[i][j+2],grid[i+1][j],grid[i+1][j+1],
                                  grid[i+1][j+2],grid[i+2][j],grid[i+2][j+1],grid[i+2][j+2]>9};
                if(temp.size()!=9){
                    continue;
                }
                if(grid[i][j]>9 or grid[i][j+1]>9 or grid[i][j+2]>9 or grid[i+1][j]>9 or grid[i+1][j+1]>9 or 
                   grid[i+1][j+2]>9 or grid[i+2][j]>9 or grid[i+2][j+1]>9 or grid[i+2][j+2]>9){
                    continue;
                }
                int sum=grid[i][j]+grid[i][j+1]+grid[i][j+2];
                if(grid[i][j]+grid[i+1][j]+grid[i+2][j]!=sum or grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2]!=sum
                    or grid[i+1][j]+grid[i+1][j+1]+grid[i+1][j+2]!=sum or grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2]!=sum or
                    grid[i][j+1]+grid[i+1][j+1]+grid[i+2][j+1]!=sum or grid[i][j+2]+grid[i+1][j+2]+grid[i+2][j+2]!=sum){
                    continue;
                }
                count+=1;
            }
        }
        return count;
    }
};