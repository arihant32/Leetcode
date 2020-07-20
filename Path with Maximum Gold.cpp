/*

Path with Maximum Gold


In a gold mine grid of size m * n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.

Return the maximum amount of gold you can collect under the conditions:

Every time you are located in a cell you will collect all the gold in that cell.
From your position you can walk one step to the left, right, up or down.
You can't visit the same cell more than once.
Never visit a cell with 0 gold.
You can start and stop collecting gold from any position in the grid that has some gold.
 

Example 1:

Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
Output: 24
Explanation:
[[0,6,0],
 [5,8,7],
 [0,9,0]]
Path to get the maximum gold, 9 -> 8 -> 7.
Example 2:

Input: grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
Output: 28
Explanation:
[[1,0,7],
 [2,0,6],
 [3,4,5],
 [0,3,0],
 [9,0,20]]
Path to get the maximum gold, 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7.
 

Constraints:

1 <= grid.length, grid[i].length <= 15
0 <= grid[i][j] <= 100
There are at most 25 cells containing gold.

*/


class Solution {
public:
    
    int r,c;
    int drx[4] = {-1, 0, 0, 1 };
    int dry[4] = {0, -1, 1, 0 };
    vector<vector<bool>> visited;
    
    bool isValid(vector<vector<int>>& grid, int x, int y) {
        if(x<0 || x>=r || y<0 || y>=c || visited[x][y] || grid[x][y]==0)
            return false;
        return true;
    }
    
    int max = 0;
    
    int gold_helper(vector<vector<int>>& grid, int i, int j, int current_max) {
        visited[i][j] = true;
        current_max = current_max + grid[i][j];
        if(current_max>max) max = current_max;
        for(int k=0; k<4; k++) {
            int x = i + drx[k];
            int y = j + dry[k];
            if(isValid(grid, x, y)) {
                gold_helper(grid, x, y, current_max);
            }
        }
        visited[i][j] = false;
        return max;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        r = grid.size();
        if(r==0) return 0;
        c = grid[0].size();
        int max_gold = 0;
        int current_max = 0;
        visited.resize(r,vector<bool>(c,false));
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(grid[i][j] != 0) {
                    current_max = gold_helper(grid, i, j, 0);
                    if(current_max > max_gold) max_gold = current_max;
                    max=0;
                }
            }
        }
        return max_gold;
    }
};
