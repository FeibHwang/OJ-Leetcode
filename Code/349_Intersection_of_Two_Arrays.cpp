/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.
*/

/*
still using hash map
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        vector<int> result;
        int i1 = 0;
        int i2 = 0;
        while(i1 < nums1.size() || i2 < nums2.size())
        {
            if(i1 < nums1.size())
            {
                if(mp.find(nums1[i1]) == mp.end())
                {
                    mp[nums1[i1]] = 0;
                }
                else if(mp.find(nums1[i1]) != mp.end() && mp[nums1[i1]] == 1)
                {
                    result.push_back(nums1[i1]);
                    mp[nums1[i1]] = 2;
                }
                else
                {
                    i1++;
                    continue;
                }
                i1++;
            }
            
            if(i2 < nums2.size())
            {
                if(mp.find(nums2[i2]) == mp.end())
                {
                    mp[nums2[i2]] = 1;
                }
                else if(mp.find(nums2[i2]) != mp.end() && mp[nums2[i2]] == 0)
                {
                    result.push_back(nums2[i2]);
                    mp[nums2[i2]] = 2;
                }
                else
                {
                    i2++;
                    continue;
                }
                i2++;
            }
        }
        return result;
    }
};