/*

Perfect Squares

Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.


*/


class Solution {
public:
    int run_recursion(int n, vector<int> &dp) {
        if(n<0) return INT_MAX;
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        // it take at least n say used 1*1 + 1*1 + 1*1 + 1*1 ... an so on
        int min_yet = n;
        for(int i=1; i*i<=n; i++){
            min_yet = min(run_recursion(n-i*i, dp), min_yet);
        }
        dp[n] = min_yet+1;
        return min_yet+1;
    }
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return run_recursion(n, dp);
    }
};
