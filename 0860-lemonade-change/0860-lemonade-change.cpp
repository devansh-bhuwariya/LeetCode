class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> bank={{5,0},{10,0},{20,0}};
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                bank[5]++;
            }else if(bills[i]==10){
                if(bank[5]==0) return false;
                bank[10]++;
                bank[5]--;
            }else if(bills[i]==20){
                if(bank[10]==0 and bank[5]>=3){
                    bank[5]=bank[5]-3;    
                }else if(bank[10]>0 and bank[5]>0){
                    bank[5]--;
                    bank[10]--;
                }else{
                    return false;
                }
                bank[20]++;
            }
        }
        return true;
    }
};