class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int total=0;
        for(int i=0;i<operations.size();i++){
            string s=operations[i];
            if(s[1]=='+'){
                total+=1;
            }else{
                total-=1;
            }
        }
        return total;
    }
};