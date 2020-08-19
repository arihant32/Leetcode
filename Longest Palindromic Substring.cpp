/**

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

https://www.youtube.com/watch?v=UflHuQj6MVA

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"

**/



// Solution One without DP


class Solution {
public:
    string longestPalindrome(string s) {
        int ln = s.size();
        if(ln==0) return "";
        int max_len = 0;
        int start = 0, end = 0;
        for(int i=0; i<ln; i++) {
            // odd length
            int l = i-1;
            int h = i+1;
            while(l<h) {
                if(l>=0 && h<ln && s[l] == s[h]) {
                    if(h-l+1 > max_len) {
                        max_len = h-l+1;
                        start = l;
                        end = h;
                    }
                    l--;
                    h++;
                } else{
                    break;
                }
            }
            // even length
            l = i;
            h = i+1;
            while(l<h) {
                if(l>=0 && h<ln && s[l] == s[h]) {
                    if(h-l+1 > max_len) {
                        max_len = h-l+1;
                        start = l;
                        end = h;
                    }
                    l--;
                    h++;
                } else{
                    break;
                }
            }
            
        }
        string ps = "";
        for(int i=start; i<=end; i++) ps += s[i];
        return ps;
    }
};



// Solution two with DP
class Solution {
public:
    string longestPalindrome(string s) {
        
         int ln = s.size();
    vector<vector<int>> v(ln,vector<int> (ln,0));
    for(int i=0;i<ln;i++)
    {
        for(int j=0;j<ln;j++)
        {
            if(i==j) v[i][j] = 1;
        }
    }
    
    for(int k=0;k<ln;k++)
    {
        int i=0;
        for(int j=k+1;j<ln;j++)
        {
            if(s[i]!=s[j]){
                  v[i][j]=0;
            }
            else{
                 v[i][j]=(v[i+1][j-1] || (v[i][j-1] && abs(i-j)==1));
            }
            i++;
        }
        
    }
    

    int cnt=0;
    int start_one=0,end_one=0,a=0,b=0;
    for(int i=0;i<ln;i++)
    {
        for(int j=i;j<ln;j++)
        {
            if(v[i][j]==1)
            {
                start_one = i;
                end_one = j;
            }
        }
        if((end_one-start_one)>=cnt)
        {
            a=start_one;
            b=end_one;
            cnt = end_one-start_one;
        }

    }
 
    string nstr="";
    while(a<=b)
    {
        nstr+=s[a];
        a++;
    }

    return nstr;
        
    }
};
