/*
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
*/

/*
bucket sort, the most important issue is to decide the size of the bucket!
range = ceil(double(maxnum - minnum) / (nums.size()-1))
*/

class Solution {
public:
    int maximumGap(vector<int>& nums) {
	if (nums.size()<2) return 0;
	int maxnum = INT_MIN, minnum = INT_MAX;
	for (int i = 0; i < nums.size(); ++i)
	{
		maxnum = max(maxnum, nums[i]);
	    minnum = min(minnum, nums[i]);
	}
	    
	int range = ceil(double(maxnum - minnum) / (nums.size()-1));
	if(range==0) return 0;
	
	vector<vector<int>> buckets(nums.size());
	
	for(auto iter = nums.begin(); iter != nums.end(); ++iter)
	{
	    int index = (*iter - minnum) / range;
	    if(buckets[index].empty())
	    {
	        buckets[index].push_back(*iter);
	        buckets[index].push_back(*iter);
	    }else{
	        buckets[index][0] = buckets[index][0] < *iter ? buckets[index][0]:*iter;
	        buckets[index][1] = buckets[index][1] > *iter ? buckets[index][1]:*iter;
	    }
	    
	}
	
	int gap = 0, pre = 0;
	for(int i = 1; i < buckets.size(); ++i)
	{
	    if(!buckets[i].empty())
	    {
	        gap = max(gap,buckets[i][0]-buckets[pre][1]);
	        pre = i;
	    }
	}
	return gap;
    }
};