/*
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example:
Given num = 16, return true. Given num = 5, return false.

Follow up: Could you solve it without loops/recursion?
*/


class Solution {
public:
    bool isPowerOfFour01(int num) {
        if(num<4) return num == 1;
        int k = num;
        while(k > 4 && (k & 1)!=1 && (k & 2)!=2)
        {
            k >>= 2;
        }
        return k == 4;
    }

    bool isPowerOfFour(int num) {
        return num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0;
    }
};