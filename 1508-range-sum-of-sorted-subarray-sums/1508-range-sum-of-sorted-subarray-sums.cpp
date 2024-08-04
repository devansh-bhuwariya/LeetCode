class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long> sums;
        long long total=0;
        for(int i=0;i<nums.size();i++){
            long long sum=0;
            for(int j=i;j<nums.size();j++){
                sum+=nums[j];
                sums.push_back(sum);
            }
        }
        sort(sums.begin(),sums.end());
        for(int i=left-1;i<right;i++){
            total+=sums[i];
        }
        return total%1000000007;
    }
};