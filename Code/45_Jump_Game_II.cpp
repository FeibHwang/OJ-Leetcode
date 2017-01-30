/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Note:
You can assume that you can always reach the last index.
*/

class Solution {
public:
    int jump01(vector<int>& nums) {
        if(nums.empty() || nums.size()==1) return 0;
        
        vector<int> rec(nums.size(),0); //[0,0,0]
        
        int reach = nums.size()-1; //2
        int step = 0; //0
        while (reach > 0) //0
    	{
    		int tmp = reach; //0
    		for (int i = reach; i >= 0; --i) //i~1->0
    		{
    			if (reach - i <= nums[i]) //true
    			{
    				rec[i] = step + 1; //[2,1,0]
    				tmp = i; //0
    			}
    		}
    		reach = tmp; //1
    		step++; //1
    	}
        return rec[0];
    }
    
    /*
    BFS solution:
    based on first elem decide range
    sweep range, see if there is any elem can reach end,update range, continue sweeping
    */
    
    int jump(vector<int>& nums) {
        int n = nums.size(), start = 0, end = 0, step = 0;
        while(end < n-1)
        {
            step++;
            int maxend = end+1;
            for(int i = start; i <= end; ++i)
            {
                if(i+nums[i] >= n-1) return step;
                maxend = max(maxend,i+nums[i]);
            }
            start = end+1;
            end = maxend;
        }
        return step;
    }
};