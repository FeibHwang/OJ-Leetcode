/*
According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state.

Follow up: 
Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?
*/

/*
write code according to the question directly
*/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
	vector<vector<int>> _new = board;
	int m = board.size();
	int n = board[0].size();
	
	if(board.empty()) {return;}
	if(n==0 && m==1) {return;}
	if(m == 1 && n == 1) {board = {{0}};}
	if(m == 1){
	    _new[0][0]=0;
	    _new[0][n-1]=0;
	    for(int i = 1; i < n-1; ++i)
	    {
	        _new[0][i] = live_or_dead(board[0][i-1]+board[0][i+1],board[0][i]);
	    }
	}
	if(n == 1){
	    _new[0][0]=0;
	    _new[m-1][0]=0;
	    for(int i = 1; i < m-1; ++i)
	    {
	        _new[i][0] = live_or_dead(board[i-1][0]+board[i+1][0],board[i][0]);
	    }
	}
	
	if(m > 1 && n > 1){
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i == 0 && j == 0) { _new[i][j] = live_or_dead(board[i + 1][j] + board[i + 1][j + 1] + board[i][j + 1], board[i][j]); continue; }
			if (i == 0 && j == n - 1) { _new[i][j] = live_or_dead(board[i][j - 1] + board[i + 1][j] + board[i + 1][j - 1], board[i][j]); continue;}
			if (i == m - 1 && j == 0) { _new[i][j] = live_or_dead(board[i][j + 1] + board[i - 1][j] + board[i - 1][j + 1], board[i][j]); continue;}
			if (i == m - 1 && j == n - 1) { _new[i][j] = live_or_dead(board[i][j - 1] + board[i - 1][j] + board[i - 1][j - 1], board[i][j]); continue; }
			if (i == 0 && j != 0 && j != n - 1)
			{
				_new[i][j] = live_or_dead(board[i][j - 1] + board[i + 1][j] + board[i + 1][j - 1] + board[i + 1][j + 1] + board[i][j + 1], board[i][j]); continue;
			}
			if (i == m - 1 && j != 0 && j != n - 1)
			{
				_new[i][j] = live_or_dead(board[i][j - 1] + board[i - 1][j] + board[i - 1][j - 1] + board[i - 1][j + 1] + board[i][j + 1], board[i][j]); continue;
			}
			if (j == 0 && i != 0 && i != m - 1)
			{
				_new[i][j] = live_or_dead(board[i][j + 1] + board[i + 1][j] + board[i + 1][j + 1] + board[i - 1][j + 1] + board[i-1][j], board[i][j]); continue;
			}
			if (j == n - 1 && i != 0 && i != m - 1)
			{
				_new[i][j] = live_or_dead(board[i][j - 1] + board[i + 1][j] + board[i + 1][j - 1] + board[i - 1][j - 1] + board[i - 1][j], board[i][j]); continue;
			}
			_new[i][j] = live_or_dead(board[i - 1][j - 1] + board[i - 1][j] + board[i - 1][j + 1] + board[i][j - 1] + board[i][j + 1] + board[i + 1][j - 1] + board[i + 1][j] + board[i + 1][j + 1], board[i][j]);
		}
	}}
	board = _new;
}
    
    int live_or_dead(int count, int cell)
    {
        if(count == 3){
            return 1;
        }
        if(count == 2){
            return cell;
        }
        return 0;
    }
};