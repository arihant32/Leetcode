/*

Search in Rotated Sorted Array

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

*/


class Solution {
public:
    int binary_search_index(vector<int>& nums, int l, int h) {
        while(l<=h) {
            int m = (l+h)/2;
            if(m+1<nums.size() && nums[m]>nums[m+1])
                return m+1;
            if(nums[l]>nums[m])
                h = m-1;
            else
                l = m+1;
        }
        return 0;
    }
    
    int binary_search(vector<int>& nums, int l, int h, int target) {
        while(l<=h) {
            int m = (l+h)/2;
            if(nums[m] == target)
                return m;
            if(nums[m]< target)
               l = m+1;
            else
               h = m-1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return -1;
        int l = 0, h = n - 1;
        int pivot_index = binary_search_index(nums, l, h);
        if(nums[pivot_index] == target)
            return pivot_index;
        if(nums[n-1]<target)
            return binary_search(nums, 0, pivot_index-1, target);
        else
            return binary_search(nums, pivot_index, n-1, target);
        return -1;
    }
};
