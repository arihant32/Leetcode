/*

Palindromic Substrings

Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:

Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
 

Example 2:

Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

*/

class Solution {
public:
    
    bool isPalind(string s, int i, int j) {
        while(i<j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    int countSubstrings(string s) {
        int ln = s.size();
        int count = ln;
        for(int i=1; i<ln; i++) {
           for(int j=0; j<i; j++) {
               if(isPalind(s,j, i)) count++;
           }
        }
        return count;
    }
};
