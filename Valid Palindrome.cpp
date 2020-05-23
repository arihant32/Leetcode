/**

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false

**/

class Solution {
public:
    bool isPalindrome(string s) {
        string new_str = "";
        
        for(int i=0; i<s.size(); i++)
        {
            if((s[i] >='a' && s[i] <='z') || (s[i] >='A' && s[i] <='Z') || (s[i] >='0' && s[i] <='9'))
                new_str +=s[i];
        }
        cout<<new_str;
        
        int i =0;
        int j = new_str.size() -1;
        char i_char, j_char;
        while(i < j)
        {
            i_char = new_str[i];
            j_char = new_str[j];
                
            if(i_char >='A' && i_char <='Z')
                i_char = new_str[i] + 32;
            
            if(j_char >='A' && j_char <='Z')
                j_char = new_str[j] + 32;
            
            if(i_char != j_char)
                return false;
            
            i++;
            j--;
        }
        return true;
    }
};
