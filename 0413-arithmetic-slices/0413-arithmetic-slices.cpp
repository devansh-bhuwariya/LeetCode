class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()<3){
            return 0;
        }
        int count=0;
        for(int i=0;i<=nums.size()-3;i++){
            int diff=nums[i+1]-nums[i];
            if(nums[i+2]-nums[i+1]!=diff){
                continue;
            }else{
                count++;
                int j=i+2;
                while(j<nums.size()-1){
                    if(nums[j+1]-nums[j]!=diff){
                        break;
                    }else{
                        count++;
                        j++;
                    }
                }
            }
            
        }
        return count;
        
    }
};