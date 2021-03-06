/*
You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u,v) which consists of one element from the first array and one element from the second array.

Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

Example 1:
Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3

Return: [1,2],[1,4],[1,6]

The first 3 pairs are returned from the sequence:
[1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
Example 2:
Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2

Return: [1,1],[1,1]

The first 2 pairs are returned from the sequence:
[1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
Example 3:
Given nums1 = [1,2], nums2 = [3],  k = 3 

Return: [1,3],[2,3]

All possible pairs are returned from the sequence:
[1,3],[2,3]
*/

/*
brute forse: find every pair
sort according to sum of pair
take first k pair
*/

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> result;
        
        for(int i = 0; i < nums1.size(); ++i)
        {
            for(int j = 0; j < nums2.size(); ++j)
            {
                auto tmp = make_pair(nums1[i],nums2[j]);
                result.push_back(tmp);
            }
        }
        sort(result.begin(),result.end(),cmp);
        if(k < nums1.size()*nums2.size()) result.assign(result.begin(),result.begin()+k);
        return result;
        
        
    }
    
    static bool cmp(pair<int,int> &p1, pair<int,int> &p2)
    {
        return (p1.first + p1.second) < (p2.first + p2.second);
    }
};