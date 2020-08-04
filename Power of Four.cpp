/*

Power of Four

Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example 1:

Input: 16
Output: true
Example 2:

Input: 5
Output: false
Follow up: Could you solve it without loops/recursion?

*/

class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num<=0) return false;
        if(!(num & (num-1))) {
           int count_zero = 0;
           while(num>0) {
               if(num%2==0) count_zero++;
               num = num/2;
           }
           return count_zero%2 == 0 ? true : false;
        }
        return false;
    }
};
