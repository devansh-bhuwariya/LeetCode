class Solution {
public:
    int merge(vector<int>& nums,int low,int mid,int high){
        int right=mid+1;
        int count=0;
        for(int left=low;left<=mid;left++){
            while(right<=high and nums[left]>2LL*nums[right]){
                right++;
            }
            count+=right-(mid+1);
        }
        int i=low;
        int j=mid+1;
        vector<int>temp;
        while(i<=mid and j<=high){
            if(nums[i]<=nums[j]){
                temp.push_back(nums[i]);
                i++;
            }else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j<=high){
            temp.push_back(nums[j]);
            j++;
        }
        for(int i=low,j=0;i<=high;i++){
            nums[i]=temp[j];
            j++;
        }
        return count;
    }
    
    int mergeSort(vector<int>& nums,int low,int high){
        int count=0;
        if(low<high){
            int mid=(low+high)/2;
            count+=mergeSort(nums,low,mid);
            count+=mergeSort(nums,mid+1,high);
            count+=merge(nums,low,mid,high);
        }
        return count;
    }
    
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
        
    }
};