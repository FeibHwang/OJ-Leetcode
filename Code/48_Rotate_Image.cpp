/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/

/*
1. swap diaganal
2. swap up/down
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return;
        int n = matrix.size();
        for(int i = 0; i < matrix.size(); ++i)
        {
            for(int j = 0; j < n-i; ++j)
            {
                swap(matrix[i][j],matrix[n-1-j][n-1-i]);
            }
        }
        
        for(int i = 0; i < matrix.size()/2; ++i)
        {
            for(int j = 0; j < matrix.size(); ++j)
            {
                swap(matrix[i][j],matrix[n-1-i][j]);
            }
        }
    }
};