/*
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/


/*
key issue is to sort hash map value:
transform hash map into pair
then sort
*/

class Solution {
public:
    struct CmpByValue {  
        bool operator()(const pair<char,int>& lhs, const pair<char,int>& rhs) {  
            return lhs.second >= rhs.second;  
        }
    };

    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(int i = 0; i < s.length(); ++i) mp[s[i]]++;
        vector<pair<char,int>> rec(mp.begin(),mp.end());
        sort(rec.begin(),rec.end(),CmpByValue());
        
        string res = "";
        for(int i = 0; i < rec.size(); ++i)
        {
            for(int j = 0; j < rec[i].second; j++)
            {
                res+=rec[i].first;
            }
        }
        return res;
    }
};