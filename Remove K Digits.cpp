/**

Link : https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3328/

https://www.youtube.com/watch?v=3QJzHqNAEXs&t=12s

Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.

**/

// code :-

class Solution {
public:
    void remove_k(string num, string &ans, int k)
    {
        if(k==0)
        {
            ans.append(num);
            return;
        }
        int ln = num.size();
        if(ln <=k)
        {
            return;
        }
        int m_ind = 0;
        for(int i=1; i<=k; i++)
        {
            if(num[m_ind] > num[i])
                m_ind = i;
        }
        ans.push_back(num[m_ind]);
        string new_num = num.substr(m_ind+1, ln-m_ind); 
        remove_k(new_num, ans, k-m_ind);   
    }
    string removeKdigits(string num, int k) {
        string ans="";
        if(num.size() == k)
            return "0";
        remove_k(num, ans, k);
        int i=0;
        for(i=0;i<ans.size();i++)
        {
            if(ans[i] == '0')
               continue;
            break;
        }
        if(i==ans.size())
            return "0";
        ans = ans.substr(i,ans.size());
        return ans;
    }
};

