/*

Island Perimeter 

You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

 

Example:

Input:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Output: 16

Explanation: The perimeter is the 16 yellow stripes in the image below:



*/

class Solution {
public:
    int r, c;
    
    int get_perimeter_count(vector<vector<int>>& grid, int i, int j) {
        int cnt = 0;
        if(j==0 || grid[i][j-1] == 0) cnt++;
        if(i== 0 || grid[i-1][j] == 0) cnt++;
        if(i==r-1 || grid[i+1][j] == 0) cnt++;
        if(j==c-1 || grid[i][j+1] == 0) cnt++;
        return cnt; 
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        r = grid.size();
        c = grid[0].size();
        
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(grid[i][j] == 1)
                   perimeter += get_perimeter_count(grid, i, j); 
            }
        }
        return perimeter;
    }
};
