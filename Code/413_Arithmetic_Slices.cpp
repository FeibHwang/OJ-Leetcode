/*
A sequence of number is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, these are arithmetic sequence:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
The following sequence is not arithmetic.

1, 1, 2, 5, 7

A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.

A slice (P, Q) of array A is called arithmetic if the sequence:
A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.

The function should return the number of arithmetic slices in the array A.


Example:

A = [1, 2, 3, 4]

return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.
*/



/*
Simplier than I imagin
the question is equal to ask is any 3-element subarray can form Arithmetic Slices
i.e:
1,2,3,5,6,7,9,10,11

only count: [1,2,3],[5,6,7],[9,10,11]
don't count: [1,5,9],[2,6,10],[3,7,11]
*/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int res = 0;
        int cnt = 0;
        for(int i = 2; i < A.size(); ++i)
        {
            if(A[i]-A[i-1]==A[i-1]-A[i-2])res += ++cnt;
            else cnt = 0;
        }
        return res;
    }
};