class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int row=points.size();
        int col=points[0].size();
        vector<long long>previousRow={points[0].begin(),points[0].end()};
        vector<long long>currentRow(points.size());
        for(int i=0;i<row-1;i++){
            vector<long long>leftMax(col);
            vector<long long>rightMax(col);
            vector<long long>currentRow(col);
            leftMax[0]=previousRow[0];
            rightMax[col-1]=previousRow[col-1];
            for(int j=1;j<col;j++){
                leftMax[j]=max(leftMax[j-1]-1,previousRow[j]);
            }
            for(int j=col-2;j>=0;j--){
                rightMax[j]=max(rightMax[j+1]-1,previousRow[j]);
            }
            for(int j=0;j<col;j++){
                currentRow[j]=points[i+1][j]+max(leftMax[j],rightMax[j]);
            }
                     previousRow=currentRow;
        }
        long long maxi=*max_element(previousRow.begin(),previousRow.end());
        return maxi;
     }
};