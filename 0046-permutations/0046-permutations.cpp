class Solution {
public:
    void recur(vector<int>& nums,vector<vector<int>>& res,vector<int>&sub){
        if(nums.size()==0){
            res.push_back(sub);
            return;
        }
        for(int i=0;i<nums.size();i++){
            vector<int>temp;
            for(int j=0;j<nums.size();j++){
                if(j==i){
                    continue;
                }
                temp.push_back(nums[j]);
            }
            sub.push_back(nums[i]);
            recur(temp,res,sub);
            sub.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>sub;
        recur(nums,res,sub);
        return res;
    }
};