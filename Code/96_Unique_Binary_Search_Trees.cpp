/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

/*
DP solution:
I fogot the transfer functiuon =_=!
*/

class Solution {
public:
    int numTrees(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        
        
        vector<int> chart(n+1,0);
        chart[1]=1;
        chart[2]=2;
        
        
        for(int i = 3; i <= n; ++i)
        {
            for(int j = 1; j <= i; ++j)
            {
                if(chart[j-1]==0)
                {
                    chart[i] += chart[i-j];
                    continue;
                }
                if(chart[i-j]==0)
                {
                    chart[i] += chart[j-1];
                    continue;
                }
                chart[i] += chart[i-j]*chart[j-1];
                
            }
        }
        return chart[n];
        
    }
};