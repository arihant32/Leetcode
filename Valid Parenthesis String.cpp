/*

Valid Parenthesis String

https://www.youtube.com/watch?v=KuE_Cn3xhxI


Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
An empty string is also valid.
Example 1:
Input: "()"
Output: True
Example 2:
Input: "(*)"
Output: True
Example 3:
Input: "(*))"
Output: True
Note:
The string size will be in the range [1, 100].

*/


class Solution {
public:
    bool checkValidString(string s) {
        stack<int> paren;
        stack<int> star;
        
        for(int i=0; i<s.size(); i++) {
            if(s[i]=='(') 
                paren.push(i);
            else if(s[i]=='*') 
                star.push(i);
            else {
                if(!paren.empty()) 
                    paren.pop();
                else if(!star.empty()) 
                    star.pop();
                else
                    return false;
            }
        }
        
        // now balancing remaining open parenthesis
        while(!paren.empty()) {
            if(star.empty())
                return false;
            else if(paren.top() < star.top()) {
                paren.pop();
                star.pop();
            }
            else
                return false;
        }
        
        return true;
    }
};
