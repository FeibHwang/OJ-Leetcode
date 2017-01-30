/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

/*
generate one circle at a time
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n==0) return {};
        if(n==1) return {{1}};
        vector<vector<int>> res(n,vector<int>(n,0));
        for(int i = 0; i < n/2; ++i)
        {
            onepass(res,i);
        }
        if(n%2==1) res[n/2][n/2] = res[n/2][n/2-1]+1;
        return res;
    }
    
    void onepass(vector<vector<int>> &res,int i)
    {
        int val;
        if(i==0) val = 1;
        else val = res[i][i-1]+1;
        for(int line = i; line < res[0].size()-i-1; ++line)
        {
            res[i][line] = val++;
        }
        for(int row = i; row < res.size()-i-1; ++row)
        {
            res[row][res.size()-i-1] = val++;
        }
        for(int line = res.size()-i-1; line > i; --line)
        {
            res[res.size()-i-1][line] = val++;
        }
        for(int row = res.size()-i-1; row > i; --row)
        {
            res[row][i] = val++;
        }
    }
    
};