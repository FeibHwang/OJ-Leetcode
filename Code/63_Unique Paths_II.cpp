/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.
*/

/*
due to the constrine, we need to get rid of special cases:
if matrix[0,0] = 1, there is no way
if matrix only has 1 line or row, if there is 1, there is no way
Then use DP
transfer function matrix[i,j] = matrix[i,j-1]*(obstacleGrid[i,j-1]==1?0:1) + matrix[i-1,j]*(obstacleGrid[i-1,j]==1?0:1)
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty()) return 0;
        if(obstacleGrid[0].empty()) return 0;
        if(obstacleGrid.size()==1 ) 
        {
            if(find(obstacleGrid[0].begin(),obstacleGrid[0].end(),1)==obstacleGrid[0].end()) return 1;
            else return 0;
        }
        
        
        if(obstacleGrid[0].size()==1)
        {
            vector<int> tmp = {1};
            if(find(obstacleGrid.begin(),obstacleGrid.end(),tmp)==obstacleGrid.end()) return 1;
            else return 0;
        }
        
        if(obstacleGrid[0][0]==1) return 0;
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<vector<int>> record(m,vector<int>(n));
        
        record[0][0]=1;
        
        for(int i = 1; i < n; ++i) record[0][i] = (obstacleGrid[0][i]==0 && record[0][i-1]==1)?1:0;
        for(int i = 1; i < m; ++i) record[i][0] = (obstacleGrid[i][0]==0 && record[i-1][0]==1)?1:0;
        
        int cnt = ((m>n) ? n : m) - 1;
        int start = 1;
        
        while(start <= cnt)
        {
            for (int i = start; i < n; ++i)
			record[start][i] = (obstacleGrid[start][i]==0)?(record[start - 1][i] + record[start][i-1]):0;
		    for (int i = start; i < m; ++i)
			record[i][start] = (obstacleGrid[i][start]==0)?(record[i][start - 1] + record[i-1][start]):0;
		    start++;
        }
        
        return record[m-1][n-1];
    }
};