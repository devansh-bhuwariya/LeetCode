class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0 and nums[i]==nums[i-1]) continue;
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<0){
                    j++;
                }else if(sum>0){
                    k--;
                }else{
                    vector<int>temp={nums[i],nums[j],nums[k]};
                    result.push_back(temp);
                    j++;
                    k--;
                    while(nums[j]==nums[j-1] and j<k){
                        j++;
                    }
                    while(nums[k]==nums[k+1] and j<k){
                        k--;
                    }
                }
            }
        }
        return result;
    }
};