/*
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
*/

/*
naive solution: put every length-10 substring into the hash map for checking

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

    vector<string> findRepeatedDnaSequences01(string s) {
        if(s.length()<11) return {};
        unordered_set<string> mp;
        unordered_set<string> rec;

        for(int i = 0; i <= s.length()-10; ++i)
        {
            string check = s.substr(i,10);
            if(mp.find(check)==mp.end()) mp.insert(check);
            else rec.insert(check);
        }

        
        return vector<string>(rec.begin(),rec.end());
    }
};