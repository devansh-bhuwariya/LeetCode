int sym(char c){
    switch(c){
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
    }
    return 0;
}
class Solution {
public:
    int romanToInt(string s) {
        int sum=0;
        int prev=0;
        for(int i=s.length()-1;i>=0;i--){
            // int val=sym(s[i]);
            if(sym(s[i])>=prev){
                sum=sum+sym(s[i]);
            }else{
                sum=sum-sym(s[i]);
            }
            prev=sym(s[i]);
        }
        return sum;
    }
};