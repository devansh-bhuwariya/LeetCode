class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int n=arr.size();
        int distinct=0;
        for(int i=0;i<n;i++){
            if(count(arr.begin(),arr.end(),arr[i])==1){
                distinct+=1;
            }
            if(distinct==k){
                return arr[i];
            }
        }
        return "";
    }
};