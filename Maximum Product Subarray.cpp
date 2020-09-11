/*

Maximum Product Subarray

Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

*/


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pre_max_pro = nums[0];
        int pre_min_pro = nums[0];
        int curr_max_pro = nums[0];
        int curr_min_pro = nums[0];
        int ans = nums[0];
        
        for(int i=1; i<nums.size(); i++) {
            curr_max_pro = max( max(pre_max_pro * nums[i], pre_min_pro * nums[i]), nums[i] );
            curr_min_pro = min( min(pre_max_pro * nums[i], pre_min_pro * nums[i]), nums[i] );
            if(curr_max_pro > ans) 
                ans = curr_max_pro;
            pre_max_pro = curr_max_pro;
            pre_min_pro = curr_min_pro;
            
        }
        return ans;
    }
};
