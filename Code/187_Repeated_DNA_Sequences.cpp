/*
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
*/

/*
using hash table to record each length-10 sequence
*/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.length()<11) return {};
        unordered_map<string,int> mp;
        
        for(int i = 0; i <= s.length()-10; ++i)
        {
            mp[s.substr(i,10)]++;
        }
        
        vector<string> result;
        for(auto item:mp)
        {
            if(item.second > 1)
                result.push_back(item.first);
        }
        
        return result;
    }
};