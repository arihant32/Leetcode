/**

Link : https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3323/

You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.

Example 1:
Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true

Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false

Constraints:

2 <= coordinates.length <= 1000
coordinates[i].length == 2
-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
coordinates contains no duplicate point.

**/

#Code : -

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& cor) {
        int n = cor.size(),i=1;
        float initial,slpoe;
        initial = float(cor[1][1]-cor[0][1])/float(cor[1][0]-cor[0][0]);
        while(i<n-1)
        {
            slpoe = (float)(cor[i+1][1]-cor[i][1])/(float)(cor[i+1][0]-cor[i][0]);
            if(slpoe!=initial)
                return false;
            i++;
        }
        return true;
    }
};

