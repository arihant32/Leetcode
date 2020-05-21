/**

Largest Rectangle in Histogram : https://leetcode.com/problems/largest-rectangle-in-histogram/

Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

 


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

 


The largest rectangle is shown in the shaded area, which has area = 10 unit.

 

Example:

Input: [2,1,5,6,2,3]
Output: 10


**/

//code :

class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n= h.size();
        if(n==0)
            return 0;
        stack<int> s;
        int i=0;
        int max=0;
        int area = 0;
        while(i < n)
        {
            if(s.empty() || h[s.top()] <= h[i])
            {
                 s.push(i);
                 i++;
            } 
            else
            {
                    int val = s.top();
                    s.pop();
                    if(s.empty())
                        area = h[val]*i;
                    else
                       area = h[val]*(i-1-s.top());
                    if(area>max)
                        max=area;
            }
            
        }
        while(!s.empty())
        {
            int val = s.top();
            s.pop();
            if(s.empty())
                area = h[val]*i;
            else
               area = h[val]*(i-1-s.top());
            if(area>max)
                max=area;
        }
        return max;    
        
    }
};
