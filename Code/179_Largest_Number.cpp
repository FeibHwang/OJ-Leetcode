/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
*/

/*
convert int to string, and sort
the trick is about how to sort two string
here is a trick: return s1+s2>s2+s1
*/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> num;
        for(int i = 0; i < nums.size(); ++i)
        {
            num.push_back(to_string(nums[i]));
        }
        
        sort(num.begin(),num.end(),[](string &s1, string &s2){ return s1+s2>s2+s1; });
        string result;
        for(int i = 0; i < num.size(); ++i)  result += num[i];
        while(result[0]=='0' && result.length()>1)
            result.erase(0,1);
        return  result;
    }
};