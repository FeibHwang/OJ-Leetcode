/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 6.
*/

/*
similar to largest rectangle in histogram
just for each line see the line above form a histogram
if this line contains 0, don't accumulate
*/


class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()||matrix[0].empty()) return 0;
        vector<int> height(matrix[0].size(),0);
        int res = 0;
        for(int i = 0; i < matrix.size(); ++i)
        {
            for(int j = 0; j <matrix[0].size(); ++j)
            {
                height[j] = (matrix[i][j]-'0')*(height[j]+matrix[i][j]-'0');
            }
            res = max(res,largestRectangleArea(height));
        }
        return res;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        stack<int> height;
        stack<int> pos;
        
        int area = 0;
        int h,p;
        
        for(int i = 0; i < heights.size(); ++i)
        {
            if(pos.empty() || heights[i] > height.top())
            {
                height.push(heights[i]);
                pos.push(i);
                continue;
            }
            else if(height.top()>heights[i])
            {
                while(!height.empty() && height.top()>heights[i])
                {
                    h = height.top();
                    p = pos.top();
                    area = max(area,h*(i-p));
                    height.pop();pos.pop();
                }
                
                height.push(heights[i]);
                pos.push(p);
                
            }
        }
        
        int len = heights.size();
        while(!pos.empty())
        {
            h = height.top();
            p = pos.top();
            area = max(area,h*(len-p));
            height.pop();pos.pop();
        }
        return area;
    }
};