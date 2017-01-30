/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/

/*
DFS solution
search for suroudings, if 'O', mark as different mark
count the diiferent mark, as 'O'
*/

class Solution {
public:
    void solve(vector<vector<char>>& board) {
	 if (board.empty() || board[0].empty()) return;
	 if (board.size() < 3 || board[0].size() < 3) return;

	 for (int i = 0; i < board.size(); ++i)
	 {
		 dfs_solve(board, i, 0);
		 dfs_solve(board, i, board[0].size()-1);
	 }

	 for (int j = 0; j < board[0].size(); ++j)
	 {
		 dfs_solve(board, 0, j);
		 dfs_solve(board, board.size() - 1, j);
	 }

	 for (int i = 0; i < board.size(); ++i)
	 {
		 for (int j = 0; j < board[0].size(); ++j)
		 {
			 if (board[i][j] == 'O') board[i][j] = 'X';
			 if (board[i][j] == '1') board[i][j] = 'O';
		 }
	 }
 }
 
private:
void dfs_solve(vector<vector<char>>& board, int i, int j)
 {
	 if (board[i][j] == 'O')
	 {
		 board[i][j] = '1';
		 if (i > 1) dfs_solve(board, i - 1, j);
		 if (j > 1) dfs_solve(board, i, j - 1);
		 if( i < board.size()-1) dfs_solve(board, i + 1, j);
		 if (j < board[0].size() - 1) dfs_solve(board, i, j+1);
	 }
 }
};