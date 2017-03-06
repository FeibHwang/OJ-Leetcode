/*
This is a follow up of Shortest Word Distance. The only difference is now word1 could be the same as word2.

Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

word1 and word2 may be the same and they represent two individual words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “makes”, word2 = “coding”, return 1.
Given word1 = "makes", word2 = "makes", return 3.

Note:
You may assume word1 and word2 are both in the list.
*/

/*
using hash map track all posible position of each word
*/


class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        for(int i = 0; i < words.size(); ++i)
        {
            dict[words[i]].push_back(i);
        }
        
        int res = INT_MAX;
        if(word1==word2)
        {
            for(int i = 1; i < dict[word1].size(); ++i)
                res = min(res, dict[word1][i]-dict[word1][i-1]);
        }else{
            for(int i = 0; i < dict[word1].size(); ++i)
            {
                for(int j = 0; j < dict[word2].size(); ++j)
                {
                    res = min(res,abs(dict[word1][i]-dict[word2][j]));
                }
            }
        }
        return res;
    }
    
private:
    unordered_map<string,vector<int>> dict;
};