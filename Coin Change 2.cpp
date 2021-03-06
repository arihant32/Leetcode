/**

Coin Change 2 :

You are given coins of different denominations and a total amount of money. Write a function to compute the number of combinations that make up that amount. You may assume that you have infinite number of each kind of coin.

 

Example 1:

Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10] 
Output: 1
 

Note:

You can assume that

0 <= amount <= 5000
1 <= coin <= 5000
the number of coins is less than 500
the answer is guaranteed to fit into signed 32-bit integer
**/

// Resursion solution

class Solution {
public:
    int get_combinations(int amount, vector<int>& coins, int index, int n) {
        
        if(amount==0) return 1;
        if(amount < 0 || index >= n) return 0;
        int ans = 0;
        for(int i=index; i<n; i++) {
            ans +=get_combinations(amount - coins[i], coins, i, n);
        }
        return ans;
        
    }
    int change(int amount, vector<int>& coins) {
        return get_combinations(amount, coins, 0, coins.size());
    }
};


// DP

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(coins.empty() && amount==0) return 1;
        if(coins.empty()) return 0;
        
        int ln = coins.size();
        vector<vector<int>>dp (ln+1, vector<int>(amount+1, 0));
        
        for(int i=0; i<=ln; i++)
            dp[i][0] = 1;
        
        for(int i=1; i<=ln; i++) {
            for(int j=1; j<=amount; j++) {
                // not taking coin -> top
                // taking coin j-coins[i-1] and still in same row
                dp[i][j] = dp[i-1][j] + (j-coins[i-1]<0 ? 0 : dp[i][j-coins[i-1]]); 
            }
        }
        return dp[ln][amount];
    }
};
