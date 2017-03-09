/*
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.

Example 1:
     0          3
     |          |
     1 --- 2    4
Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2.

Example 2:
     0           4
     |           |
     1 --- 2 --- 3
Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]], return 1.

Note:
You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
*/

/*
DFS, using an array to record the discovered node
*/

class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        unordered_map<int,vector<int>> mp;
        vector<bool> rec(n,false);
        
        for(int i = 0; i < edges.size(); ++i)
        {
            mp[edges[i].first].push_back(edges[i].second);
            mp[edges[i].second].push_back(edges[i].first);
        }
        
        int res = 0;
        for(int i = 0; i < n; ++i)
        {
            if(!rec[i])
            {
                res++;
                dfs_mark(rec,mp,i);
            }
        }
        return res;
    }
    
    void dfs_mark(vector<bool>& rec, unordered_map<int,vector<int>>& mp, int i)
    {
        if(rec[i]) return;
        rec[i] = true;
        for(int j = 0; j < mp[i].size(); ++j)
        {
            dfs_mark(rec,mp,mp[i][j]);
        }
        return;
    }
};