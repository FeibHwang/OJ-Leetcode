/*
This is a follow up of Shortest Word Distance. The only difference is now you are given the list of words and your method will be called repeatedly many times with different parameters. How would you optimize it?

Design a class which receives a list of words in the constructor, and implements a method that takes two words word1 and word2 and return the shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
*/

/*
same idea, track position of all words, using a hash map to realize O(1) search time
*/

class WordDistance {
public:
    WordDistance(vector<string> words) {
        for(int i = 0; i < words.size(); ++i) mp[words[i]].push_back(i);
        //myWord = words;
    }
    
    int shortest(string word1, string word2) {
        
        int dis = INT_MAX;
        for(auto i:mp[word1])
        {
            for(auto j:mp[word2])
            {
                dis = min(dis,abs(i-j));
            }
        }
        return dis;
        //return shortestDistance(myWord, word1, word2);
    }
    
private:
    unordered_map<string,vector<int>> mp;
    
    vector<string> myWord;
    
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