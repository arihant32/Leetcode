/**

Coin Change

You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3 
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Note:
You may assume that you have an infinite number of each kind of coin.


**/


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // say amount is 11 so we will try to make all amount from 0 to 11
        // initialize it to INT_MAX
        vector<long int>dp(amount+1, INT_MAX);
        
        dp[0] = 0;
        
        // to iterate all amounts
        for(int i=0; i<=amount; i++) {
            // to iterate all given coins
            for(int j=0; j<coins.size(); j++) {
                // say coin 5 and amount that is i -> 8
                if(coins[j] <= i) 
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            }
        }
        
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
