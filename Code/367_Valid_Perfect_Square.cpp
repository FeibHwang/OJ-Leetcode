/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Returns: True
Example 2:

Input: 14
Returns: False
*/

/*
binary search
use long to avoid overflow
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==0) return false;
        if(num==1) return 1;
        if(num > 2147395600) return false;
        
        long head=1, tail=num/2;
        long x = num;
        
        while(head<=tail)
        {
            if(head*head==x) return true;
            if(tail*tail==x) return true;
            if((head+(tail-head)/2)*(head+(tail-head)/2) == x) return true;
            else if ((head+(tail-head)/2)*(head+(tail-head)/2) > x) tail = head + (tail-head)/2 - 1;
            else head = head+(tail-head)/2 + 1;
        }
        return false;
    }
};

//max 2 147 395 600