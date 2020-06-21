/*

Number of Islands

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3


*/


class Solution {
public:
    
    int r;
    int c;
    int x_dir[4] = {-1, 0, 0, 1};
    int y_dir[4] = {0, -1, 1, 0};
    
    bool isValid(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited) {
        if(i<0 || i>=r || j<0 || j>=c || visited[i][j] || grid[i][j] == '0')
            return false;
        return true;
    }
    
    void DFS(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>&visited) {
        
        visited[i][j] = true;
        
        for(int k=0; k<4; k++) {
            if(isValid(grid, i+x_dir[k], j+y_dir[k], visited))
                DFS(grid, i+x_dir[k], j+y_dir[k], visited);
        }
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        r = grid.size();
        if(r == 0) return 0;
        c = grid[0].size();
        
        vector<vector<bool>> visited(r,vector<bool>(c,false));
        int lands_count = 0;
        
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(grid[i][j] == '1' && !visited[i][j]){
                    DFS(grid, i, j, visited);
                    lands_count++;
                }
            }
        }
        
        return lands_count;
    }
};
