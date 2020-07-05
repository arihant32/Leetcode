/*

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

You may assume no duplicate exists in the array.

Example 1:

Input: [3,4,5,1,2] 
Output: 1
Example 2:

Input: [4,5,6,7,0,1,2]
Output: 0

*/


class Solution {
public:
    int binary_search(vector<int>& nums, int l, int h) {
        
        while(l<=h) {
            
            int mid = (l+h)/2;
            if(mid+1 < nums.size() && nums[mid] > nums[mid+1])
                return nums[mid+1];
            
            if(nums[l] > nums[mid])   h = mid-1;
            else l = mid+1;
            
        }
        // given array is sorted only
        return nums[0];
    }
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;
        return binary_search(nums, low, high);
    }
};
