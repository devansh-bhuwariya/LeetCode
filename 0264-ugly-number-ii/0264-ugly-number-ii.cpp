class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> uglyNumbers;
        uglyNumbers.insert(1);
        long long current=1;
        for(int i=0;i<n-1;i++){
            current=*uglyNumbers.begin();
            uglyNumbers.erase(uglyNumbers.begin());
            uglyNumbers.insert(current*2);
            uglyNumbers.insert(current*3);
            uglyNumbers.insert(current*5);
        }
        return (int)*uglyNumbers.begin();
    }
};