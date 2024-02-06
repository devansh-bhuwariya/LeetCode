class Solution {
public:
    string defangIPaddr(string address) {
        string s;
        for(int i=0;i<address.length();i++){
            // 48   57
            if((int)address[i]>=48 && (int)address[i]<=57){
                s.push_back(address[i]);
            }else{
                s.push_back('[');
                s.push_back('.');
                s.push_back(']');
            }
        }
        return s;
    }
};