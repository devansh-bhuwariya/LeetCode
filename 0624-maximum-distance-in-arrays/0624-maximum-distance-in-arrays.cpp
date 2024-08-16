class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int small=arrays[0][0];
        int big=arrays[0].back();
        int diff=INT_MIN;
        for(int i=1;i<arrays.size();i++){
            diff=max(diff,abs(small-arrays[i].back()));
            diff=max(diff,abs(big-arrays[i][0]));
            small=min(small,arrays[i][0]);
            big=max(big,arrays[i].back());
        }
        return diff;
    }
};