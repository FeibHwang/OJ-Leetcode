/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/

/*
basic idea:
how much water on position i will be decided by:
1:max value on the height[0..i-1]->leftmax
2:max value on the height[i+1..end]->rightmax
3:height[i]->self

final height on i(water height + self height): hold= max(self  ,  min(leftmax  ,  rightmax)
the water = hold - height

I use another vector right_side_max to record max height started from index i
so when calculating, I only need to update leftmax
space: O(n)
time: O(n)
*/

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<3) return 0;
        vector<int> right_side_max(height.size(),height.back());
        for(int i = height.size()-2; i>=0; i--)
        {
            right_side_max[i] = max(right_side_max[i+1],height[i]);
        }
        
        vector<int> hold(height.size(),0);
        int start = 0;
        while(height[start]==0)start++;
        hold[start] = height[start];
        
        int left_max = height[start];
        for(int i = start+1; i < height.size()-1; ++i)
        {
            hold[i] = max(height[i],min(left_max,right_side_max[i+1]));
            left_max = max(left_max,height[i]);
        }
        hold[hold.size()-1] = height[height.size()-1];
        
        int res = 0;
        for(int i = 0; i < height.size(); ++i)
            res += hold[i]-height[i];
        return res;
    }
};