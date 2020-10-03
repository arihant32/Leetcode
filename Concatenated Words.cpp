/*

Concatenated Words


Given a list of words (without duplicates), please write a program that returns all concatenated words in the given list of words.
A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.

Example:
Input: ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]

Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]

Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats"; 
 "dogcatsdog" can be concatenated by "dog", "cats" and "dog"; 
"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
Note:
The number of elements of the given array will not exceed 10,000
The length sum of elements in the given array will not exceed 600,000.
All the input string will only include lower case letters.
The returned elements order does not matter.


*/


// TLE solution 43/44 passed + 1 TLE


class Solution {
public:
    
    vector<string> results;
    unordered_set<string> set_words;
    int match_count = 0;
    
    bool solve(string word, string copy_word) {
        
        if(word.size() == 0 && match_count >=2)
            return true;
        
        for(int i=0; i<=word.size(); i++){
            string prefix = word.substr(0,i);
            if(set_words.find(prefix) != set_words.end() && prefix != copy_word){
                match_count++;
                string remaining = word.substr(i);
                if(solve(remaining, copy_word)) {
                     return true;
                }      
            }
        }
        return false;
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
        for(auto word : words) {
            // to avoid empty string
            if(word.size() >0) set_words.insert(word);
        }
        
        for(int i=0; i<words.size(); i++){
             // to avoid empty string
            if(words[i].size()>0 && solve(words[i], words[i]))
                results.push_back(words[i]);
            match_count = 0;
        }
        
        return results;
    }
};
