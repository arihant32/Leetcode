/*

Partition Labels

A string S of lowercase English letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

 

Example 1:

Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
 

Note:

S will have length in range [1, 500].
S will consist of lowercase English letters ('a' to 'z') only.

*/


class Solution {
public:
    vector<int> partitionLabels(string s) {
        int ln = s.size();
        vector<int> results;
        unordered_map<char, int> ump;
        int i;
        
        // storing last index of the each char
        for(i=0; i<ln; i++) ump[s[i]] = i;
        
        // it's only for initial value
        int last_index = ump[s[0]];
        // to track previous i value
        int pre_i = 0;
        
        for(i=0; i<ln; i++) {
            // Eg : ababcbacadefegdehijhklij
            if(i <= last_index) {
                if(ump[s[i]] > last_index) last_index = ump[s[i]];
            }
            else{
                last_index = ump[s[i]];
                // to calculate the length
                results.push_back(i - pre_i);
                pre_i = i;
            }
        } 
        results.push_back(i - pre_i);
        return results;
    }
};
