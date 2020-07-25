/*

Subsets

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
    
    vector<vector<int>> result;
    
    void generate_sets(vector<int> &nums, int ind, vector<int> &temp) {
        result.push_back(temp);
        for(int i=ind; i<nums.size(); i++){
            temp.push_back(nums[i]);
            generate_sets(nums, i+1, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        generate_sets(nums, 0, temp);
        return result;
    }
};

