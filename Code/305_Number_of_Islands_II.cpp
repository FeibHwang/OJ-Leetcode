/*
A 2d grid map of m rows and n columns is initially filled with water. We may perform an addLand operation which turns the water at position (row, col) into a land. Given a list of positions to operate, count the number of islands after each addLand operation. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example:

Given m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]].
Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).

0 0 0
0 0 0
0 0 0
Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.

1 0 0
0 0 0   Number of islands = 1
0 0 0
Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.

1 1 0
0 0 0   Number of islands = 1
0 0 0
Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.

1 1 0
0 0 1   Number of islands = 2
0 0 0
Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.

1 1 0
0 0 1   Number of islands = 3
0 1 0
We return the result as an array: [1, 1, 2, 3]
*/

/*
Standard DFS
I can do faster =_=!
*/

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& position) {
        vector<vector<int>> grid(m,vector<int>(n,0));
        vector<int> res;
        int cnt = 0;
        for(int i = 0; i <position.size(); ++i)
        {
            cnt++;
            grid[position[i].first][position[i].second] = i+1;
            if(position[i].first > 0 && grid[position[i].first-1][position[i].second]!=0)
            {
                if(grid[position[i].first-1][position[i].second] != i+1)
                {
                cnt--;
                dfs_connect(grid,position[i].first-1,position[i].second,i+1);
                }
            }
            if(position[i].first < m-1 && grid[position[i].first+1][position[i].second]!=0)
            {
                if(grid[position[i].first+1][position[i].second]!=i+1)
                {
                cnt--;
                dfs_connect(grid,position[i].first+1,position[i].second,i+1);
                }
            }
            if(position[i].second > 0 && grid[position[i].first][position[i].second-1]!=0)
            {
                if(grid[position[i].first][position[i].second-1]!=i+1)
                {
                cnt--;
                dfs_connect(grid,position[i].first,position[i].second-1,i+1);
                }
            }
            if(position[i].second < n-1 && grid[position[i].first][position[i].second+1]!=0)
            {
                if(grid[position[i].first][position[i].second+1]!=i+1)
                {
                cnt--;
                dfs_connect(grid,position[i].first,position[i].second+1,i+1);
                }
            }
            res.push_back(cnt);
        }
        return res;
    }
    
    void dfs_connect(vector<vector<int>>& grid, int i, int j, int mark)
    {
        if(grid[i][j] == 0 || grid[i][j]==mark) return;
        
        grid[i][j] = mark;
        if(i>0) dfs_connect(grid,i-1,j,mark);
        if(i<grid.size()-1) dfs_connect(grid,i+1,j,mark);
        if(j>0) dfs_connect(grid,i,j-1,mark);
        if(j<grid[0].size()-1) dfs_connect(grid,i,j+1,mark);
    }
};