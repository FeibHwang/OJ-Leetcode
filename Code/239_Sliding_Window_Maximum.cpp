/*
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Therefore, return the max sliding window as [3,3,5,5,6,7].

Note: 
You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.

Follow up:
Could you solve it in linear time?

Hint:

How about using a data structure such as deque (double-ended queue)?
The queue size need not be the same as the window’s size.
Remove redundant elements and the queue should store only elements that need to be considered.
*/

/*
directly code according to question
using queue to simulate window
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.empty()) return {};
        deque<int> window;
        int min_num = INT_MIN;
        vector<int> result;
        
        for(int i = 0; i < k; ++i)
        {
            min_num = max(min_num,nums[i]);
            window.push_back(nums[i]);
        }
        
        result.push_back(min_num);
        
        for(int j = k; j < nums.size(); ++j)
        {
            int tmp = window.front();
            window.pop_front();
            window.push_back(nums[j]);
            min_num = (tmp < min_num && nums[j] < min_num)? min_num:maxdeque(window);
            result.push_back(min_num);
        }
        return result;
        
    }
    
    int maxdeque(deque<int> window)
    {
        int max_int = INT_MIN;
        for(auto item = window.begin();item != window.end();++item)
        {
            int tmp = *item;
            max_int = max(max_int,tmp);
        }
        return max_int;
    }
};