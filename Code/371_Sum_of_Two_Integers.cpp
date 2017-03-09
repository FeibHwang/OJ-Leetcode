/*
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.
*/

/*
bit manipulation, simulate the full adder
*/

class Solution {
public:
    int getSum(int a, int b) {
        int c = 0, s = 0;
        for(int i = 0; i < 32; ++i)
        {
            int abit = a>>i;
            int bbit = b>>i;
            s |= ((abit&1)^(bbit&1)^c)<<i;
            c = ((abit&1)&(bbit&1))|((abit&1)&c)|((bbit&1)&c);
            
        }
        return s;
    }
};