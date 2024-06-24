class Solution {
public:
    vector<int> generateRow(int n){
        vector<int> row;
        long long ans=1;
        row.push_back(1);
        for(int i=1;i<n;i++){
            ans=ans*(n-i);
            ans=ans/(i);
            row.push_back(ans);
        }
        return row;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};