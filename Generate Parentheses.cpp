/*

Generate Parentheses

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

*/

class Solution {
public:
    
    vector<string> result;
    
    void generate(string p, int open, int close) {
        if(open==0 && close==0) {
            result.push_back(p);
            return;
        }
        if(open>=1) {
            generate(p+"(", open-1, close);
        }
        if(open<close) {
            generate(p+")", open, close-1);
        }
    }
    vector<string> generateParenthesis(int n) {
        generate("", n, n);
        return result;
    }
};
