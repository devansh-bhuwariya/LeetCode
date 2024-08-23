class Solution {
public:
    long long count=0;
    void merge(vector<int>& nums,int low,int mid,int high){
        int right=mid+1;
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
    }
    
    void mergeSort(vector<int>& nums,int low,int high){
        if(low<high){
            int mid=(low+high)/2;
            mergeSort(nums,low,mid);
            mergeSort(nums,mid+1,high);
            merge(nums,low,mid,high);
        }
    }
    
    int reversePairs(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return count;
    }
};