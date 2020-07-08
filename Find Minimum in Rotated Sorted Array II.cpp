/*

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

The array may contain duplicates.

Example 1:

Input: [1,3,5]
Output: 1
Example 2:

Input: [2,2,2,0,1]
Output: 0
Note:

This is a follow up problem to Find Minimum in Rotated Sorted Array.
Would allow duplicates affect the run-time complexity? How and why?

*/


class Solution {
public:
    
    int get_min_using_binary_search(vector<int>& nums, int l, int h) {
        // as in duplicate numbser case array begning and ending elements might be same
        // eg : [10,1,10,10,10]
        //      [10,10,10,1,10,10]
        while(h>0 && nums[l]==nums[h]) h--;
        while(l<=h) {
            int m = (l+h)/2;
            if(m+1<nums.size() && nums[m]>nums[m+1])
                return nums[m+1];
            else if(nums[l]>nums[m])
                h = m-1;
            else
                l = m+1;
        }
        return nums[0];
    }
    
    int findMin(vector<int>& nums) {
        int ln = nums.size();
        return get_min_using_binary_search(nums, 0, ln-1);
    }
};
