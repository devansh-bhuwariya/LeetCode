class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int temp=x;
        long long rev=0;
        int n;
        while(x>0){
            n=x%10;
            rev=rev*10+n;
            x=x/10;
        }
        if(rev==temp){
            return true;
        }else{
            return false;
        }
    }
};