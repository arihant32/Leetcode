/**

Trapping Rain Water : https://leetcode.com/problems/trapping-rain-water/

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6

**/

// code :

class Solution {
public:
    int trap(vector<int>& height) {
        int ln = height.size();
        if(ln==1 || ln==0)
            return 0;
        vector<int> max_left(ln,0);
        vector<int> max_right(ln,0);
        max_left[0] = height[0];
        max_right[ln-1] = height[ln-1];
        int i=1;
        while(i<ln)
        {
            if (height[i] > max_left[i-1])
                max_left[i] = height[i];
            else
                max_left[i] = max_left[i-1];
            i++;
        }
        i=ln-2;
        while(i>=0)
        {
            if (height[i] > max_right[i+1])
                max_right[i] = height[i];
            else
                max_right[i] = max_right[i+1];
            i--;
        }
        i=0;
        int area = 0;
        while(i < ln)
        {
            area = area + min(max_left[i],max_right[i]) - height[i];
            i++;
        }
        return area; 
    }
};
