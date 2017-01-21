/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

[
  ["aa","b"],
  ["a","a","b"]
]
*/

/*
dfs solution
record cuting position and previous cutting position
*/


class Solution {
public:
    vector<vector<string>> partition(string s) {
        dfs(s,0,1);
        return res;
    }
    
private:
    vector<vector<string>> res;
    vector<string> path;
    
    void dfs(string s, int prev, int start)
    {
        if(start == s.length())
        {
            if(isPalindrome(s,prev,start-1))
            {
                path.push_back(s.substr(prev,start-prev));
                res.push_back(path);
                path.pop_back();
            }
            return;
        }
        
        dfs(s,prev,start+1); //uncut
        
        if(isPalindrome(s,prev,start-1)) //cut
        {
            path.push_back(s.substr(prev,start-prev));
            dfs(s,start,start+1);
            path.pop_back();
        }
    }
    
    bool isPalindrome(string s, int start, int end)
    {
        while(start < end && s[start]==s[end])
        {
            start++;end--;
        }
        return start >= end;
    }
    
};