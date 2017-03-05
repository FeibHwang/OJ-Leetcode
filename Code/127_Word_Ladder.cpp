/*
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
*/

/*
BFS, push beginWord into queue, literate every word in list, record the chosen one
the bfs will make sure the result is the shortest
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<int> rec(wordList.size(),-1);
        queue<string> que;
        que.push(beginWord);
        return bfs(que,endWord,rec,0, wordList)+1;
    }
    
    inline int worddist(string a, string b)
    {
        int dis = 0;
        if(a.length()==b.length())
        {
            for(int i = 0; i < a.length(); ++i)
            {
                dis += a[i]!=b[i];
            }
        }
        return dis;
    }
    
    int bfs(queue<string>& que, string endWord, vector<int>& rec, int level, vector<string>& wordList)
    {
        vector<string> tmp;
        while(!que.empty())
        {
            string check = que.front();
            que.pop();
            for(int i = 0; i < rec.size(); ++i)
            {
                if(rec[i]==-1 && worddist(check,wordList[i])==1)
                {
                    rec[i] = level+1;
                    tmp.push_back(wordList[i]);
                    if(wordList[i]==endWord) return rec[i];
                }
            }
        }
        if(tmp.empty()) return -1;
        for(auto i:tmp) que.push(i);
        return bfs(que,endWord,rec,level+1,wordList);
    }
    
};