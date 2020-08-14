/*

Longest Palindrome

Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.

*/

class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> f(128,0);
        int max_len = 0;
        for(int i=0; i<s.size(); i++) f[s[i]]++;
        int even_count = 0;
        int odd_count = 0;
        int max_odd = -1;
        for(int i=0; i<128; i++) {
            if(f[i]%2 == 0){
               even_count += f[i];
            }else{
                odd_count += (f[i]-1);
                if(f[i] > max_odd){
                    max_odd = f[i];
                }     
            }
        }
        
        if(max_odd != -1) odd_count = odd_count + 1;
        max_len = even_count + odd_count;
        return max_len;
    }
};
