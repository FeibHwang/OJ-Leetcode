/*
Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.

Note that 1 is typically treated as an ugly number.
*/

/*
there might be a more efficient way
*/

class Solution {
public:
    bool isUgly(int num) {
        if(num<=0) {return false;}
        int remain = 0;
        int start = num;
        while(remain == 0)
        {
            if(start == 1) return true;
            if(start % 2==0) start /= 2;
            else if(start % 3==0) start /= 3;
            else if(start % 5==0) start /= 5;
            else return false;
            
            
        }
        return false;
    }
};