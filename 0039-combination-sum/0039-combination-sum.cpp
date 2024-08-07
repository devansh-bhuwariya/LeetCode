class Solution {
public:
    void recur(int ind,int target,vector<int>& candidates,vector<int>& sub,vector<vector<int>>& result){
        if(target==0){
            result.push_back(sub);
            return;
        }
        if(ind==candidates.size()){
            return;
        }
        if(candidates[ind]<=target and (ind==0 or candidates[ind]!=candidates[ind-1])){
            sub.push_back(candidates[ind]);
            recur(ind,target-candidates[ind],candidates,sub,result);
            sub.pop_back();
        }
        recur(ind+1,target,candidates,sub,result);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>sub;
        recur(0,target,candidates,sub,result);
        return result;
    }
};