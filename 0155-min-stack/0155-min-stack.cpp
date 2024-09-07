class MinStack {
private:
    long long mini;
    stack<long long>st;
public:
    
    MinStack() {
        mini=INT_MAX;
    }
    
    void push(int val) {
        if(st.empty()){
            mini=val*1LL;
            st.push(val*1LL);
        }else{
            if(val<mini){
                st.push(2LL*val-mini);
                mini=val;
            }else{
                st.push(val);
            }
        }
    }
    
    void pop() {
        if(st.empty()) return ;
        long long x=st.top();
        st.pop();
        if(x<mini){
            mini=2LL*mini-x;
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        if(mini>st.top()){
            return mini;
        }
        return st.top();
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */