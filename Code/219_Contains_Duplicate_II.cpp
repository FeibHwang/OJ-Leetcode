/*
Given an array of integers and an integer k, 
find out whether there are two distinct indices i and j in the array 
such that nums[i] = nums[j] and the difference between i and j is at most k.
*/

/*
same as previous
just this time add one more constrain: ps - mp[n] <= k
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
    
        
        unordered_map<int,int> mp;
        for(int ps = 0; ps < nums.size(); ++ps)
        {
            int n = nums[ps];
            if(mp.find(n)!=mp.end() && ps - mp[n] <= k)
            {
                return true;
            }
            
            mp[nums[ps]] = ps;
        }
        return false;
    }