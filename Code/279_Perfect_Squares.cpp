/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
*/

/*
classic DP question
*/

class Solution {
public:
    int numSquares(int n) {
        vector<int> sqr(n+1,0);
        sqr[1]=1;
        for(int i = 2; i<=n; ++i)
        {
            int minsum = INT_MAX;
            int j = 1;
            while(j*j<=i)
            {
                if(j*j==i) 
                { minsum = 1;break;}
                minsum = min(minsum,sqr[i-j*j]+1);
                ++j;
            }
            sqr[i]=minsum;
        }
        return sqr[n];
        
    }
};