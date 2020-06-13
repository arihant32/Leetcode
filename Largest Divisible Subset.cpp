/*

Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)
Example 2:

Input: [1,2,4,8]
Output: [1,2,4,8]

*/


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int ln = nums.size();
        if(ln == 0)
            return nums;
        
        sort(nums.begin(), nums.end());
        vector<int> dv(ln, 1);
        vector<int> pre_index(ln, -1);
        vector<int> result;
        
        int max_count = 0;
        
        for(int i=1; i<ln; i++) {
            for(int j=0; j<i; j++) {
                if(nums[i]%nums[j] == 0) {
                    if(dv[i] < dv[j] + 1)
                    {
                        dv[i] = dv[j] + 1;
                        pre_index[i] = j;
                    }
                }
            }
            
            if(dv[max_count] < dv[i])
                max_count = i;
        }
        
        int m = max_count;
        while(m>=0){
           result.push_back(nums[m]);
            m = pre_index[m];
        }
        return result;
    }
};
