/*

Add Digits

Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

Example:

Input: 38
Output: 2 
Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2. 
             Since 2 has only one digit, return it.
Follow up:
Could you do it without any loop/recursion in O(1) runtime?

*/


// solution one

class Solution {
public:
    int helper(int n, int &sum) {
        if(n==0) return sum;
        sum = sum + n%10;
        return helper(n/10, sum);
    }
    
    int addDigits(int num) {
        while(!(num>=0 && num<=9)) {
            int sum = 0;
            num = helper(num, sum);
        }
        return num;
    }
};



// solution two

class Solution {
public:
    int addDigits(int num) {
        if(num==0) return 0;
        if(num%9==0) return 9;
        return num%9;
    }
};
