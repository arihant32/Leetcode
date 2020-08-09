/*

Longest Substring Without Repeating Characters


Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
             
 */
 
 
 class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ln = s.size();
        int l=0, r=0;
        set<char> myset;
        int longest_len = 0;
        while(l<ln && r<ln){
            if(myset.find(s[r]) == myset.end()) {
                myset.insert(s[r]);
                if(myset.size()>longest_len) 
                    longest_len = myset.size();
                r++;
            }
            else
            {
              myset.erase(s[l]);
              l++;
            }
        }
        return longest_len;
    }
    
};
