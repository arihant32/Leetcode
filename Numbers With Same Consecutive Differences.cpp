/*

Numbers With Same Consecutive Differences


Return all non-negative integers of length N such that the absolute difference between every two consecutive digits is K.

Note that every number in the answer must not have leading zeros except for the number 0 itself. For example, 01 has one leading zero and is invalid, but 0 is valid.

You may return the answer in any order.

 

Example 1:

Input: N = 3, K = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.
Example 2:

Input: N = 2, K = 1
Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
 

Note:

1 <= N <= 9
0 <= K <= 9


*/


class Solution {
public:
    vector<int> results;
    void generate(int start, int n, int k) {
        string ss = to_string(start);
        if(ss.size() == n) {
            results.push_back(start);
            return;
        }
        
        if(ss.size() > n) return;
        // getting last single digit eg : 153 we get 3
        int single_digit = start%10;
        // checking diff is k 
        int minus = single_digit - k;
        int plus = single_digit + k;
        
        // as no need to take negative number and two digits (plus or minus variables) 
        if(minus>=0 && minus<=9)
             // making two or more digit number like
             generate(start*10+minus, n, k);
        
        if(plus>=0 && plus<=9 && minus !=plus )
            // making two or more digit number like
            generate(start*10+plus, n, k);
    }
    vector<int> numsSameConsecDiff(int N, int K) {
        if(N==1 && K==0) results.push_back(0);
        int start_digit = 1;
        if(N==1 && K!=0) start_digit = 0;
        for(int i=start_digit; i<=9; i++) generate(i, N, K);
        return results;
    }
};

