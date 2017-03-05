/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/

/*
record every number
then literate the array, expanding the smaller and larger
return the largest
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        
        for(int i = 0; i < nums.size(); ++i)
        {
            mp[nums[i]] = 1;
        }
        
        for(int i = 0; i < nums.size(); ++i)
        {
            int k = 1;
            while(mp.find(nums[i]-k) != mp.end())
            {
                //mp[nums[i]-k]++;
                mp[nums[i]]++;
            }
            k = 1;
            while(mp.find(nums[i]+k) != mp.end())
            {
                //mp[nums[i]+k]++;
                mp[nums[i]]++;
            }
        }
        
        auto item = mp.begin();
        int cnt = 0;
        for(;item!=mp.end(); ++item)
        {
            cnt = item->second > cnt ? item->second:cnt;
        }
        return cnt;
        
    }
};