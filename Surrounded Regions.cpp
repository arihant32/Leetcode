/*

Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.

*/

class Solution {
public:
    int r;
    int c;
    
    void dfs_make_other(vector<vector<char>>& board, int i, int j) {
        if( i<0 || i>=r || j<0 || j>=c)
            return;
        
        if(board[i][j] == 'O') {
            
            board[i][j] = '#';
            //for all 4 direction -> top, bottom, left, right
            dfs_make_other(board, i-1, j);
            dfs_make_other(board, i+1, j);
            dfs_make_other(board, i, j-1);
            dfs_make_other(board, i, j+1);
        }
        
    }
    void solve(vector<vector<char>>& board) {
        
        if(board.size() == 0)
            return;
        
        r = board.size();
        c = board[0].size();
        
        // marking 1st row and last row 'O' (and it's Surrounded 'O') to other char say '#'
        for(int i=0; i<c; i++) {
            if(board[0][i] == 'O')
                dfs_make_other(board, 0, i);
        }
        
        for(int i=0; i<c; i++) {
            if(board[r-1][i] == 'O')
                dfs_make_other(board, r-1, i);
        }
        
        // marking 1st col and last col 'O' (and it's Surrounded 'O') to other char say '#'
        for(int i=0; i<r; i++) {
            if(board[i][0] == 'O')
                dfs_make_other(board, i, 0);
        }
        
        for(int i=0; i<r; i++) {
            if(board[i][c-1] == 'O')
                dfs_make_other(board, i, c-1);
        }
        
        // now fill all # to 'O' (as we changed it above) and all 'O' to 'X'
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(board[i][j] == '#')
                    board[i][j] = 'O';
                else if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        
    }
};
