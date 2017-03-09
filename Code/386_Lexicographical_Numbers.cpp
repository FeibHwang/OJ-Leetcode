/*
Given an integer n, return 1 - n in lexicographical order.

For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].

Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000.
*/

/*
consider as tree structure with 10 children:
   1  ..   2   ..
  / \
 10..19 
 
each node has value n, then children is 10*n+0 ~ 10*n+9

pre-travel of the tree is the result;
*/

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for(int i = 1; i < 10; ++i)
        {
            dfs(res,i,n);
        }
        return res;
    }
    
    void dfs(vector<int>& res, int i, int n)
    {
        if(i > n) return;
        
        res.push_back(i);
        for(int k = 0; k < 10; ++k)
        {
            dfs(res,10*i+k,n);
        }
    }
};