/**

Given a string s and a string t, check if s is subsequence of t.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

Follow up:
If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. In this scenario, how would you change your code?

Credits:
Special thanks to @pbrother for adding this problem and creating all test cases.

 

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false
 

Constraints:

0 <= s.length <= 100
0 <= t.length <= 10^4
Both strings consists only of lowercase characters.

**/


class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        if(s.empty()) return true;
        
        int s_ln = s.size();
        int t_ln = t.size();
        
        vector<vector<int>> dp(s_ln+1, vector<int>(t_ln+1,0));
        // using logic of LCS and at the end if we found LCS of length s_ln 
        // then we can say s is a subsequence of t.
        for(int i=1; i<=s_ln; i++) {
            for(int j=1; j<=t_ln; j++) {
                // [diagonal] [top]
                // [left]     [here] 
                // match -> take diagonal + 1
                if(s[i-1] == t[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    // not match -> take max of left and top
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);   
            }   
        }
        
        return dp[s_ln][t_ln] ==  s_ln ? true : false;
    }
};


