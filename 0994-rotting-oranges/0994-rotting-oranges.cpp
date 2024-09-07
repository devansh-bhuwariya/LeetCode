class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>>q;
        vector<int> d_row={-1,0,1,0};
        vector<int>d_col={0,1,0,-1};
        set<vector<int>> vis;
        int time=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis.insert({i,j});
                }
            }
        }
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int newRow=r+d_row[i];
                int newCol=c+d_col[i];
                if(newRow>=0 and newRow<n and newCol>=0 and newCol<m){
                    if(grid[newRow][newCol]==1){
                        time=t+1;
                        grid[newRow][newCol]=2;
                        q.push({{newRow,newCol},t+1});
                        vis.insert({newRow,newCol});
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        
        return time;
    }
};