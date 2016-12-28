/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
*/

/*
Basic fact:
final solution ai~aj: ai < an, n < i; aj >am, m > j

using two pointer and shrink until finding larger height

the algorithm can be optimized to only one compare each run
*/


class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int area = (right-left)*min(height[left],height[right]);
        
        while(left < right)
        {
            area = max(area,(right-left)*min(height[left],height[right]));
            height[left] < height[right] ? left++ : right--;
        }
        return area;
    }
};