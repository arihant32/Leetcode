/*

Subsets (power set)

Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

*/


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        int ln = nums.size();
        int pset_count = pow(2,ln);
        for(int i=0; i<pset_count; i++) {
            vector<int> temp;
            for(int j=0; j<ln; j++) {
                if(i & (1<<j)) {
                    temp.push_back(nums[j]);
                }
            }
            result.push_back(temp);
        }
        return result;
    }
};
