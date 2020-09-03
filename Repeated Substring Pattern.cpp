/*

Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

 

Example 1:

Input: "abab"
Output: True
Explanation: It's the substring "ab" twice.
Example 2:

Input: "aba"
Output: False
Example 3:

Input: "abcabcabcabc"
Output: True
Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)

*/

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int ln = s.size();
        for(int l=ln/2; l>0; l--) {
            if(ln%l == 0){
                int i=0;
                while(i+l <ln && s[i] == s[i+l]){
                    i++;
                }
                if(i+l == ln) return true;
            }
        }
        return false;
    }
};
