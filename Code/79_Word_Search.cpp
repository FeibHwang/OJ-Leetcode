/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

/*
DSF solution
for each letter, match the first char, if match, proceed to 2nd char to the 4 direction
*/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.empty()) return true;
        if(board.size()==0 || board[0].size()==0) return false;
        
        vector<vector<bool>> rec(board.size(),vector<bool>(board[0].size(),false));
        
        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[0].size();++j)
            {
                if(matchword(board,word,0,i,j,rec)) return true;
            }
        }
        return false;
    }
    
    
    bool matchword(vector<vector<char>>& board, string word, int match, int i, int j, vector<vector<bool>>& rec)
    {
        if(match == word.size()) return true;
        
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || rec[i][j] || board[i][j] != word[match])
            return false;
        

        rec[i][j] = true;
        bool res = matchword(board,word,match+1,i+1,j,rec) ||
                   matchword(board,word,match+1,i-1,j,rec) ||
                   matchword(board,word,match+1,i,j+1,rec) ||
                   matchword(board,word,match+1,i,j-1,rec);
        rec[i][j] = false;
        
        return res;
    }
};