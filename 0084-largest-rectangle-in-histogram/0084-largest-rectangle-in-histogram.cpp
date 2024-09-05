class Solution {
public:
    vector<int>nextSmaller(vector<int>arr){
        vector<int>res(arr.size(),arr.size());
        stack<int>st;
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() and arr[st.top()]>=arr[i]){
                st.pop();
            }
            if (!st.empty()) {
                res[i] = st.top();
            }
            st.push(i);
        }
        return res;
    }
    
    vector<int>previousSmaller(vector<int>arr){
        vector<int>res(arr.size(),-1);
        stack<int>st;
        for(int i=0;i<arr.size();i++){
            while(!st.empty() and arr[st.top()]>=arr[i]){
                st.pop();
            }
            if (!st.empty()) {
                res[i] = st.top();
            }
            st.push(i);
        }
        return res;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse=nextSmaller(heights);
        vector<int> pse=previousSmaller(heights);
        int maxArea=INT_MIN;
        for(int i=0;i<heights.size();i++){
            int area=heights[i]*(nse[i]-pse[i]-1);
            maxArea=max(area,maxArea);
        }
        return maxArea;
    }
};