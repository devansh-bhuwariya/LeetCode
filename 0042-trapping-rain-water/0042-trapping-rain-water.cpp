class Solution {
public:
    int trap(vector<int>& height) {
        int len=height.size();
        int total=0;
        int prefixMax[len];
        int sufixMax[len];
        prefixMax[0]=height[0];
        sufixMax[len-1]=height[len-1];
        for(int i=1;i<len-1;i++){
            prefixMax[i]=max(prefixMax[i-1],height[i]);
        }
        for(int i=len-2;i>=0;i--){
            sufixMax[i]=max(sufixMax[i+1],height[i]);
        }
        for(int i=0;i<len-1;i++){
            total+=min(prefixMax[i],sufixMax[i])-height[i];
        }
        return total;
    }
};