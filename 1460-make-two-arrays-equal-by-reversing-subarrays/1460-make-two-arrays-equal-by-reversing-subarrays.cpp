class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int i=0;i<target.size();i++){
            mp[target[i]]++;
        }
        for(int i=0;i<arr.size();i++){
            if(mp[arr[i]]==0){
                return false;
            }
            mp[arr[i]]--;
        }
        return true;
    }
};