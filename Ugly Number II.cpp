/*

Ugly Number II

Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

Example:

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
Note:  

1 is typically treated as an ugly number.
n does not exceed 1690.

*/

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp_ugly(n);
        dp_ugly[0] = 1;
        
        int nm2, nm3, nm5;
        int i2=0, i3=0, i5=0;
        
        for(int i=1; i<n; i++) {
            
            nm2 = 2*dp_ugly[i2];
            nm3 = 3*dp_ugly[i3];
            nm5 = 5*dp_ugly[i5];
            
            int ugly_no = min(min(nm2, nm3), nm5);
            dp_ugly[i] = ugly_no;
            
            if(nm2 == ugly_no) i2++;
            if(nm3 == ugly_no) i3++;
            if(nm5 == ugly_no) i5++;
            
        }
        
        return dp_ugly[n-1];
    }
};
