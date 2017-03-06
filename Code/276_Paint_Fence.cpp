/*
There is a fence with n posts, each post can be painted with one of the k colors.

You have to paint all the posts such that no more than two adjacent fence posts have the same color.

Return the total number of ways you can paint the fence.

Note:
n and k are non-negative integers.
*/

/*
A mathmatical problem
*/

class Solution {
public:
    int numWays(int n, int k) {
        if(n==0) return 0;
        if(n==1) return k;
        if(n==2) return k*k;
        int a = k;
        int b = k*k;
        for(int i = 3; i <= n; ++i)
        {
            int c = (k-1) * (a+b);
            a = b;
            b = c;
        }
        return b;
    }
};