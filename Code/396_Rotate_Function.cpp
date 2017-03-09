/*
Given an array of integers A and let n to be its length.

Assume Bk to be an array obtained by rotating the array A k positions clock-wise, we define a "rotation function" F on A as follow:

F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-1) * Bk[n-1].

Calculate the maximum value of F(0), F(1), ..., F(n-1).

Note:
n is guaranteed to be less than 105.

Example:

A = [4, 3, 2, 6]

F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26

So the maximum value of F(0), F(1), F(2), F(3) is F(3) = 26.
*/


/*
After we calculate F(x)

right shift A with 1 digit:
1,2,3  -->  3,1,2

F(x+1) equals to F(x) + sum(A) - A[0]*A.size()

sum(A) is pre calculated
just minus one figure

pay attention to over flow problem


instead of shift, we just iterate each element will be fine
*/


class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        long res = (long)INT_MIN-1;
        long part_sum = 0;
        int cnt = 0;
        long total_sum = 0;
        for(auto i:A) {part_sum += i*(cnt++); total_sum+=i;}
        
        res = max(res,part_sum);
        
        for(int i = A.size()-1; i >= 0; --i)
        {
            part_sum = part_sum + total_sum - ((long)A[i])*A.size();
            res = max(res,part_sum);
        }
        
        if(res < 0) return res >= INT_MIN ? (int)res:INT_MIN;
        return res > INT_MAX ? INT_MAX:(int)res;
    }
    
    
};