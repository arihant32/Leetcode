/*

Word Break


Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false

*/


// Solution one :

class Solution {
public:
    
    bool solve(string s, vector<string>& wordDict) {
        if(s.size() == 0) return true;
        // using all words one by one
        for(int i=0; i<wordDict.size(); i++){
            // say wordDict = ["leet", "code"] and s = "leetcode"
            // so will take the 1st word that is "leet" from wordDict
            // and now take the prefix from string s with same length of above taken word
            // if our word and prefix is same then pass the remaining 's' to recorsive function and so on
            string w = wordDict[i];
            string prefix = s.substr(0, w.size()); // taking prefix
            if(w.compare(prefix) == 0) { // if both are same
                string new_s = s.substr(prefix.size()); // taking remaining string s that is 'code'
                if(solve(new_s, wordDict))
                   return true;
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
       return solve(s, wordDict);
    }
};
