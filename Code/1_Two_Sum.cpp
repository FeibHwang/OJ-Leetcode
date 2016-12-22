/********************************************************************************** 
* 
* Given an array of integers, find two numbers such that they add up to a specific target number.
* 
* The function twoSum should return indices of the two numbers such that they add up to the target, 
* where index1 must be less than index2. Please note that your returned answers (both index1 and index2) 
* are not zero-based.
* 
* You may assume that each input would have exactly one solution.
* 
* Input: numbers={2, 7, 11, 15}, target=9
* Output: index1=1, index2=2
* 
*               
**********************************************************************************/

/********************************************************************************** 
* Basic Idea:
* using hash map to solve, since there is onli one solution
* be sure that the key is the difference between the target and the number

* two pointer solution:
* sort, using two pointer to find, much much more efficient
**********************************************************************************/

class Solution {
public:

    vector<int> twoSum01(vector<int>& nums, int target) {
    	vector<int> result = {};
    	int target_tmp = target;
	   	unordered_map<int,int> mp;
	    for(int start = 0;start < nums.size();++start)
	    {
	        if(mp.find(nums[start])==mp.end())
	        {
	            mp[target-nums[start]] = start;
	        }else{
	            result.push_back(mp[nums[start]]);
	            result.push_back(start);
	            break;
	        }
	    }
    return result;
    
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> s(nums);
        sort(s.begin(),s.end());
        int i = 0; 
        int j = s.size() - 1; 
        while(i<j)
        {
            int sum = s[i]+s[j];
            if(sum == target) break;
            if(sum < target) i++;
            if(sum > target) j--;
        }
        if(s[i]+s[j]==target)
        {
            vector<int> res= {-1,-1};
            for(int k = 0, l = nums.size()-1; k < nums.size() && l>=0; ++k,--l)
            {
                if(nums[k]==s[i]&&res[0]==-1)
                {
                    res[0]=k;
                }
                if(nums[l]==s[j]&&res[1]==-1)
                {
                    res[1]=l;
                }
            }
            return res;
        }
        return {};
    }
};