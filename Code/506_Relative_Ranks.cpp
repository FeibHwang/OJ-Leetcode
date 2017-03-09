/*
Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".
Example 1:
Input: [5, 4, 3, 2, 1]
Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal". 
For the left two athletes, you just need to output their relative ranks according to their scores.

Note:
N is a positive integer and won't exceed 10,000.
All the scores of athletes are guaranteed to be unique.
*/

/*
the key issue is to format the score to increasing array with 1 addition
*/

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        if(nums.size()==0) return {};
        vector<int> hold(nums);
        sort(hold.rbegin(),hold.rend());
        unordered_map<int,string> rec;
        for(int i = 0; i < hold.size(); ++i)
        {
            if(i==0) rec[hold[i]] = "Gold Medal";
            else if(i==1) rec[hold[i]] = "Silver Medal";
            else if(i==2) rec[hold[i]] = "Bronze Medal";
            else rec[hold[i]] = to_string(i+1);
        }
        vector<string> res;
        for(auto i:nums) res.push_back(rec[i]);
        return res;
    }
};