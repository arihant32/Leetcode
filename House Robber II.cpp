/**

House Robber II : https://leetcode.com/problems/house-robber-ii/

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
             because they are adjacent houses.
Example 2:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
**/



class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        int ln = nums.size();
        if(ln == 1) return nums[0];
        
        vector<int> dp(ln);
        
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        if(ln == 2) return dp[ln-1];
        // case one -> not robing last house as arranged in a circle.
        for(int i=2; i<ln-1; i++) {
            //current house + 1 house previous
            // or previous
            // [0] [1] [2]
            dp[i] = max(nums[i]+dp[i-2], dp[i-1]);  
        }
        
        int case_one_ans = dp[ln-2];
        dp.clear();
        dp.resize(ln);
        // case two -> not robing first house as arranged in a circle.
        dp[1] = nums[1];
        dp[2] = max(nums[2], nums[1]);
        for(int i=3; i<ln; i++) {
            //current house + 1 house previous
            // or previous
            // [0] [1] [2]
            dp[i] = max(nums[i]+dp[i-2], dp[i-1]);  
        }
        
        int case_two_ans = dp[ln-1];
        return max(case_one_ans, case_two_ans);
            
    }
};
