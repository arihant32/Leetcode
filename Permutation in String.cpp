/**

Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

 

Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False
 

Note:

The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].

**/

// code :-

class Solution {
public:
    map<char, int> pm;
    map<char, int> sm;
    
    bool isPermut()
    {
        for(int i=0; i<pm.size(); i++)
        {
            if(pm['a'+i] != sm['a'+i]) 
                return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        
        
        int p_ln = s1.size();
        int s_ln = s2.size();
        
        if(p_ln > s_ln)
            return false;
        
        for(int i=0; i<p_ln; i++)
        {
            pm[s1[i]] +=1;
            sm[s2[i]] +=1;
        }
                
        if(isPermut())
           return true;
        
        for(int i=1;i<=s_ln-p_ln;i++)
        {
            sm[s2[i-1]] -=1;
            sm[s2[i + p_ln -1]] +=1;
            if(isPermut())
                return true; 
        }
        
        return false;
        
    }
};

