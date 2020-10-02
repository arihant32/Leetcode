/**

Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]

**/

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> res;
    
    void find_sum(vector<int> &can,int t,int ln,int index)
    {
        if(t==0)
        {
            ans.push_back(res);
            return;
        }
        if(t < 0 || index >=ln)
            return;
        res.push_back(can[index]);
        find_sum(can,t-can[index],ln,index);
        res.pop_back();
        find_sum(can,t,ln,index+1);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       find_sum(candidates,target,candidates.size(),0);
        return ans;
    }
    
};



// or


class Solution {
public:
    
    vector<vector<int>> results;
    vector<int> temp;
    
    void generate_combination(vector<int>& candidates, int target, int index) {
        if(target == 0)
            results.push_back(temp);
        
        if(target < 0 || index >= candidates.size())
            return;
        
        for(int i = index; i<candidates.size(); i++) {
            temp.push_back(candidates[i]);
            generate_combination(candidates, target - candidates[i], i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        generate_combination(candidates, target, 0);
        return results;
    }
};
