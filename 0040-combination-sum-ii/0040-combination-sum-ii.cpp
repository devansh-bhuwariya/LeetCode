class Solution {
public:
    void recur(int ind,vector<int>& candidates,int target,vector<vector<int>>& result,vector<int>& sub){
        if(target==0){
            result.push_back(sub);
            return;
        }
        for(int i=ind;i<candidates.size();i++){
            if(i>ind and candidates[i]==candidates[i-1]){
                continue;
            }else if(candidates[i]>target){
                break;
            }
            sub.push_back(candidates[i]);
            recur(i+1,candidates,target-candidates[i],result,sub);
            sub.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>sub;
        sort(candidates.begin(),candidates.end());
        recur(0,candidates,target,result,sub);
        return result;
    }
};