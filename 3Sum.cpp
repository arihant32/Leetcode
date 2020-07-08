/*

3Sum


Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int ln = nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>> s;
        for(int i=0; i<ln-2; i++) {
            int a = nums[i];
            if(i>0 && nums[i]==nums[i-1]) continue;
            int l = i+1;
            int h = ln-1;
            while(l<h) {
                int b = nums[l];
                int c = nums[h];
                int total = a+b+c;
                if(total==0) s.insert({a, b, c});    
                if(total>0) h--;
                else l++;
            }
        }
        for(auto v : s) result.push_back(v);
        return result;
    }
};
