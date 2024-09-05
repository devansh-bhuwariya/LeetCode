class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea=INT_MIN;
        for(int i=0;i<heights.size();i++){
            while(!st.empty() and heights[st.top()]>heights[i]){
                int x=st.top();
                st.pop();
                int pse=(!st.empty())?st.top():-1;
                int area=heights[x]*(i-pse-1);
                maxArea=max(area,maxArea);
            }
            st.push(i);
        }
        while(!st.empty()){
            int x=st.top();
            st.pop();
            int pse=(!st.empty())?st.top():-1;
            int area=heights[x]*(heights.size()-pse-1);
            maxArea=max(area,maxArea);
        }
        return maxArea;
    }
};