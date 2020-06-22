/*

Sliding Window Maximum


Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.

Follow up:
Could you solve it in linear time?

Example:

Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7] 
Explanation: 

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
 

Constraints:

1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
1 <= k <= nums.length
Accepted
263,241
Submissions
619,846



*/



class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int ln = nums.size();
        deque<int> dq;
        for(int i=0; i<k; i++) {
            while(!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);
        }
        
        for(int i=k; i<ln; i++) {
            ans.push_back(nums[dq.front()]);
            
            while(!dq.empty() && dq.front() <= i-k)
                dq.pop_front();
                
            while(!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            
            dq.push_back(i);
        }
        
        // Print the maximum element of last window 
        ans.push_back(nums[dq.front()]);

        return ans;  
    }
};
