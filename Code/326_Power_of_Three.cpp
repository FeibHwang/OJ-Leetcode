/*
Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion?
*/

/*
same to power of two
*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) {return false;}
        if(n == 1 || n == 3) {return true;}
        int k = n;
        while(k > 0)
        {
            if(k % 3 == 1 || k % 3 == 2){return false;}
            k /= 3;
            if(k == 3)
            {
                return true;
            }
        }
        return false;
        
    }
};