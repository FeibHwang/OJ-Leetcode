/***************************************************************************
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
**************************************************************************/

/***************************************************************************
 * check line,row and the 9-num box, just like player do
 * **************************************************************************/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool v_line = true;
        bool v_row = true;
        
        for(int i = 0; i < 9; ++i)
        {
            v_line = v_line && valid_line(board,i);
        }
        
        for(int i = 0; i < 9; ++i)
        {
            v_row = v_row && valid_row(board,i);
        }
        
        return v_line && v_row && valid_box(board);
    }
    
    
    
    bool valid_line(vector<vector<char>>& board,int line)
    {
        unordered_map<char,int> mp;
        for(int i = 0; i < 9; ++i)
        {
            if(board[line][i]=='.') continue;
            mp[board[line][i]]++;
            if(mp[board[line][i]]>1)
            {
                return false;
            }
        }
        return true;
    }
    
    
    bool valid_row(vector<vector<char>>& board,int row)
    {
        unordered_map<char,int> mp;
        for(int i = 0; i < 9; ++i)
        {
            if(board[i][row]=='.') continue;
            mp[board[i][row]]++;
            if(mp[board[i][row]]>1)
            {
                return false;
            }
        }
        return true;
    }
    
    bool valid_box(vector<vector<char>>& board)
    {
        vector<int> line = {1,4,7,1,4,7,1,4,7};
        vector<int> row =  {1,1,1,4,4,4,7,7,7};
        
        for(int i = 0; i < 9; ++i)
        {
            vector<char> box;
            
            box.push_back(board[line[i]][row[i]]);
            
            box.push_back(board[line[i]-1][row[i]-1]);
            
            box.push_back(board[line[i]-1][row[i]]);
            
            box.push_back(board[line[i]-1][row[i]+1]);
            
            box.push_back(board[line[i]][row[i]-1]);
            
            box.push_back(board[line[i]][row[i]+1]);
            
            box.push_back(board[line[i]+1][row[i]-1]);
            
            box.push_back(board[line[i]+1][row[i]]);
            
            box.push_back(board[line[i]+1][row[i]+1]);
            
            unordered_map<char,int> mp;
            for(int k = 0; k < 9; ++k)
            {
                if(box[k]=='.') continue;
                mp[box[k]]++;
                if(mp[box[k]]>1)
                {
                    return false;
                }
            }
        }
        return true;
    }
    
    
    //there is a better way to do it!! http://blog.csdn.net/doc_sgl/article/details/13002461
};