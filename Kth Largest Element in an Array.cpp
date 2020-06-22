/*
Kth Largest Element in an Array

Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.


*/


class Solution {
public:
    
    void max_heap(vector<int>& nums, int i, int ln) {
        
        int l = 2*i + 1;
        int r = 2*i + 2;
        int lar = i;
        
        if(l < ln && nums[lar] < nums[l])
            lar = l;
        
        if(r < ln && nums[lar] < nums[r])
            lar = r;
        
        if(i!=lar){
            int tmp = nums[i];
            nums[i] = nums[lar];
            nums[lar] = tmp;
            max_heap(nums, lar, ln);
        }
        
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int ln = nums.size();
        for(int i=(ln/2)-1; i>=0; i--){
            max_heap(nums, i, ln);
        }
    
        for(int i=ln-1; i>=ln-k; i--) {
            int tmp = nums[0];
            nums[0] = nums[i];
            nums[i] = tmp;
            max_heap(nums, 0, i);
        }
        return nums[ln- k];
    }
};
