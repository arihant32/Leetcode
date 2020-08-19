/**

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

https://www.youtube.com/watch?v=UflHuQj6MVA

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"

**/



// Solution One without DP


class Solution {
public:
    string longestPalindrome(string s) {
        int ln = s.size();
        if(ln==0) return "";
        int max_len = 0;
        int start = 0, end = 0;
        for(int i=0; i<ln; i++) {
            // odd length
            int l = i-1;
            int h = i+1;
            while(l<h) {
                if(l>=0 && h<ln && s[l] == s[h]) {
                    if(h-l+1 > max_len) {
                        max_len = h-l+1;
                        start = l;
                        end = h;
                    }
                    l--;
                    h++;
                } else{
                    break;
                }
            }
            // even length
            l = i;
            h = i+1;
            while(l<h) {
                if(l>=0 && h<ln && s[l] == s[h]) {
                    if(h-l+1 > max_len) {
                        max_len = h-l+1;
                        start = l;
                        end = h;
                    }
                    l--;
                    h++;
                } else{
                    break;
                }
            }
            
        }
        string ps = "";
        for(int i=start; i<=end; i++) ps += s[i];
        return ps;
    }
};



// Solution two with DP


class Solution {
public:
    string longestPalindrome(string s) {
        int ln = s.size();
        if(ln==0) return "";
        vector<vector<bool>> dp(ln, vector<bool>(ln, false));
        
        // char with one length is always palindrome
        // Eg :  "baabad"
        
        for(int i=0; i<ln; i++) {
            dp[i][i] = true;
        }
        
        // for(int i=0; i<ln; i++) {
        //     for(int j=0; j<ln; j++) {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
                 // End
            // 1 0 0 0 0 0 
            // 0 1 0 0 0 0 
   //start  // 0 0 1 0 0 0 
            // 0 0 0 1 0 0 
            // 0 0 0 0 1 0 
            // 0 0 0 0 0 1 

        // Now Store all two length palindrome if s[i]==s[i+1] then is a palindrome of two lenght eg : bb 
        for(int i=0; i<ln-1; i++) {
            if(s[i] == s[i+1]) {
                dp[i][i+1] = true;
            }
        }
        
        // 1 0 0 0 0 0 
        // 0 1 1 0 0 0 
        // 0 0 1 0 0 0 
        // 0 0 0 1 0 0 
        // 0 0 0 0 1 0 
        // 0 0 0 0 0 1 
        
        // for all three and greater length string 
        // so 'bab' is a palindrome if first and last char are same and inner substring is palindrome so           // over all string is palindrome.
        
        for(int k=0; k<ln-2; k++) {
            int i=0;
            for(int j=k+2; j<ln; j++) {
                if(s[i]==s[j] && dp[i+1][j-1]==true) {
                    dp[i][j] = true;
                }
                i++;
            }
        }
        
        // now get the Longest Palindromic Substring
        int start = 0, end = 0, count = 0;
        for(int i=0; i<ln; i++) {
            for(int j=0; j<ln; j++) {
                if(dp[i][j]==true) {
                    if(j-i+1>count) {
                        count = j-i+1;
                        start = i;
                        end = j;
                    }
                }
            }
        }
        
        string ps="";
        while(start<=end)
        {
            ps+=s[start];
            start++;
        }
        
        return ps;
    }
};
