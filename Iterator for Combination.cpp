/*

Iterator for Combination


Design an Iterator class, which has:

A constructor that takes a string characters of sorted distinct lowercase English letters and a number combinationLength as arguments.
A function next() that returns the next combination of length combinationLength in lexicographical order.
A function hasNext() that returns True if and only if there exists a next combination.
 

Example:

CombinationIterator iterator = new CombinationIterator("abc", 2); // creates the iterator.

iterator.next(); // returns "ab"
iterator.hasNext(); // returns true
iterator.next(); // returns "ac"
iterator.hasNext(); // returns true
iterator.next(); // returns "bc"
iterator.hasNext(); // returns false
 

Constraints:

1 <= combinationLength <= characters.length <= 15
There will be at most 10^4 function calls per test.
It's guaranteed that all calls of the function next are valid.

*/


class CombinationIterator {
public:

    queue<string> q;
    
    CombinationIterator(string characters, int combinationLength) {
        generate(characters, "", 0, combinationLength);
    }
    
    void generate(string s, string result, int index, int cln) {
        if(cln==result.size()){
            q.push(result);
            return;
        }
        for(int i=index; i<s.size(); i++){
            generate(s, result+s[i], i+1, cln);
        }
    }
    string next() {
        string ans = q.front();
        q.pop();
        return ans;
    }
    
    bool hasNext() {
       return q.empty() ? false : true;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */