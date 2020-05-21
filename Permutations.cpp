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
    
    void to_permute(vector<int> &v,int i,int n)
    {
        if(i==n)
        {
            vector<int> res;
            for(int k=0;k<n;k++)
                res.push_back(v[k]);
            ans.push_back(res);
            return;
        }
        for(int j=i;j<n;j++)
        {
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            to_permute(v,i+1,n);
            temp=v[i];
            v[i] = v[j];
            v[j] = temp;
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        to_permute(nums,0,nums.size());
        return ans;
    }
};
