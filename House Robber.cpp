/**

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.
 

Constraints:

0 <= nums.length <= 100
0 <= nums[i] <= 400

**/


// Recursion Solution

class Solution {
public:
    int get_max_money(vector<int>& nums, int i, int n)
    {
        if(i>=n) return 0;
        int with_rob = nums[i] + get_max_money(nums, i+2, n);
        int without_rob = get_max_money(nums, i+1, n);
        return max(with_rob, without_rob);
    }
    int rob(vector<int>& nums) {
        return get_max_money(nums, 0, nums.size());
    }
};


// DP memoization solution


class Solution {
public:
    
    int get_max_money(vector<int>& nums, vector<int>& dp, int i, int n)
    {
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int with_rob = nums[i] + get_max_money(nums, dp, i+2, n);
        int without_rob = get_max_money(nums, dp, i+1, n);
        dp[i] = max(with_rob, without_rob);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int ln = nums.size();
        vector<int> dp(ln, -1);
        return get_max_money(nums, dp, 0, ln);
    }
};


// DP Solution


class Solution {
public:
    
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        int ln = nums.size();
        if(ln == 1) return nums[0];
        vector<int>dp(ln);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i=2; i<ln; i++) {
            //current house + 1 house previous
            // or previous
            // [0] [1] [2]
            dp[i] = max(nums[i]+dp[i-2], dp[i-1]);
        }
        
        return dp[ln-1];
    }
};
