/**

Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?

**/

class Solution {
public:
    int get_max(vector<int> v)
    {
        int mx = 0;
        for(int i=0;i<v.size();i++)
        {
            if(v[i] > mx)
                mx = v[i];
        }
        return mx;

    }
    int lengthOfLIS(vector<int>& v) {
        int s = v.size();
        vector<int> temp(s,1);
        for(int i=0;i<s;i++)
        {
            for(int j=i+1;j<s;j++)
            {
                if(v[i] < v[j])
                {
                    temp[j] = max(temp[i]+1,temp[j]);
                }
            }
        }
        
        return get_max(temp);
    }
};



// or


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        if(nums.empty()) return 0;
        
        int ln = nums.size();
        if(ln==1) return 1;
        
        // as all element itselt LIS of 1 length
        vector<int> dp(ln, 1);
        int max_so_far = 1;
        
        for(int i=1; i<ln; i++) {
            for(int j=0; j<i; j++) {
                if(nums[j] < nums[i]) {
                    dp[i] = max(dp[i], 1+dp[j]);
                    if(dp[i] > max_so_far) 
                        max_so_far = dp[i];    
                }
                    
            }
        }
        return max_so_far;
    }
};
