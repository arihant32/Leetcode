/*

Insert Interval

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.



*/



class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> results;
        
        int i = 0, ln = intervals.size();
        
        // adding non overlapping in the our answer
        while(i < ln && intervals[i][1] < newInterval[0]) {
            results.push_back(intervals[i]);
            i++;
        }
        
        // now finding overlapping then will add in the answer
        int merge_start = newInterval[0], merge_end = newInterval[1];
        while(i < ln && intervals[i][0] <= newInterval[1]) {
            merge_start = min(merge_start, intervals[i][0]);
            merge_end = max(merge_end, intervals[i][1]);
            i++;
        }
        
        results.push_back({merge_start, merge_end});
            
        // now adding rest non overlapping in the answer
        while(i < ln) {
            results.push_back(intervals[i]);
            i++;
        }
       
        return results;
    }
};
