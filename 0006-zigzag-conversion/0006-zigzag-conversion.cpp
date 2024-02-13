class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<=1 || s.length()<numRows){
            return s;
        }
        vector<vector<char>> a(numRows, vector<char>(s.length(), ' '));
        int r=0;
        int direction=1;
        string temp="";
        for(int i=0;i<s.length();i++){
            a[r][i]=s[i];
            if(r==0){
                direction=1;
            }else if( r==numRows-1){
                direction=-1;
            }
            r=r+direction;
        }
        for(int i=0;i<numRows;i++){
            for(int j=0;j<s.length();j++){
                if(a[i][j]!=' '){
                    temp=temp+a[i][j];
                }
            }
        }
        return temp;
    }
};