/*
Given an array of integers, 
find out whether there are two distinct indices i and j in the array 
such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.
*/

/*
maintain a K size window
need to convert int to long to avoid overflow
*/

class Solution {
public:
//http://www.2cto.com/kf/201506/410746.html
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(t < 0 || k < 1) return false;
        
        unordered_map<int,int> mp;
        int key;
        for(int i = 0; i < nums.size(); ++i)
        {
            key = nums[i]/max(1,t);
            if( (mp.find(key) != mp.end() && abs(nums[i] - mp[key]) <= t) ||
                (mp.find(key-1) != mp.end() && abs((long)nums[i] - (long)mp[key-1]) <= t) ||
                (mp.find(key+1) !=mp.end() && abs(nums[i] - mp[key+1]) <= t))
            {                           
                return true;
            }
            
            mp.insert(pair<int,int>(key,nums[i]));

            if(i>=k)
            {
                mp.erase(nums[i-k]/max(1,t));
            }

        }
        return false;
    }
    
};