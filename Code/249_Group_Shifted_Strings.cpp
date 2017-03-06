/*
Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:

"abc" -> "bcd" -> ... -> "xyz"
Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.

For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"], 
A solution is:

[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]
*/

/*
DFS compare every possible combinations 
*/

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<bool> rec(strings.size(),false);
        vector<vector<string>> res;
        for(int i = 0; i < strings.size(); ++i)
        {
            if(rec[i]) continue;
            vector<string> path;
            path.push_back(strings[i]);
            int cnt = i+1;
            while(cnt<strings.size())
            {
                if(!rec[cnt] && check(strings[i],strings[cnt]))
                {
                   path.push_back(strings[cnt]); 
                   rec[cnt] = true;
                }
                cnt++;
            }
            res.push_back(path);
        }
        return res;
    }
    
    bool check(string a, string b)
    {
        if(a.length()==b.length())
        {
            int dis = a[0]-b[0];
            for(int i = 0; i < a.length(); ++i)
                if ((a[i] - b[i]) != dis && (a[i] - b[i]) != (26 + dis) && (a[i] - b[i]) != (dis-26)) return false;
            return true;
        }
        return false;
    }
};