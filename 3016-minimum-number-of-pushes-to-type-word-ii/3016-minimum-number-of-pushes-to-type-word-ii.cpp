class Solution {
public:
    bool static comparator(pair<char,int> c1,pair<char,int> c2){
        return c1.second>c2.second;
    }
    int minimumPushes(string word) {
        int count=0;
        int add=1;
        int keys=0;
        map<char,int> chars;
        for(int i=0;i<word.size();i++){
            chars[word[i]]+=1;
        }
        vector<pair<char, int>> freq(chars.begin(), chars.end());
        sort(freq.begin(),freq.end(),comparator);
        for(auto it=freq.begin();it!=freq.end();it++){
            if(keys<8){
                count+=add*it->second;
                keys+=1;
            }else{
                keys=1;
                add=add+1;
                count+=add*it->second;
            }
        }
        
        return count;
    }
};

