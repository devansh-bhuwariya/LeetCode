class MyStack {
public:
    queue<int> q;
    MyStack() {
    }
    
    void push(int x) {
        int s=q.size();
        q.push(x);
        while(s>0){
            int x=q.front();
            q.pop();
            q.push(x);
            s--;
        }
    }
    
    int pop() {
        int n=q.front();
        q.pop();
        return n;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.size()==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */