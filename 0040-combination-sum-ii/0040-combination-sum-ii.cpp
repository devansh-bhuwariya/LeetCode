class Solution {
public:
    
    void recur(int ind,vector<int>& candidates,int target,vector<vector<int>>& res,vector<int>& sub){
        if(target==0){
            res.push_back(sub);
            return ;
        }
        for(int i=ind;i<candidates.size();i++){
            if(i!=ind and candidates[i]==candidates[i-1]){
                continue;
            }
            if(candidates[i]<=target){
                sub.push_back(candidates[i]);
                recur(i+1,candidates,target-candidates[i],res,sub);
                sub.pop_back();
            }
        }
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>res;
        vector<int>sub;
        recur(0,candidates,target,res,sub);
        return res;
    }
};