class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi=INT_MIN;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                count+=1;
            }else{
                maxi=max(count,maxi);
                count=0;
            }
        }
        maxi=max(count,maxi);
        return maxi;
    }
};