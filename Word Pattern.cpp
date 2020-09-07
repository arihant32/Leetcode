/*

Word Pattern


Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Example 1:

Input: pattern = "abba", str = "dog cat cat dog"
Output: true
Example 2:

Input:pattern = "abba", str = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", str = "dog cat cat dog"
Output: false
Example 4:

Input: pattern = "abba", str = "dog dog dog dog"
Output: false
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters that may be separated by a single space.

*/




class Solution {
public:
        
    vector<string> words;
    
    void split(string s) {
        string temp = "";
        for(int i=0; i<s.size(); i++) {
            if(s[i] == ' '){
               words.push_back(temp);
                temp = "";
            }else{
                temp += s[i];
            }
        }
        words.push_back(temp);
    }
    
    bool wordPattern(string pattern, string str) {
        split(str); 
        
        int w_size = words.size();
        int p_size = pattern.size();
        if(w_size != p_size) return false;
        
        unordered_map<char, string> ctw;
        
        for(int i=0; i<pattern.size(); i++) {    
            char c = pattern[i];
            string w = words[i];
            
            if(ctw.find(c) == ctw.end()) {
                 ctw[c] = w;
            }
            else {
                if(ctw[c].compare(w) != 0)
                    return false;
            }
                
        }
        
        unordered_map<string, char> wtc;
        
        for(int i=0; i<words.size(); i++) {    
            char c = pattern[i];
            string w = words[i];
            
            if(wtc.find(w) == wtc.end()) {
                 wtc[w] = c;
            }
            else {
                if(wtc[w] != c)
                    return false;
            }
                
        }
        
        return true;
    }
};




// or




class Solution {
public:
        
    vector<string> words;
    
    void split(string s) {
        string temp = "";
        for(int i=0; i<s.size(); i++) {
            if(s[i] == ' '){
               words.push_back(temp);
                temp = "";
            }else{
                temp += s[i];
            }
        }
        words.push_back(temp);
    }
    
    bool wordPattern(string pattern, string str) {
        
        split(str); 
        
        int w_size = words.size();
        int p_size = pattern.size();
        if(w_size != p_size) return false;
        
        unordered_map<char, string> ctw;
        unordered_map<string, char> wtc;
        
        for(int i=0; i<pattern.size(); i++) {    
            char c = pattern[i];
            string w = words[i];
            
            if(ctw.find(c) == ctw.end())
                 ctw[c] = w;
            else if(ctw[c].compare(w) != 0)
                return false;  
            
            if(wtc.find(w) == wtc.end()) 
                 wtc[w] = c;
            else if(wtc[w] != c)
                return false;
        }
        
        return true;
    }
};
