/*

Word Break

https://www.youtube.com/watch?v=1U4jQusbeJc


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


// Solution one : Brute force

class Solution {
public:
    
    bool solve(string s, vector<string>& wordDict) {
        // if anytime our 's' become empty "" then we can say we found the answer
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


// memo solution

class Solution {
public:
    
    bool solve(string s, vector<string>& wordDict, unordered_map<string, bool> &memo) {
        // if anytime our 's' become empty "" then we can say we found the answer
        if(s.size() == 0) return true;
        if(memo[s]) return memo[s];
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
                if(solve(new_s, wordDict, memo)) {
                    memo[s] = true;
                    return true;  
                }
            }
        }
        memo[s] = false;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
       unordered_map<string, bool> memo;
       return solve(s, wordDict, memo);
    }
};


// solution 3rd


class Solution {
public:
    
    unordered_set<string> word_set;
    
    bool solve(string s) {
        
        if(s.size() == 0) return true;
        
        for(int i=0; i<=s.size(); i++) {
            string prefix = s.substr(0,i);
            if(word_set.find(prefix) != word_set.end()) {
                string remaining_str = s.substr(i);
                if(solve(remaining_str)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        // assign all wordDict to set
        for(auto word : wordDict) {
            word_set.insert(word);
        }
        return solve(s);
    }
};


// 4th with memo and submitted

class Solution {
public:
    
    unordered_set<string> word_set;
    unordered_map<string, bool> memo;
    
    bool solve(string s) {
        
        if(s.size() == 0) return true;
        
        if(memo.find(s) != memo.end()) return  memo[s];
        
        for(int i=0; i<=s.size(); i++) {
            string prefix = s.substr(0,i);
            if(word_set.find(prefix) != word_set.end()) {
                string remaining_str = s.substr(i);
                if(solve(remaining_str)) {
                    memo[s] = true;
                    return true;
                }
            }
        }
        memo[s] = false;
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        // assign all wordDict to set
        for(auto word : wordDict) {
            word_set.insert(word);
        }
        return solve(s);
    }
};
