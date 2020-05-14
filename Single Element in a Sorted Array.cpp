/**

Link : https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3327/

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.

Example 1:

Input: [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: [3,3,7,7,10,11,11]
Output: 10
 
Note: Your solution should run in O(log n) time and O(1) space.

**/

// code :-

class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int n = a.size();
        int l=0,r=n-1;
        long int m=0;
        int ele=n;
        while(l <= r)
        {
            m = (l+r)/2;
            if(m+1< n && a[m]==a[m+1])
            {
                if(m&1)
                    r = m - 1;
                else
                    l = m + 1;
            }
            else if (m > 0 && a[m] == a[m-1])
            {
                if(m%2 == 0)
                    r = m - 1;
                else
                    l = m + 1;
            } 
            else
            {
                return a[m];
            }
                  
        }
        return -1;
        
    }
};

