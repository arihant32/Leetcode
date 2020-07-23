/*
Single Number III
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.
Example:
Input:  [1,2,1,3,2,5]
Output: [3,5]
Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
*/


class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans(2, 0);
        int ln = nums.size();
        int xor_of_2no = 0;
        for(int i=0; i<ln; i++) xor_of_2no ^= nums[i];
        // now find the right most set bit of the xor
        // formula number with bitwise & and it's 2's complement
        int right_most_set_bit = xor_of_2no & (-xor_of_2no);
        // now filter all the element in two group with 1 set bit and 0 set and take xor
        for(int i=0; i<ln; i++) {
            if(nums[i] & right_most_set_bit) // if right_most_set_bit is one
                ans[0] ^= nums[i];
            else // if right_most_set_bit is zero
                ans[1] ^= nums[i];
        }
        return ans;     
    }
};
