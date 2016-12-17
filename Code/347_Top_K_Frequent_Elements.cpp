/*
Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note: 
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

/*
record using hash map
sort according to the value of hash table
watch how I did it
*/

class Solution {
public:

    //issue: how to sort map according to its value
    static int cmp(pair<int,int>& x, pair<int,int>& y)   
    //must add static: http://www.w2bc.com/Article/19411
    {
        return x.second > y.second;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        
        for(int i=0; i < nums.size(); ++i)
        {
            mp[nums[i]]++;
        }
        vector<pair<int,int>> record;
        int i = 0;
        for(auto item: mp)
        {
            record.push_back(make_pair(item.first,item.second));
        }
        sort(record.begin(),record.end(),cmp);

        vector<int> result;
        for(int j=0; j < k; ++j)
        {
            result.push_back(record[j].first);
        }
        
        return result;
    }
    
    
};