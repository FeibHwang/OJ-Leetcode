/*
Given an integer, write a function to determine if it is a power of two.
*/

/*
keep deviding by 2, until 2/1
insteat divide, use shift instead
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        int k = n;
        if(k == 1 || k == 2) {return true;}
        while(k > 0)
        {
            if(((k>>1)<<1)!=k){return false;}
            k = k>>1;
            if(k == 2)
            {
                return true;
            }
        }
        return false;
    }
};