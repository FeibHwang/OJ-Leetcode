/*
Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below. 

 

Example 1:
Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]

Note:
You may use one character in the keyboard more than once.
You may assume the input string will only contain letters of alphabet.
*/

/*
use vector instead of hash map to save space and time
*/

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<int> match = {1,2,2,1,0,1,1,1,0,1,1,1,2,2,0,0,0,0,1,0,0,2,0,2,0,2};
        vector<string> res;
        for(int i = 0; i < words.size(); ++i)
        {
            int begin = match_char(match,words[i][0]);
            bool isnot = true;
            for(int j = 1; j < words[i].length(); ++j) 
            {
                if(begin != match_char(match,words[i][j])) 
                {
                    isnot = false;
                    break;
                }
            }
            if(isnot) res.push_back(words[i]);
        }
        return res;
    }
    
    int match_char(vector<int> &board, char c)
    {
        int conv = 0;
        return board[tolower(c)-conv-'a'];
    }
};