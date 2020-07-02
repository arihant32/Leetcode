/*

Rotting Oranges

In a given grid, each cell can have one of three values:

the value 0 representing an empty cell;
the value 1 representing a fresh orange;
the value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.

 

Example 1:



Input: [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: [[0,2]]
Output: 0
Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Note:

1 <= grid.length <= 10
1 <= grid[0].length <= 10
grid[i][j] is only 0, 1, or 2.


*/



class Solution {
public:
    int r,c;
    
     int x_dir[4] = {-1, 0, 0, 1};
     int y_dir[4] = {0, -1, 1, 0};
    
    bool isValid(int x, int y) {
        if(x<0 || x>=r || y<0 || y>=c) return false;
        return true;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();
        int rotten_orange = 0, fresh_orange = 0, total_orange = 0, time = 0;
        queue<pair<int,int>> q;
        
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(grid[i][j] == 2) {
                    rotten_orange++;
                    q.push({i,j}); 
                }else if(grid[i][j] == 1) {
                    fresh_orange++;
                }
            }
        }
        
        total_orange = rotten_orange + fresh_orange;
        
        if(total_orange == 0) return time;
        
        while(!q.empty()) {
            
            if(rotten_orange == total_orange) return time;
            int s = q.size();
            bool flag = false;
            
            while(s--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int k=0; k<4; k++) {
                    int px = x+x_dir[k];
                    int py = y+y_dir[k];
                    if(isValid(px, py) && grid[px][py] == 1) {
                        flag = true;
                        rotten_orange++;
                        grid[px][py] = 2;
                        q.push({px,py}); 
                    }
                }
            }
            if(flag) time++;    
        }
        return -1;
    }
};
