/*
You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

Example:

[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Answer: 16
Explanation: The perimeter is the 16 yellow stripes in the image below:
*/


/*
the usual connection is 2 + 2*square, if 4 square connect as a new square:
_____
|_|_|
|_|_|
the result will minus 2
so counting the total number of square and the number of big square above
final perimeter = 2 + 2* square - 2*big_square
*/

class Solution {
public:


    int islandPerimeter(vector<vector<int>>& grid) {
        int cross = 0;
        if(grid.size()>1 && grid[0].size()>1)
        {
            for(int i = 0; i < grid.size()-1; ++i)
            {
                for(int j = 0; j < grid[0].size()-1; ++j)
                {
                    if(grid[i][j] == 1 && grid[i][j+1]==1 && grid[i+1][j]==1 && grid[i+1][j+1]==1) cross++;
                }
            }
        }
        
        int res = 0;
        for(int i = 0; i < grid.size(); ++i)
            {
                for(int j = 0; j < grid[0].size(); ++j)
                {
                    res += grid[i][j];
                }
            }
            
        return 2 + 2*res - 2*cross;
        
    }
    
    
};