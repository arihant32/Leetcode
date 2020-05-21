/**

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true

**/

class Solution {
public:
    bool isValid(string str) {
        
        stack<char> s;
        int ln = str.size();
        int i=0;
        while(i<ln)
        {
            if(str[i]=='(' || str[i]=='['|| str[i]=='{')
                s.push(str[i]);
            else if (!s.empty())
            {
                //cout<<"char="<<s.top()<<"\n";
                if((str[i] == ')' && s.top() == '(') || (str[i] == ']' && s.top() == '[') || (str[i] == '}' && s.top() == '{') )
                {
                    s.pop();
                 }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
            i++;
        }

        if(s.empty())
            return true;
        else
            return false;

    
        
    }
};
