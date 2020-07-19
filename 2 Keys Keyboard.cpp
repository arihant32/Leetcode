/*

2 Keys Keyboard


Initially on a notepad only one character 'A' is present. You can perform two operations on this notepad for each step:

Copy All: You can copy all the characters present on the notepad (partial copy is not allowed).
Paste: You can paste the characters which are copied last time.
 

Given a number n. You have to get exactly n 'A' on the notepad by performing the minimum number of steps permitted. Output the minimum number of steps to get n 'A'.

Example 1:

Input: 3
Output: 3
Explanation:
Intitally, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.

*/


class Solution {
public:
    int minSteps(int n) {
        int current_A = 1;
        int buffer_A = 0;
        int count_A = 0;
        while(current_A < n) {
            if(n%current_A == 0){
                buffer_A = current_A;
                current_A += buffer_A;
                count_A += 2;
              
            }else{
                current_A += buffer_A;
                count_A += 1;
            }
        }
        return count_A;
    }
};
