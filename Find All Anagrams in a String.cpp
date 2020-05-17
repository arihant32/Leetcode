/**

Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

**/

// code :-

class Solution {
public:
    map<char, int> pm;
    map<char, int> sm;
    
    bool isAnn()
    {
        for(int i=0; i<pm.size(); i++)
        {
            if(pm['a'+i] != sm['a'+i]) 
                return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        
        int s_ln = s.size();
        int p_ln = p.size();
        
        vector<int> ind;
        
        for(int i=0; i<p_ln; i++)
        {
            pm[p[i]] +=1;
            sm[s[i]] +=1;
        }
                
        if(isAnn())
           ind.push_back(0);
        
        for(int i=1;i<=s_ln-p_ln;i++)
        {
            sm[s[i-1]] -=1;
            sm[s[i + p_ln -1]] +=1;
            if(isAnn())
                ind.push_back(i);
        }
        
        return ind;
        
    }
};
