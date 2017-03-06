/*
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.
*/

/*
count how many 5/25/125...
*/

class Solution {
public:
    int trailingZeroes(int n) {
        int sum = 0;
        for(;n;n/=5) sum += n/5;
        return sum;
    }
};