/*
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
*/

/*
direct count, I will come up with a better algorithm
*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
    vector<string> result = {};
    string to = "->";

    if(nums.empty()){return {};}
    if(nums.size()==1)
    {
        result.push_back(to_string(nums[0]));
    }
    else
    {
    	int end = 1;
    	int begin = end - 1;
    	int start = nums[begin];
    	for(;end < nums.size(); ++end)
    	{
    		begin = end - 1;
    		if(nums[end] - nums[begin] == 1 && end != nums.size() - 1)
    		{
    			continue;
    		}
    		if(nums[end] - nums[begin] != 1 && end != nums.size() - 1)
    		{
    			if(start == nums[begin])
    			{
    				result.push_back(to_string(start));
    				start = nums[end];
    				continue;
    			}else{
    				string tmp = to_string(start) + to + to_string(nums[begin]);
                    result.push_back(tmp);
                    start = nums[end];
                    continue;
    			}
    		}
    		if(end == nums.size() - 1)
    		{
    			if(nums[end] - nums[begin] == 1)
    			{
    					string tmp = to_string(start) + to + to_string(nums[end]);
                    	result.push_back(tmp);
                    	break;
    			}else{
    				if(start != nums[begin])
    				{
    					string tmp = to_string(start) + to + to_string(nums[begin]);
    					result.push_back(tmp);
    					result.push_back(to_string(nums[end]));
    					break;
    				}else{
    					result.push_back(to_string(start));
    					result.push_back(to_string(nums[end]));
    					break;
    				}

    			}
    		}
    	}
    }
    return result;

}
};