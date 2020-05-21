/**

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"

**/

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
