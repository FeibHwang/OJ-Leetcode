/*
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
*/

/*
Standard Topological Sort, using dfs
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        unordered_map<int,vector<int>> preq;
        for(auto i:prerequisites) preq[i.first].push_back(i.second);
        bool res = false;
        vector<bool> check(numCourses,false);
        for(int i = 0; i < numCourses; ++i)
        {
            if(!dfs(prerequisites,preq,check,i,0,numCourses)) return false;
        }
        return true;
    }
    
    bool dfs(vector<pair<int, int>>& prerequisites, unordered_map<int,vector<int>>& preq,vector<bool>& check, int checkcnt, int rec_depth, int numCourses)
    {
        if(check[checkcnt]) return true;
        
        if(preq.find(checkcnt)==preq.end()) 
        {
            check[checkcnt] = true;
            return true;
        }
        
        if(rec_depth > numCourses) return false;
        
        for(int i = 0; i < preq[checkcnt].size(); ++i)
        {
            if(!check[preq[checkcnt][i]])
            {
                if(dfs(prerequisites,preq,check,preq[checkcnt][i],rec_depth+1,numCourses)) check[preq[checkcnt][i]] = true;
                else return false;
            }
        }
        return true;
    }
};