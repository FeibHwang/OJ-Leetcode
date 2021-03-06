/*
Given an 2D board, count how many different battleships are in it. The battleships are represented with 'X's, empty slots are represented with '.'s. You may assume the following rules:

You receive a valid board, made of only battleships or empty slots.
Battleships can only be placed horizontally or vertically. In other words, they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1 column), where N can be of any size.
At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.
Example:
X..X
...X
...X
In the above board there are 2 battleships.
Invalid Example:
...X
XXXX
...X
This is an invalid board that you will not receive - as battleships will always have a cell separating between them.
Follow up:
Could you do it in one-pass, using only O(1) extra memory and without modifying the value of the board?
*/

/*
how to define a ship:
any ship has only 1 left-bottom:

X .    or       X |         or       X |
.               .                    _
it's unique!!!
*/

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int cnt = 0;
        if(board.empty() || board[0].empty())return cnt;
        
        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[0].size(); ++j)
            {
                if( board[i][j] == 'X' && (i==board.size()-1 || board[i+1][j]=='.') && (j==board[0].size()-1 || board[i][j+1]=='.') )
                    cnt++;
            }
        }
        return cnt;
    }
};