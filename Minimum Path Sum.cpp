/**

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.

**/

class Solution {
public:
    int minPathSum(vector<vector<int>>& v) {
        
        int r = v.size();
        int c = v[0].size();
        
        vector<vector<int>> temp(r,vector<int> (c,0));

        for(int i=0;i<r;i++)
        {
            if(i==0)
                temp[i][0]=v[i][0];
            else
                temp[i][0]=v[i][0]+temp[i-1][0];
        }

        for(int j=0;j<c;j++)
        {
            if(j==0)
                temp[0][j]=v[0][j];
            else
                temp[0][j]=v[0][j]+temp[0][j-1];
        }


        for(int i=1;i<r;i++)
        {
            for(int j=1;j<c;j++)
            {
                if (temp[i][j-1] < temp[i-1][j])
                    temp[i][j] = temp[i][j-1] + v[i][j];
                else
                    temp[i][j] = temp[i-1][j] + v[i][j];
            }

        }


        return temp[r-1][c-1];
        
    }
};
