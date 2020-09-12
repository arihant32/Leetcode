/*

Combination Sum II

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]


*/


class Solution {
public:
    vector<vector<int>> results;
    // to avoid duplicate
    set<vector<int>> myset;
    vector<int> temp;
    
    void solve(vector<int>& cand, int ln, int target, int index) {
        
        if(target == 0) {
            myset.insert(temp);
            return;
        }
        
        if(target < 0 || index >= ln) 
            return;
        
        for(int i=index; i<ln; i++) {
            temp.push_back(cand[i]);
            solve(cand, ln, target - cand[i], i+1);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // sorting to duplicate combination like [2, 1, 2] or [2, 2 ,1]
        sort(candidates.begin(), candidates.end());
        solve(candidates, candidates.size(), target, 0);
        for(auto s : myset) results.push_back(s);
        return results;
    }
};
