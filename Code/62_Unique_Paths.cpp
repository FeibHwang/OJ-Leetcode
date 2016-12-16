/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
*/

/*
DP is the easist way to think of
construct a new matrix with same size
each item is the unit path to the same position
for line 1 and row 1, there is only one way
transfer function: record[i,j] = record[i-1,j]+record[i,j-1]
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==0 || n==0) return 0;
        if(m==1 || n==1) return 1;
        
        vector<vector<int>> record(m,vector<int>(n));
        
        for(int i = 1; i < n; ++i) record[0][i] = 1;
        for(int i = 1; i < m; ++i) record[i][0] = 1;
        
        int cnt = ((m>n) ? n : m) - 1;
        int start = 1;
        
        while(start <= cnt)
        {
            for (int i = start; i < n; ++i)
			record[start][i] = record[start - 1][i] + record[start][i-1];
		    for (int i = start; i < m; ++i)
			record[i][start] = record[i][start - 1] + record[i-1][start];
		    start++;
        }
        
        return record[m-1][n-1];
    }
};