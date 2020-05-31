/**

Edit Distance

Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')

**/

class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int l1 = word1.size();
        int l2 = word2.size();
        
        vector<vector<int>> mat(l1+1, vector<int>(l2+1, 0));
        
        //row
        for(int i=1; i<=l1; i++)
            mat[i][0] = mat[i-1][0] + 1;
          
        //col
        for(int j=1; j<=l2; j++)
            mat[0][j] = mat[0][j-1] + 1;
        
        for(int i=1; i<=l1; i++)
        {
            for(int j=1; j<=l2; j++)
            {
                if(word1[i-1] == word2[j-1])
                {
                    //diagonal
                    mat[i][j] = mat[i-1][j-1];
                }
                else
                {
                    // min of (diagonal, top, right)
                    mat[i][j] = 1 + min( min( mat[i-1][j], mat[i][j-1] ), mat[i-1][j-1] );
                }
            }
           
        }
        
        return mat[l1][l2];
    }
};
