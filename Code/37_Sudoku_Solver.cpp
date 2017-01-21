/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.
*/

/*
DFS solution:
from head to tail, if it's not number, put 1~9 in it, check validity
if valid, proceed to next point
*/

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0);
    }
    
    bool solve(vector<vector<char>>& board, int step)
    {
        if(step == 81) return true;
        
        int line = step / 9;
        int row = step % 9;
        
        if(board[line][row] == '.')
        {
            for(int i = 1; i <= 9; ++i)
            {
                board[line][row] = i + '0';
                if(check(board,line,row))
                {
                    if(solve(board,step+1)) return true;
                }
                board[line][row] = '.';
            }
        }else{
            if(solve(board,step+1)) return true;
        }
        return false;
    }
    
    
    bool check(vector<vector<char>>& board,int line,int row)
    {
        vector<int> linecheck(10,0);
        vector<int> rowcheck(10,0);
        vector<int> gridcheck(10,0);
        
        for(int i = 0; i < 9; ++i)
        {
            if(board[line][i]!='.') linecheck[board[line][i]-'0']++;
            if(board[i][row]!='.') rowcheck[board[i][row]-'0']++;
        }
        
        for(int i = (line/3)*3; i < (line/3)*3+3; ++i)
        {
            for(int j = (row/3)*3; j < (row/3)*3+3; ++j)
            {
                if(board[i][j]!='.') gridcheck[board[i][j]-'0']++;
            }
        }
        
        for(int i = 0; i < 10; ++i)
        {
            if(linecheck[i]>1 || rowcheck[i]>1 || gridcheck[i]>1) return false;
        }
        return true;
    }
};