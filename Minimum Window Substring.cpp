/*

Minimum Window Substring

https://www.youtube.com/watch?v=b9OgfHDFNlo

Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.

*/


class Solution {
public:
    string minWindow(string s, string t) {
        int sln = s.size();
        int tln = t.size();
        string result = "";
        if(tln>sln) return result;
        map<char,int> text_map;
        for(auto ch : t) {
            text_map[ch] +=1;
        }
        
        int required_char_for_match = text_map.size();
        int r=0, l=0, match=0, min_sub_str_len = INT_MAX;
        int min_win_start = 0, min_win_end = 0;
        bool found = false;
        map<char,int> window_map;
        while(r<sln) {
            char c = s[r];
            window_map[c] +=1;
            if(text_map.find(c)!=text_map.end() && window_map[c] == text_map[c])
                match++;
            while(l<=r && match==required_char_for_match) {
                char ch = s[l];
                if(min_sub_str_len > (r-l+1)) {
                    found = true;
                    min_sub_str_len = (r-l+1);
                    min_win_start = l;
                    min_win_end = r;
                }
                // remove this ch from current window
                window_map[ch] -=1;
                if(text_map.find(ch)!=text_map.end() && window_map[ch]<text_map[ch])
                    match--;
                l++;
            }
            r++;
        }
        if(found) {
            for(int i=min_win_start; i<=min_win_end; i++)
                result += s[i];
        }
        return result;
    }
};
