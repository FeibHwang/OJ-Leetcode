/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.
*/

/*
DP
transfer function: record[i][j] = (matrix[i][j]-'0') * (min(record[i-1][j-1],min(record[i][j-1],record[i-1][j])) + 1)
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        
        
        vector<vector<int>> record(matrix.size(),vector<int>(matrix[0].size(),0));
        
        for(int i = 0; i < matrix.size(); ++i)
        {
            record[i][0] = matrix[i][0]-'0';
        }
        for(int i = 0; i < matrix[0].size(); ++i)
        {
            record[0][i] = matrix[0][i]-'0';
        }
        int result = 0;
        for(int i = 0; i < matrix.size(); ++i)
        {
            for(int j = 0; j < matrix[0].size(); ++j)
            {
                if(i!=0 && j != 0) record[i][j] = (matrix[i][j]-'0') * (min(record[i-1][j-1],min(record[i][j-1],record[i-1][j])) + 1);
                result = max(result,record[i][j]);
            }
        }
        
        return result*result;
    }
};