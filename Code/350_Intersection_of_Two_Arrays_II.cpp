/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
*/

/*
actually easier to implenment
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        
        for(int i = 0; i < nums1.size(); ++i)
        {
            mp[nums1[i]]++;
        }
        
        vector<int> result;
        for(int j=0; j < nums2.size(); ++j)
        {
            if(mp.find(nums2[j])!=mp.end())
            {
                if(mp[nums2[j]] > 0)
                {
                    result.push_back(nums2[j]);
                    mp[nums2[j]]--;
                }
            }
        }
        return result;
    }
};