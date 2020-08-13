/*

Meeting Rooms II


Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

Example 1:

Input: [[0, 30],[5, 10],[15, 20]]
Output: 2
Example 2:

Input: [[7,10],[2,4]]
Output: 1

*/


class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> start_time;
        vector<int> end_time;
        for(auto arr : intervals) {
            start_time.push_back(arr[0]);
            end_time.push_back(arr[1]);
        }
        sort(start_time.begin(), start_time.end());
        sort(end_time.begin(), end_time.end());
        
        int i = 0, j = 0, max = 0, count = 0;
        while(i<start_time.size() && j<end_time.size()) {
            if(start_time[i]<end_time[j]) {
                count++;
                i++;
            }else{
                count--;
                j++;
            }
            if(count>max) max = count;
        }
        return max;
    }
};
