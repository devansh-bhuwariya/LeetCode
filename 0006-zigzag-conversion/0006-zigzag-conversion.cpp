class Solution {
public:
    string convert(string s, int numRows) {
        if(s.length()<numRows || numRows<=1){
            return s;
        }
        string temp="";
        vector<string> rows(min(numRows,int(s.length())));
        int direction=1;
        int curr_row=0;
        for(int i=0;i<s.length();i++){
            rows[curr_row]=rows[curr_row]+s[i];
            if(curr_row==0){
                direction=1;
            }else if(curr_row==numRows-1){
                direction=-1;
            }
            curr_row+=direction;
        }
        for(int i=0;i<min(numRows,int(s.length()));i++){
            temp=temp+rows[i];
        }
        return temp;
    }
};