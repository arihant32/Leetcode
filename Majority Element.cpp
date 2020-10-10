/*

Majority Element

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2

*/


class Solution {
public:
    int getCandidate(vector<int>& nums) {
        int count = 0, maj_index = 0;
        for(int i = 0; i<nums.size(); i++) {
            if(nums[maj_index] == nums[i]) 
                count++;
            else
                count--;
            if(count == 0) {
                maj_index = i;
                count = 1;
            }
        }
        
        return nums[maj_index];
    }
    
    int majorityElement(vector<int>& nums) {
        //  Using Moore’s Voting Algorithm
        int candidate = getCandidate(nums);
        int count = 0, ln = nums.size();
        
        for(int i=0; i<ln; i++){
            if(nums[i] == candidate)
                count++;
            if(count > ln/2) return candidate;
        }
        return -1;
    }
};
