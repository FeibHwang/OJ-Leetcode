/*
Given two sparse matrices A and B, return the result of AB.

You may assume that A's column number is equal to B's row number.

Example:

A = [
  [ 1, 0, 0],
  [-1, 0, 3]
]

B = [
  [ 7, 0, 0 ],
  [ 0, 0, 0 ],
  [ 0, 0, 1 ]
]


     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                  | 0 0 1 |
*/

/*
direct calculate by definition
there is a faster way in Introduction to Algorithm
*/

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        if(A[0].size()!=B.size() || A.empty() || A[0].empty() || B.empty() || B[0].empty()) return {};
        vector<vector<int>> Btrans = transmatrix(B);
        vector<vector<int>> res(A.size(),vector<int>(B[0].size(),0));
        for(int i = 0; i < res.size(); ++i)
        {
            for(int j = 0; j < res[0].size(); ++j)
            {
                res[i][j] = vector_time(A[i],Btrans[j]);
            }
        }
        return res;
    }
    
    vector<vector<int>> transmatrix(vector<vector<int>>& B)
    {
        vector<vector<int>> res;
        for(int i = 0; i < B[0].size(); ++i)
        {
            vector<int> row;
            for(int j = 0; j < B.size(); ++j)
            {
                row.push_back(B[j][i]);
            }
            res.push_back(row);
        }
        return res;
    }
    
    int vector_time(vector<int> &al, vector<int> &bl)
    {
        int res = 0;
        for(int i = 0; i < al.size(); ++i) res += al[i]*bl[i];
        return res;
    }
};

