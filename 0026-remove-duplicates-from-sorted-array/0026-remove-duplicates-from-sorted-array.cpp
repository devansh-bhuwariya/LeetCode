class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=0;
        int i=0;
        while(i<nums.size()){
            if(nums[i]==nums[k]){
                i++;
            }else{
                swap(nums[i],nums[k+1]);
                k++;
                i++;
            }
        }
        return k+1;
    }
};