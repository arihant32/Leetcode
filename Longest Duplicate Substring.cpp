/*


https://www.youtube.com/watch?v=BMvotl5vHvM

Given a string S, consider all duplicated substrings: (contiguous) substrings of S that occur 2 or more times.  (The occurrences may overlap.)

Return any duplicated substring that has the longest possible length.  (If S does not have a duplicated substring, the answer is "".)

 

Example 1:

Input: "banana"
Output: "ana"
Example 2:

Input: "abcd"
Output: ""
 

Note:

2 <= S.length <= 10^5
S consists of lowercase English letters.


*/



class Solution {
public:
    vector<int> power;
    int prime = 10000001;
    
    string robin_karp(string &s, int len) {
        
        if(len == 0)
            return "";
        
         int n = s.size();
         int curr = 0;
         unordered_map<int, vector<int>> hash;
        
        for(int i=0; i<len; i++) {
            curr = (curr*26 + (s[i]-'a'))%prime;
        }
        
        hash[curr] = {0};
        
        for(int i=len; i<n; i++) {
            curr = ((curr - power[len-1] * (s[i-len]-'a'))%prime + prime) % prime;
            curr = (curr*26 + (s[i]-'a'))%prime;
            
            if(hash.find(curr) == hash.end())
                hash[curr] = {i-len+1};
            else{
                for(int index : hash[curr]) {
                    string str = s.substr(i-len+1, len);
                    if(s.substr(index,len) == str)
                        return s.substr(index,len);
                    
                }
                hash[curr].push_back({i-len+1});
            }
        }
        
        return "";
    }
    
    
    string longestDupSubstring(string S) {
        
        int n = S.size();
        int l=0;
        int r = n-1;
        power = vector<int>(n);
        // d0 + d1 + d2 + d3 ... d number of char is posible
        power[0] = 1;
        for(int i=1; i<n; i++) {
            power[i] = (power[i-1]*26)%prime;
        }
        
        string ans;
        
        while(l<=r) {
            int mid = l + (r-l)/2;
            string curr = robin_karp(S, mid);
            
            if(curr.length() > ans.length()){
                ans = curr;
                l = mid+1;
            }
            else{
                r = mid -1;
            }
        }
        
        return ans;
    }
};
