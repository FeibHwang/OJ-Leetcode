/*
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.
*/

/*
simply modification
*/

class Solution {
public:
    int totalNQueens(int n) {
        int cnt = 0;
        vector<string> path(n,string(n,'.'));
        dfs(cnt,path,0,n);
        return cnt;
    }
    
    void dfs(int &res, vector<string>& path, int line, int n)
    {
        for(int i = 0; i < n; ++i)
        {
            if(check(path,line,i,n))
            {
                path[line][i] = 'Q';
                if(line==n-1)
                {
                    res+=1;
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