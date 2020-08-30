/*

Word Break II

Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
Output:
[
  "cats and dog",
  "cat sand dog"
]
Example 2:

Input:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
Output:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
Explanation: Note that you are allowed to reuse a dictionary word.
Example 3:

Input:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
Output:
[]

*/


// solution one recursive


class Solution {
public:
    
    unordered_set<string> word_set;
    vector<string> results;
    vector<string> temp;
    
    void solve(string s, int index) {
        
        if(s.size() == 0) {
           string ans = "";
           int k;
           for(k=0; k<index-1; k++) {
               ans += temp[k] + " ";
           }
           // in last string no need to add space so above loop till index-1
           ans += temp[k];
           results.push_back(ans); 
        }
        
        for(int i=0; i<=s.size(); i++) {
            string prefix = s.substr(0,i);
            if(word_set.find(prefix) != word_set.end()) {
                temp[index] = prefix;
                string remaining_str = s.substr(i);
                solve(remaining_str, index+1);
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // assign all wordDict to set
        temp.resize(1000);
        for(auto word : wordDict) {
            word_set.insert(word);
        }
        solve(s, 0);
        return results;
    }
};



// or we can solve like below as well



class Solution {
public:
    
    unordered_set<string> word_set;
    vector<string> results;
    vector<string> temp;
    
    void solve(string s) {
        
        if(s.size() == 0) {
           string ans = "";
           int k;
           for(k=0; k<temp.size()-1; k++) {
               ans += temp[k] + " ";
           }
           //in last string no need to add space so above loop till temp.size()-1
           ans += temp[k];
           results.push_back(ans); 
        }
        
        for(int i=0; i<=s.size(); i++) {
            string prefix = s.substr(0,i);
            if(word_set.find(prefix) != word_set.end()) {
                temp.push_back(prefix);
                string remaining_str = s.substr(i);
                solve(remaining_str);
                temp.pop_back();
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // assign all wordDict to set
        for(auto word : wordDict) {
            word_set.insert(word);
        }
        solve(s);
        return results;
    }
};


// with memo

class Solution {
public:
    
    unordered_set<string> word_set;
    unordered_map<string, vector<string>> umap;
    
    vector<string> solve(string s) {
        
        if(umap.find(s) != umap.end()) return umap[s];
        
        vector<string> results;
        
        if(s.size() == 0) {
            results.push_back("");
            return results;
        }
        
        for(int i=0; i<=s.size(); i++) {
            string prefix = s.substr(0,i);
            if(word_set.find(prefix) != word_set.end()) {
                string remaining_str = s.substr(i);
                vector<string> answers = solve(remaining_str);
                for(auto ans : answers) {
                    ans = (ans == "" ? ans : " " + ans);
                    results.push_back(prefix + ans);
                }
            }
        }
        
        umap[s] = results;
        return results;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // assign all wordDict to set
        for(auto word : wordDict) {
            word_set.insert(word);
        }
        return solve(s);
    }
};
