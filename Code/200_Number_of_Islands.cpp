/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3
*/

/*
BFS
once find a '1', change all connected '1' into '2'
remember to search 4 direction
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        if(grid[0].empty()) return 0;
        int res = 0;
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[0].size(); ++j)
            {
                if(grid[i][j]=='1')
                {
                    res++;
                    search_change(grid,i,j);
                }
            }
        }
        return res;
    }
    
    void search_change(vector<vector<char>>& grid, int i, int j)
     {
    	 if (i >= 0 && i < grid.size() && j>=0 && j < grid[0].size() && grid[i][j] == '1')
    	 {
    		 grid[i][j] = '2';
    		 search_change(grid, i + 1, j);
    		 search_change(grid, i, j + 1);
    		 search_change(grid, i - 1, j);
    		 search_change(grid, i, j - 1);
    	 }
    	 else return;
     }
    
};