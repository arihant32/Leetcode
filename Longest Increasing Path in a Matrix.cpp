/*

Longest Increasing Path in a Matrix


Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

Input: nums = 
[
  [9,9,4],
  [6,6,8],
  [2,1,1]
] 
Output: 4 
Explanation: The longest increasing path is [1, 2, 6, 9].
Example 2:

Input: nums = 
[
  [3,4,5],
  [3,2,6],
  [2,2,1]
] 
Output: 4 
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

*/


class Solution {
public:
    vector<vector<bool>> visited;
    vector<vector<int>> dp;
    int xdr[4] = {-1, 0, 1, 0};
    int ydr[4] = {0, -1, 0, 1};
    int r,c;
    
    bool isValid(vector<vector<int>>& matrix, int x,int y, int pre_val) {
        if(x<0 || x>=r || y<0 || y>=c || pre_val>=matrix[x][y])
            return false;
        return true;
    }
    
    int getIncLn(vector<vector<int>>& matrix, int i, int j) {
        if(dp[i][j] != 0) return dp[i][j];
        int len=0;
        for(int k=0; k<4; k++) {
            int x = i + xdr[k];
            int y = j + ydr[k];
            if(isValid(matrix, x, y, matrix[i][j])) {
               len = max(len,getIncLn(matrix, x, y));
            }
        }
        dp[i][j] = len+1;
        return dp[i][j];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        r = matrix.size();
        if(r==0) return 0;
        c = matrix[0].size();
        visited.resize(r,vector<bool>(c,false));
        dp.resize(r,vector<int>(c,0));
        int max = 0, at_max = 0;
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                at_max = getIncLn(matrix, i, j);
                if(at_max>max) max = at_max;
            }
        }
        return max;
    }
};
