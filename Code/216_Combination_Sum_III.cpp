/*
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]
*/

/*
standard DFS
*/

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if(k==1)
        {
            if(n<10) return {{n}};
            return {};
        }
        vector<vector<int>> res;
        vector<int> path;
        for(int i = 1; i < 10; ++i)
        {
            if(i > n) break;
            path = {i};
            vector<bool> rec(10,false);
            rec[0] = true; rec[1] = true;
            dfs(rec,path,res,n-i,k);
        }
        return res;
    }
    
    void dfs(vector<bool>& rec, vector<int>& path, vector<vector<int>>& res, int target, int k)
    {
        if(path.size()==k-1)
        {
            if(target > path.back() && target<10 && !rec[target])
            {
                path.push_back(target);
                res.push_back(path);
                path.pop_back();
            }
            return;
        }
        
        for(int i = path.back()+1; i < 10; ++i)
        {
            if(target >= i)
            {
                path.push_back(i);
                rec[i] = true;
                dfs(rec,path,res,target-i,k);
                path.pop_back();
                rec[i] = false;
            }else{
                break;
            }
        }
    }
    
};