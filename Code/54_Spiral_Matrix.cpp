/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/

/*
I didn't come up with a better solution so far, I use a subfunction to generate one spiral string and main function sweep the val
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return {};
        int line_top = 0, line_bottem = matrix.size()-1, row_left = 0, row_right = matrix[0].size()-1;
        vector<int> result = {};
        while(line_bottem - line_top > 1 && row_right - row_left > 1)
        {
            vector<int> tmp= spirlOrder_single(line_top,line_bottem,row_left,row_right,matrix);
            line_top++;line_bottem--;row_left++;row_right--;
            result.insert(result.end(),tmp.begin(),tmp.end());
        }
        vector<int> tail = spirlOrder_single(line_top,line_bottem,row_left,row_right,matrix);
        result.insert(result.end(),tail.begin(),tail.end());
        return result;
    }
    
    vector<int> spirlOrder_single(int line_top, int line_bottem, int row_left, int row_right, vector<vector<int>>& matrix)
    {
        if(line_top == line_bottem && row_left == row_right) return {matrix[line_top][row_left]};
        if(line_top == line_bottem)
        {
            vector<int> tp;
            for(int i = row_left; i <= row_right; ++i) tp.push_back(matrix[line_top][i]);
            return tp;
        }
        if(row_left == row_right)
        {
            vector<int> tp;
            for(int i = line_top; i <= line_bottem; ++i) tp.push_back(matrix[i][row_left]);
            return tp;
        }
        vector<int> rec1 = {};
        if(row_left <= row_right)
        {
            for(int i = row_left; i <= row_right; ++i) rec1.push_back(matrix[line_top][i]);
        }
        if(line_top != line_bottem)
        {
            for(int i = line_top+1; i <= line_bottem; ++i) rec1.push_back(matrix[i][row_right]);
        }
        if(row_right-row_left > 1 || line_bottem - line_top > 1)
        {
            for(int i = row_right-1; i >= row_left; --i)rec1.push_back(matrix[line_bottem][i]);
            for(int i = line_bottem-1; i >= line_top+1; --i)rec1.push_back(matrix[i][row_left]);
        }else if(row_right-row_left == 1 && line_bottem - line_top == 1)
        {
            rec1.push_back(matrix[line_bottem][row_left]);
        }

        return rec1;
    }
};