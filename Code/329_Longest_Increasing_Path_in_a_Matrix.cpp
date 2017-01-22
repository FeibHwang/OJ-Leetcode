/*
Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

nums = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
Return 4
The longest increasing path is [1, 2, 6, 9].

Example 2:

nums = [
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
Return 4
The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
*/

/*
DFS + DP

using dfs search for every possible answer, record the searched point to avoid research
*/

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty()||matrix[0].empty()) return 0;
        rec = matrix;
        for(int i = 0; i < matrix.size(); ++i)
        {
            for(int j = 0; j < matrix[0].size(); ++j)
            {
                rec[i][j]=0;
            }
        }
        line = matrix.size();
        row = matrix[0].size();
        vector<vector<int>> rec(line,vector<int>(row,0));
        
        for(int i = 0; i < matrix.size(); ++i)
        {
            for(int j = 0; j < matrix[0].size(); ++j)
            {
                if(rec[i][j]==0) dfs(matrix,i,j);
            }
        }
        return res;
    }
    
private:
    int path = 0;
    int res = 0;
    vector<vector<int>> rec;
    
    
    int line;
    int row;
    
    int dfs(vector<vector<int>>& matrix, int l, int r)
    {
        int target = matrix[l][r];
        if(rec[l][r]>0) return rec[l][r];
        
        int a=1,b=1,c=1,d=1;
        
        if(l>0 && matrix[l-1][r] > target) a = 1+dfs(matrix,l-1,r);
        
        if(l<(line-1) && matrix[l+1][r] > target) b = 1+dfs(matrix,l+1,r);
        
        if(r>0 && matrix[l][r-1] > target) c = 1+dfs(matrix,l,r-1);
        
        if(r<(row-1) && matrix[l][r+1] > target) d = 1+dfs(matrix,l,r+1);
        
        path = max(max(a,b), max(c,d));
        res = max(res,path);
        rec[l][r] = path;
        return path;
    }
};