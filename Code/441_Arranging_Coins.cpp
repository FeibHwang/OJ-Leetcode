/*
Arranging Coins
You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.

Given n, find the total number of full staircase rows that can be formed.

n is a non-negative integer and fits within the range of a 32-bit signed integer.

Example 1:

n = 5

The coins can form the following rows:
¤
¤ ¤
¤ ¤

Because the 3rd row is incomplete, we return 2.
Example 2:

n = 8

The coins can form the following rows:
¤
¤ ¤
¤ ¤ ¤
¤ ¤

Because the 4th row is incomplete, we return 3.
*/

/*
binary search

or also you could solve the equasion directly
*/


class Solution {
public:
    int arrangeCoins(int n) {
        if(n==0) return 0;
        int l = 0;
        int r = n/2;
        long mid = (l + r) / 2;
        while(l <= r)
        {
            mid = (l + r) / 2;
            if((mid*(mid+1)/2 <= (long)n) && ((mid+1)*(mid+2)/2 > (long)n)) return mid;
            
            if(mid*(mid+1)/2 < (long)n) l = mid+1;
            else r = mid-1;
        }
        return mid+1;
    }
};