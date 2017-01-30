/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given heights = [2,1,5,6,2,3],
return 10.
*/

/*
use a stack:
https://www.youtube.com/watch?v=VNbkzsnllsU
*/

class Solution {
public:
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