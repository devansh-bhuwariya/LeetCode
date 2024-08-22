class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        sort(a.begin(),a.end());
        vector<vector<int>>ans;
        for(int i=0;i<a.size();i++){
            int start=a[i][0];
            int end=a[i][1];
            if(!ans.empty() and end<=ans.back()[1]){
                continue;
            }
            for(int j=i+1;j<a.size();j++){
                if(a[j][0]<=end){
                    end=max(end,a[j][1]);
                }else{
                    break;
                }
            }
            ans.push_back({start,end});
            
            
        }
        return ans;
    }
};