/*
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]

4, [[1,0],[2,0],[3,1],[3,2]]
There are a total of 4 courses to take. 
To take course 3 you should have finished both courses 1 and 2. 
Both courses 1 and 2 should be taken after you finished course 0. 
So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].
*/

/*
Direct topological sort, you can use BFS and DFS 
I use BFS here
I will make a DFS solution later
*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        unordered_map<int,vector<int>> preq;
        for(auto i:prerequisites) preq[i.first].push_back(i.second);
        vector<int> rec;
        vector<bool> checked(numCourses,false);
        for(int i = 0; i < numCourses; ++i)
        {
            if(!bfs(preq,checked,i,0,numCourses,rec)) return {};
        }
        return rec;
    }
    
    bool bfs(unordered_map<int,vector<int>>& preq,vector<bool>& checked,int checkcnt,int depth, int bound,vector<int>& rec)
    {
        if(checked[checkcnt]) return true;
        if(preq.find(checkcnt)==preq.end())
        {
            checked[checkcnt]=true;
            rec.push_back(checkcnt);
            return true;
        }
        if(depth > bound) return false;
        
        for(int i = 0; i < preq[checkcnt].size(); ++i)
        {
            if(!checked[preq[checkcnt][i]]) 
            {
                if(!bfs(preq,checked,preq[checkcnt][i],depth+1,bound,rec)) return false;
            }
            if(i==preq[checkcnt].size()-1) {
                rec.push_back(checkcnt);
                checked[checkcnt]=true;
            }
        }
        return true;
    }
    
};