/*

Word Search


Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
 

Constraints:

board and word consists only of lowercase and uppercase English letters.
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3


*/


class Solution {
public:
    int r,c;
    int x_dir[4] = {-1, 0, 0, 1};
    int y_dir[4] = {0, -1, 1, 0};
    string str = "";
    
    bool DFS(vector<vector<char>> &board,int i, int j, vector<vector<bool>> &visited, string word, int index) {
        
        if(i<0 || i>=r || j<0 || j>=c || visited[i][j] == true) return false;
        
        if(board[i][j]!=word[index]) return false;
        
        str = str + board[i][j];
        
        if(str.compare(word) == 0) return true;
        
        visited[i][j] = true;
        
        for(int k=0; k<4; k++) {
            if(DFS(board, i+x_dir[k], j+y_dir[k], visited, word, index+1))
                return true;
        }  
        
        visited[i][j] = false;
        str.erase(str.size()-1);
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        r = board.size();
        c = board[0].size();
        
        vector<vector<bool>> visited(r,vector<bool>(c, false));
        
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(DFS(board, i, j, visited, word, 0)) 
                    return true;
            }
        }
        
        return false;
    }
};


