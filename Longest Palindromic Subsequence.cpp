/*

Longest Palindromic Subsequence

Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

Example 1:
Input:

"bbbab"
Output:
4
One possible longest palindromic subsequence is "bbbb".
 

Example 2:
Input:

"cbbd"
Output:
2
One possible longest palindromic subsequence is "bb".

*/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int ln = s.size();
        vector<vector<int>> dp(ln+1, vector<int>(ln+1, 0));
        // reverse s
        string rs = s;
        reverse(rs.begin(), rs.end());
        //cout<<rs;
        // Now using Longest Common Subsequence code 
        // for string 's' and reverse string 'rs'
        for(int i=1; i<=ln; i++) {
            for(int j=1; j<=ln; j++) {
                if(s[i-1] == rs[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[ln][ln];
    }
};
