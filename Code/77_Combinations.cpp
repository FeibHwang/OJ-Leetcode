/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

/*
DFS with deque
deque can push value front/ back, easy to generate next combination
*/

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if(k>n) return res;
        
        vector<deque<int>> tmp = dfs(n,k,1);
        for(int l = 0; l < tmp.size(); ++l)
        {
            res.push_back(vector<int>(tmp[l].begin(),tmp[l].end()));
        }

        return res;
    }
    
    vector<deque<int>> dfs(int n, int k, int i)
    {
        vector<deque<int>> res;
        
        if(k==1)
        {
            for(int j = i; j <= n; ++j)
            {
                deque<int> t;
                t.push_back(j);
                res.push_back(t);
            }
            return res;
        }
        
        for(int j = i; j <= n-k+2; ++j)
        {
            vector<deque<int>> tmp = dfs(n,k-1,j+1);
            for(int l = 0; l < tmp.size(); ++l)
            {
                tmp[l].push_front(j);
                res.push_back(tmp[l]);
            }
        }
        return res;
    }
};