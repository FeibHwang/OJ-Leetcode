/*
Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
Note:
You may assume that the matrix does not change.
There are many calls to sumRegion function.
You may assume that row1 ≤ row2 and col1 ≤ col2.
*/

/*
Similar to previous question
record total sum for each [0,0] to [i,j]
*/

class NumMatrix {
public:
    vector<vector<int>> record;

    NumMatrix(vector<vector<int>> &matrix) {
        if(matrix.empty()) return;
        record = vector<vector<int>>(matrix.size(),vector<int>(matrix[0].size(),0));
        record[0][0] = matrix[0][0];
        
        for(int i = 1; i < matrix.size(); ++i )
        {
            record[i][0] = record[i-1][0] + matrix[i][0];
        }
        for(int i = 1; i < matrix[0].size(); ++i )
        {
            record[0][i] = record[0][i-1] + matrix[0][i];
        }
        
        for(int i = 1; i < matrix.size(); ++i)
        {
            for(int j = 1; j < matrix[0].size(); ++j)
            {
                record[i][j] = record[i-1][j] + record[i][j-1] - record[i-1][j-1] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if(record.empty()) return 0;
        int up = (row1==0)?0:1;
        int left = (col1==0)?0:1;
        return record[row2][col2] - (left * record[row2][col1-left] + up * record[row1-up][col2] - left*up*record[row1-up][col1-left]);
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);