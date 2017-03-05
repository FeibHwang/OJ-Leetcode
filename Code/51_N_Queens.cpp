/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/

/*
Straight forward DFS, try every possible combinations
*/

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> path(n,string(n,'.'));
        dfs(res,path,0,n);
        return res;
    }
    
    void dfs(vector<vector<string>> &res, vector<string>& path, int line, int n)
    {
        for(int i = 0; i < n; ++i)
        {
            if(check(path,line,i,n))
            {
                path[line][i] = 'Q';
                if(line==n-1)
                {
                    res.push_back(path);
                    path[line][i]='.';
                    break;
                }else{
                    dfs(res,path,line+1,n);
                }
                path[line][i]='.';
            }
        }
    }
    
    bool check(vector<string>& path, int line, int row, int n)
    {
        for(int i = 0; i < n; ++i) if(path[i][row]=='Q'&&i!=line) return false;
        for(int i = 0; i < n; ++i) if(path[line][i]=='Q'&&i!=row) return false;
        for(int i = 1; i < n; ++i)
        {
            if(line+i<n && row+i<n &&path[line+i][row+i]=='Q') return false;
            if(line-i>=0 && row+i<n && path[line-i][row+i]=='Q') return false;
            if(line-i>=0 && row-i>=0 && path[line-i][row-i]=='Q') return false;
            if(line+i<n && row-i>=0 && path[line+i][row-i]=='Q') return false;
        }
        return true;
    }
};