/**

Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

 

Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
Example 2:

Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.
 

Constraints:

1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1

**/

//code :-

class Solution {
public:
    int countSquares(vector<vector<int>>& m) {
        int r = m.size();
        int c = m[0].size();
        
        int num_of_sqr = 0;
        
        // counting number of 1's in first column
        for(int i=0; i<r; i++)
        {
            if(m[i][0] == 1) num_of_sqr++;
        }
        
        // counting number of 1's in first row
        // as m[0][0] needs to be iterate only once and we did it above so starting here i by 1 
        for(int i=1; i<c; i++)
        {
            if(m[0][i] == 1) num_of_sqr++;
        }
        
        for(int i=1; i<r; i++)
        {
            for(int j=1; j<c; j++)
            {
                // as did not take any extra space and modifying same matrix so checking it > 0
                if(m[i][j] > 0)
                {
                    // min of top, left and diagonal
                    m[i][j] = min(min(m[i-1][j], m[i][j-1]), m[i-1][j-1]) + 1;
                    num_of_sqr += m[i][j];
                }
                
            }
        }
        
        return num_of_sqr;
        
    }
};
