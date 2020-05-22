/**

Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

A partially filled sudoku which is valid.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

Example 1:

Input:
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: true
Example 2:

Input:
[
  ["8","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being 
    modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
The given board contain only digits 1-9 and the character '.'.
The given board size is always 9x9.

**/

class Solution {
public:
    bool is_row_valid(vector<vector<char>>& board, int row_i)
    {
        // to store numbers to tell if no occur or not 
        set<char> s;
        for(int i=0; i<9; i++)
        {
            if(board[row_i][i] == '.') 
                continue;
            // if not found in set then added into the set.
            if(s.find(board[row_i][i]) == s.end())
                s.insert(board[row_i][i]);
            else
                return false;    
        }
        return true;
    }
    
    bool is_col_valid(vector<vector<char>>& board, int col_j)
    {
        // to store numbers to tell if no occur or not 
        set<char> s;
        for(int i=0; i<9; i++)
        {
            if(board[i][col_j] == '.') 
                continue;
            // if not found in set then added into the set.
            if(s.find(board[i][col_j]) == s.end())
                s.insert(board[i][col_j]);
            else
                return false;    
        }
        return true;
    }
    
    bool is_square_valid(vector<vector<char>>& board, int row_i, int col_j)
    {
        // to store numbers to tell if no occur or not 
        set<char> s;
        
        // for 3 cross 3 box
        for(int i=row_i; i<row_i+3; i++)
        {
            for(int j=col_j; j<col_j+3; j++)
            {
                if(board[i][j] == '.') 
                    continue;
                // if not found in set then added into the set.
                if(s.find(board[i][j]) == s.end())
                    s.insert(board[i][j]);
                else
                    return false;    
            } 
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int r = board.size(); 
        int c = board[0].size();
        
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                // checking each row is valid or not
                if(!is_row_valid(board, i))
                    return false;
                
                // checking each column is valid or not
                if(!is_col_valid(board, j))
                    return false;
                
                // checking each box 3 cross 3 is valid or not
                if(i%3 == 0 && j%3 == 0)
                {
                    if(!is_square_valid(board, i,j))
                        return false;
                }
                
            }
        }
        
        return true;
        
    }
};
