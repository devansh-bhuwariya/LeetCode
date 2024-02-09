class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> hist;
        while(hist[n]!=1){
            hist[n]++;
            int sum=0;
            while(n>0){
                sum=sum+pow((n%10),2);
                n=n/10;
            }
            n=sum;
        }
        if(n==1){
            return true;
        }
        else{
            return false;
        }
    }
};