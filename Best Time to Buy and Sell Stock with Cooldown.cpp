/*

Best Time to Buy and Sell Stock with Cooldown


Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

Input: [1,2,3,0,2]
Output: 3 
Explanation: transactions = [buy, sell, cooldown, buy, sell]


*/


// recursive solution


class Solution {
public:
    
    int get_max_profit(vector<int>& prices, int i, bool buy_or_sell) {
        if(i>=prices.size()) return 0;
        int max_pro=0;
        if(buy_or_sell) {
            int buy = get_max_profit(prices, i+1, false) - prices[i];
            int no_buy = get_max_profit(prices, i+1, true);
            max_pro = max(buy, no_buy);
        }else{
            int sell = get_max_profit(prices, i+2, true) + prices[i];
            int no_sell = get_max_profit(prices, i+1, false);
            max_pro = max(sell, no_sell);
        }
        return max_pro;
    }
    int maxProfit(vector<int>& prices) {
        // true -> buy, flase -> sell
        return get_max_profit(prices, 0, true);
    }
};



// with memoization


class Solution {
public:
    
    map<string, int> mp;
    
    int get_max_profit(vector<int>& prices, int i, bool buy_or_sell) {
        if(i>=prices.size()) return 0;
        
        string key = to_string(i);
        key = buy_or_sell ? key+"buy" : key+"sell";
        
        if(mp.find(key) != mp.end())
            return mp[key];
        
        int max_pro=0;
        if(buy_or_sell) {
            int buy = get_max_profit(prices, i+1, false) - prices[i];
            int no_buy = get_max_profit(prices, i+1, true);
            max_pro = max(buy, no_buy);
        }else{
            int sell = get_max_profit(prices, i+2, true) + prices[i];
            int no_sell = get_max_profit(prices, i+1, false);
            max_pro = max(sell, no_sell);
        }
        
        mp[key] = max_pro;
        return max_pro;
    }
    int maxProfit(vector<int>& prices) {
        // true -> buy, flase -> sell
        return get_max_profit(prices, 0, true);
    }
};
