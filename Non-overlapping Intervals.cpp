/*

Non-overlapping Intervals

Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

 

Example 1:

Input: [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
Example 2:

Input: [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.
Example 3:

Input: [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.

*/


class Solution {
public:
    
    static bool myCompare(vector<int> &a, vector<int> &b) {
        return (a[1] < b[1]);
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ln = intervals.size();
        if(ln==0) return 0;
        // sort vector based on end time
        sort(intervals.begin(), intervals.end(), myCompare);
        int count = 0;
        int initial_end_time = intervals[0][0];
        for(auto interval : intervals) {
            // interval[0] -> start time
            // interval[1] -> end time
            if(interval[0] < initial_end_time)
                count++;
            else
               initial_end_time =  interval[1];
        }
        return count;
    }
};
