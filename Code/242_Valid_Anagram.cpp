/*
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/

/*
use hash map to count

faster way:
since there are only 256 char
just use array to count
C style is much faster
*/

class Solution {
public:
    bool isAnagram01(string s, string t) {
        if(s.size()!=t.size()){return false;}
        unordered_map<char,int> mp;
        for(int i = 0; i < s.size(); ++i)
        {
            if(mp.find(s[i])==mp.end())
            {
                mp[s[i]]=1;
            }else{
                mp[s[i]]++;
            }
        }
        
        for(int j = 0; j < t.size(); j++)
        {
            if(mp.find(t[j])==mp.end())
            {
                return false;
            }else{
                mp[t[j]]--;
            }
            if(mp[t[j]] < 0){return false;}
        }
        return true;
    }
    
    
    bool isAnagram(string s, string t) {
        int map[256] ={0} ; //only lowercase alphabets
        //memset(map, 0, sizeof(map));
        
        // count each char for s
        for (int i=0; i<s.size(); i++) {
            map[s[i]]++;
        }
        // decrease the count for t
        for (int i=0; i<t.size(); i++) {
            map[t[i]]--;
        }
        
        //if all alphabets is zero, then they are anagram 
        for (int i=0; i<sizeof(map)/sizeof(map[0]); i++) {
            if (map[i]!=0) return false;
        }
        return true;
    }
    
};