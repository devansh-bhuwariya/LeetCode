class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> sym;
        int sum=0;
        sym['M']=1000;
        sym['D']=500;
        sym['C']=100;
        sym['L']=50;
        sym['X']=10;
        sym['V']=5;
        sym['I']=1;
        int prev=0;
        for(int i=s.length()-1;i>=0;i--){
            if(sym[s[i]]>=prev){
                sum=sum+sym[s[i]];
            }else{
                sum=sum-sym[s[i]];
            }
            prev=sym[s[i]];
        }
        return sum;
    }
};