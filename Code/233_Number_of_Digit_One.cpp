/*
Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

For example:
Given n = 13,
Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.

Hint:

Beware of overflow.
*/

/*
count number of '1' in each digits seperately
deviding a number into two part, left right
i.e
12531 -> 125,31
then number of digits in hundrad can be represented as (125+8)/10*100

+8: a quick way to decide last digit is 0,1,2 and used for calculation

pay attention to the last digit of left,see if it's == to 1
i.e:13123->131,23
then it should add another un-counted 23 '1's
*/

class Solution {
public:
    int countDigitOne(int n) {
        int cnt = 0;
        long long m = 1;
        for(;m<=(long long)n;m*=10)
        {
            int left = n/m; int right = n%m;
            cnt += (left+8)/10*m + (left%10==1) * (right+1);
        }
        return cnt;
    }
};