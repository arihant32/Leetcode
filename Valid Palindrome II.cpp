/*

Valid Palindrome II

Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:
Input: "aba"
Output: True
Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.
Note:
The string will only contain lowercase characters a-z. The maximum length of the string is 50000.

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
    bool validPalindrome(string s) {
        int ln = s.size();
        int l=0, h=ln-1;
        while(l<h) {
            if(s[l] != s[h]) {
                // if not match then removed one char from left side and check we can make Palindrome
                // if not then removed one char from right side and check we can make Palindrome
                return isPalind(s, l+1, h) || isPalind(s, l, h-1);
            }
            l++;
            h--;
        }
        return true;
    }
};
