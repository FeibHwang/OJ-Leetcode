/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/

/*
look out for corner cases
sign bit
*/

class Solution {
public:
    int reverse(int x) {
        if(x<10&&x>=0) return x;
        long sign = x<0 ? -1 : 1;
        vector<long> rec;
        long cct = abs(long(x));
        while(cct!=0)
        {
            rec.push_back(cct%10);
            cct = cct/10;
        }
        for(int i = 0; i < rec.size(); ++i)
        {
            cct = 10*cct+rec[i];
        }
        if(cct > (long)INT_MAX && sign == 1) return 0;
        if(cct > (long)INT_MAX+1 && sign == -1) return 0;
        return sign*(int)cct;
    }
};