/**

Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

**/

class Solution {
public:
    vector<vector<int>> ans;
    
    void to_permute(vector<int> &v,int index,int n)
    {
        if(index==n)
        {
            vector<int> res;
            for(int k=0;k<n;k++)
                res.push_back(v[k]);
            ans.push_back(res);
            return;
        }
        for(int i=index; i<n; i++)
        {
            int temp = v[index];
            v[index] = v[i];
            v[i] = temp;
            to_permute(v, index+1,n);
            temp = v[index];
            v[index] = v[i];
            v[i] = temp;
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        to_permute(nums,0,nums.size());
        return ans;
    }
};
