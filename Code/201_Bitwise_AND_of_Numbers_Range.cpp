/*
Given a range [m, n] where 0 <= m <= n <= 2147483647, 
return the bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.
*/


/*
if 2 number are different, then sinc there is a range, the last bot is ddiferent, 
therefor it's 0, by compare each bit, the result can compute 
*/

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m==0) return 0;
        int movefactor = 1;
        while(m!=n)
        {
            m>>=1;
            n>>=1;
            movefactor<<=1;
        }
        return m * movefactor;
    }
};