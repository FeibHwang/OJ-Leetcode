/*
Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.

Example:

Input:
[1,2,3]

Output:
3

Explanation:
Only three moves are needed (remember each move increments two elements):

[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
*/

/*
instead of thinking adding n-1 with 1, we minus one element with 1
until every element is equal to the smallest one
so res = sum(nums - smallest_elemt)
*/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int lower = INT_MAX;
        for(auto i : nums) lower = min(i,lower);
        int res = 0;
        for(auto i : nums) res += (i-lower);
        return res;
    }
};