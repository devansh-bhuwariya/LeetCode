class Solution {
public:
    int mini(int curr_len,int paste_len,int n){
        if(curr_len==n) return 0;
        if(curr_len>n) return INT_MAX-1000;
        int copy=2+mini(curr_len*2,curr_len,n);
        int paste=1+mini(curr_len+paste_len,paste_len,n);
        return min(copy,paste);
    }
    int minSteps(int n) {
        if(n==1) return 0;
        return 1+mini(1,1,n);
    }
};