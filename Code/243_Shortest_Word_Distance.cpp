/*
Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
*/

/*
track position of the words, iterate all posible distance
*/

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        vector<int> w1;
        vector<int> w2;
        for(int i = 0; i < words.size(); ++i)
        {
            if(words[i]==word1) w1.push_back(i);
            if(words[i]==word2) w2.push_back(i);
        }
        int dis = INT_MAX;
        for(int i = 0; i < w1.size(); ++i)
        {
            for(int j = 0; j < w2.size(); ++j)
            {
                dis = min(dis,abs(w1[i]-w2[j]));
            }
        }
        return dis;
    }
};