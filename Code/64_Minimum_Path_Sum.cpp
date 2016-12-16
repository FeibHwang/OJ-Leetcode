/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/


/*
typical DP
transfer function: record[i,j] = min(record[i-1,j], record[i,j-1]) + grid[i,j]
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid[0].empty()) return 0;
        //if(grid.size()==1) return accumulate(grid[0].begin(),grid[0].end(),0);
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> record(m,vector<int>(n));
        
        record[0][0] = grid[0][0];
        
        int cnt_line = 1, cnt_row = 1;
        
        for(int i = 1; i < n; ++i) record[0][i] = record[0][i-1] + grid[0][i];
        for(int i = 1; i < m; ++i) record[i][0] = record[i-1][0] + grid[i][0];
        
        if(m==1 || n==1) return record[m-1][n-1]; 
        
        int cnt = ((m>n) ? n : m) - 1;
        int start = 1;
        
        while(start <= cnt)
        {
            for (int i = start; i < n; ++i)
			record[start][i] = ((record[start][i - 1]<record[start - 1][i]) ? record[start][i - 1] : record[start - 1][i]) + grid[start][i];
		    for (int i = start; i < m; ++i)
			record[i][start] = ((record[i - 1][start]<record[i][start - 1]) ? record[i - 1][start] : record[i][start - 1]) + grid[i][start];
		    start++;
        }
        
        return record[m-1][n-1];
    }
};