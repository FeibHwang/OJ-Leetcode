/*
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

For example:

Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.

Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.

Hint:

Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], what should your return? Is this case a valid tree?
According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”
Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
*/

/*
BFS solution:
if iterating times is larger than the node number, then there is loop
after literation, if not all nodes have been visited, thn there is individual tree
*/

class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        unordered_map<int,vector<int>> mp;
        for(int i = 0; i < edges.size(); ++i)
        {
            mp[edges[i].first].push_back(edges[i].second);
            mp[edges[i].second].push_back(edges[i].first);
        }
        
        queue<int> que;
        que.push(0);
        vector<bool> check(n,false);
        vector<int> hold;
        int bef = -1;
        while(!que.empty())
        {
            int thy = que.front(); que.pop();
            if(check[thy]) return false;
            for(int i = 0; i < mp[thy].size(); ++i)
            {
                if(mp[thy][i]!=bef) hold.push_back(mp[thy][i]);
            }
            if(que.empty())
            {
                while(hold.size()>0)
                {
                    que.push(hold.back());
                    hold.pop_back();
                }
                bef = thy
            }
            
        }
    }
    
};