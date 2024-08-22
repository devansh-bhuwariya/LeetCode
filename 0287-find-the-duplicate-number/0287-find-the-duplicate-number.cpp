class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0];
        int fast=nums[0];
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);
        int i=nums[0];
        while(i!=slow){
            slow=nums[slow];
            i=nums[i];
        }
        return i;
    }
};