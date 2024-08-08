class Solution {
public:
    int count=0;
    void recur(int ind,vector<int>& candidates,int target,vector<vector<int>>& result,vector<int>& sub){
        if (target == 0) {
            result.push_back(sub);
            return;
        }
        if (ind == candidates.size()) {
            return;
        }
        // Include current candidate if it's <= target
        if (candidates[ind] <= target) {
            sub.push_back(candidates[ind]);
            recur(ind + 1, candidates, target - candidates[ind], result, sub);
            sub.pop_back();
        }
        // Skip duplicates
        int i = ind;
        while (i + 1 < candidates.size() && candidates[i + 1] == candidates[ind]) {
            i++;
        }
        recur(i + 1, candidates, target, result, sub);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>result;
        vector<int>sub;
        recur(0,candidates,target,result,sub);
        return result;
    }
};