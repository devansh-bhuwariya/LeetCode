class Solution {
public:
    bool isPalindrome(string s, int start,int end){
        while(start<=end){
            if(s[start]!=s[end]){
                return false;
            }
            start+=1;
            end-=1;
        }
        return true;
    }
    void recur(int ind,string s,vector<string>& sub,vector<vector<string>>& result){
        if(ind==s.size()){
            result.push_back(sub);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(isPalindrome(s,ind,i)){
                sub.push_back(s.substr(ind,i-ind+1));
                recur(i+1,s,sub,result);
                sub.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string>sub;
        recur(0,s,sub,result);
        return result;
    }
};