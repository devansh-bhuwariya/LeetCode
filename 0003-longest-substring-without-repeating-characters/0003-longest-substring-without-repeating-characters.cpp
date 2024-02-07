class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int previous=0;
        for(int i=0;i<s.length();i++){
            unordered_map<char,int> m;
            int current=0;
            for(int j=i;j<s.length();j++){
                if(m[s[j]]<1){
                    m[s[j]]++;
                    current++;
                }else{
                    break;
                }
            }
            previous=max(previous,current);
        }
        return previous;
    }
};