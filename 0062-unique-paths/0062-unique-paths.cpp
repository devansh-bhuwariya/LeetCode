class Solution {
public:
    
    long long nCr(int m,int n){
        long long ans=1;
        for(int i=1;i<=n;i++){
            ans*=(m-(i-1));
            ans/=i;
        }
        return ans;
    }
    
    int uniquePaths(int m, int n) {
        int steps=(m-1)+(n-1);
        int choose=min(m-1,n-1);
        return nCr(steps,choose);
    }
};