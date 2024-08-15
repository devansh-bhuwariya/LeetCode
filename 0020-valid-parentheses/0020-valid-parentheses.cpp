class Solution {
public:
    bool isValid(string s) {
        if(s[0]==')' or s[0]=='}' or s[0]==']') return false;
        stack<char> st;
        st.push(s[0]);
        for(int i=1;i<s.size();i++){
            if(s[i]=='(' or s[i]=='{' or s[i]=='['){
                st.push(s[i]);
            }else{
                if(st.empty()) return false;
                char ch=st.top();
                if((ch=='(' and s[i]!=')') or (ch=='[' and s[i]!=']') or (ch=='{' and s[i]!='}')) return false;
                st.pop();
            }
        }
        return st.size()==0;
    }
};