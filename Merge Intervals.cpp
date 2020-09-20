/**

Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

**/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& vv) {
        
        vector<vector<int>> ans;
        sort(vv.begin(),vv.end());
        
        int i=0;
        int x, y;
        
        while(i < vv.size()) {
            
            x=vv[i][0];
            y=vv[i][1];
            
            for(int j=i+1;j<vv.size();j++)
            {
               if(y >= vv[j][0])
               {
                   if(y < vv[j][1])
                       y=vv[j][1];
                   i++;
               }
              else
              {
                  ans.push_back({x,y});
                  break;
              }
            }
            
            if(i+1 == vv.size()) ans.push_back({x,y});
            
            i++;
        }
        
        return ans;
    }
};
