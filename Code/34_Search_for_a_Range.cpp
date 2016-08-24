/***************************************************************************
* Given a sorted array of integers, find the starting and ending position of a given target value.

* Your algorithm's runtime complexity must be in the order of O(log n).

* If the target is not found in the array, return [-1, -1].

* For example,
* Given [5, 7, 7, 8, 8, 10] and target value 8,
* return [3, 4]. 
**************************************************************************/

/***************************************************************************
 * find one target, expand the range
 * **************************************************************************/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==1)
        {
            if(nums[0]==target) return {0,0};
            else return {-1,-1};
        } //special case
        int mid = find_target(nums,target);      //find at least one target
        if(mid == -1) return {-1,-1};
        int start = mid, end = mid;
        while(start >= 0 && end < nums.size())  //expand the range
        {
            if(start!=0)
            {
                if(nums[start]==nums[start-1])
                {
                    start--;
                }
            }
            if(end!=nums.size()-1)
            {
                if(nums[end]==nums[end+1])
                {
                    end++;
                }
            }
            if((start==0 || nums[start]!=nums[start-1])&&(end==nums.size()-1 || nums[end]!=nums[end+1]))
            {
                break;
            }
        }
        vector<int> result;
        result.push_back(start);
        result.push_back(end);
        return result;
    }
    
    int find_target(vector<int>& nums, int target)    //binary search
{
	int left, right;
	int mid;
	left = 0;
	right = nums.size() - 1;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (target == nums[mid]) return mid;
		else if (target < nums[mid]) right = mid - 1;
		else if (target > nums[mid]) left = mid + 1;
	}
	return -1;
}
};
