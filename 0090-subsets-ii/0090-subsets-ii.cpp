class Solution {
public:
    void recur(int ind,vector<int>&nums,vector<int>& sub,vector<vector<int>>&result){
        result.push_back(sub);
        for(int i=ind;i<nums.size();i++){
            if(i!=ind and nums[i]==nums[i-1]){
                continue;
            }
            sub.push_back(nums[i]);
            recur(i+1,nums,sub,result);
            sub.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>result;
        vector<int>sub;
        recur(0,nums,sub,result);
        return result;
    }
};