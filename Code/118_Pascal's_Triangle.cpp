/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/


/*
code is written directly according to the definition
*/


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int one = 1;
        vector<int> one_begin = {1};
        vector<int> two_begin = {1,1};
        vector<vector<int>> result = {};
        if(numRows == 0) {return result;}
        result.push_back(one_begin);
        if(numRows == 1) 
        {
            return result;
        }
        result.push_back(two_begin);
        if (numRows == 2)
        {
            return result;
        }else{
            for(int line = 2; line < numRows; ++line)
            {
                vector<int> line_begin = {1};
                for(int num = 0;num < line - 1; ++ num)
                {
                    line_begin.push_back(result[line-1][num] + result[line-1][num+1]);
                }
                line_begin.push_back(one);
                result.push_back(line_begin);
            }
        }
        return result;
    }
};