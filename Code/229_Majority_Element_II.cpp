/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.

Hint:

How many majority elements could it possibly have?
Do you have a better hint? Suggest it!
*/

/*
I use hash map to trace
may be another more efficient way??
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result = {};
        if(nums.empty()){return result;}
        if(nums.size() == 1){return nums;}
        if(nums.size() == 2)
        {
            if(nums[0] == nums[1])
            {
                result.push_back(nums[0]);
                return result;
            }else{
                result.push_back(nums[0]);
                result.push_back(nums[1]);
                return result;
            }
        }
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i = 0 ; i < n; ++i)
        {
                mp[nums[i]]++;
                if(mp[nums[i]] > n / 3 )//&& find(result.begin(), result.end(), nums[i]) == result.end())
                {
                    result.push_back(nums[i]);
                    mp[nums[i]] = - n;
                }
        }
        return result;
    }
};