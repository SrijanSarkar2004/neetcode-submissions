class Solution {
public:
    int getSum(int a, int b) {
        int cur = 0, pos = 0, sum = 0;
        for(int pos=0;pos<32;pos++){
            int x = a & 1;
            int y = b & 1;

            sum |= (x ^ y ^ cur) << pos;
            cur = (x & y) || (x & cur) || (y & cur);
            a>>=1;
            b>>=1;
        }


        return sum;
    }
};