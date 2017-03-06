/*
You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

For example, given the 2D grid:
INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
After running your function, the 2D grid should be:
  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4

*/

/*
Standard DFS/BFS
*/

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int depth = 0;
        for(int i = 0; i < rooms.size(); ++i)
        {
            for(int j = 0; j < rooms[0].size(); ++j)
            {
                if(rooms[i][j]==0)
                {
                    DFS(rooms,i+1,j,depth+1);
                    DFS(rooms,i,j+1,depth+1);
                    DFS(rooms,i-1,j,depth+1);
                    DFS(rooms,i,j-1,depth+1);
                }
            }
        }
    }
    
    void DFS(vector<vector<int>>& rooms, int i, int j, int depth)
    {
        if(i<0 || i > rooms.size()-1 || j < 0 || j > rooms[0].size()-1 || rooms[i][j] == -1)
        {
            return;
        }
        
        if(rooms[i][j]>depth) 
        {
            rooms[i][j] = depth;
            DFS(rooms,i+1,j,depth+1);
            DFS(rooms,i,j+1,depth+1);
            DFS(rooms,i-1,j,depth+1);
            DFS(rooms,i,j-1,depth+1);
        }
    }
    
};