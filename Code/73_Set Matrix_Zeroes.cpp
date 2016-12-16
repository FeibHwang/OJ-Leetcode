/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
*/

/*
first record whether or not the first line and first row need to be set to 0
then use the first line and first row as the indicator to decide whether this line or row needs to clear
finally decide first line/ row needs to clear
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty()) return;
        bool first_Line = false;
        bool first_Row = false;
        
        for(int i = 0; i < matrix.size(); ++i)
        {
            first_Row = first_Row || (matrix[i][0]==0);
        }
        
        for(int i = 0; i < matrix[0].size(); ++i)
        {
            first_Line = first_Line || (matrix[0][i]==0);
        }
        
        for(int i = 1; i < matrix.size(); ++i)
        {
            for(int j = 1; j < matrix[0].size();++j)
            {
                if(matrix[i][j]==0)
                {
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        
        for(int i = 1; i < matrix.size(); ++i)
        {
            if(matrix[i][0]==0)
            {
                for(int j = 0; j < matrix[0].size(); ++j)
                {
                    matrix[i][j]=0;
                }
            }
        }
        
        for(int i = 1; i < matrix[0].size(); ++i)
        {
            if(matrix[0][i]==0)
            {
                for(int j = 1; j < matrix.size(); ++j)
                {
                    matrix[j][i]=0;
                }
            }
        }
        
        if(first_Line)
        {
            for(int i = 0; i < matrix[0].size(); ++i)
            {
                matrix[0][i]=0;
            }
        }
        if(first_Row)
        {
            for(int i = 0; i < matrix.size(); ++i)
            {
                matrix[i][0]=0;
            }
        }
    }
};