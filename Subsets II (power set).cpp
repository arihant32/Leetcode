/*

Subsets II (power set)

Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

*/


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        
        set<vector<int>> s;
        
        int ln = nums.size();
        
        int pset_count = pow(2,ln);
        
        sort(nums.begin(),nums.end());
        
        for(int i=0; i<pset_count; i++) {
            vector<int> temp;
            for(int j=0; j<ln; j++) {
                if(i & (1<<j)) {
                    temp.push_back(nums[j]);
                }
            }
            s.insert(temp);
        }
        for(auto v : s) result.push_back(v);
        return result;
    }
};
