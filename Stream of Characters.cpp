/*

Stream of Characters

Implement the StreamChecker class as follows:

StreamChecker(words): Constructor, init the data structure with the given words.
query(letter): returns true if and only if for some k >= 1, the last k characters queried (in order from oldest to newest, including this letter just queried) spell one of the words in the given list.
 

Example:

StreamChecker streamChecker = new StreamChecker(["cd","f","kl"]); // init the dictionary.
streamChecker.query('a');          // return false
streamChecker.query('b');          // return false
streamChecker.query('c');          // return false
streamChecker.query('d');          // return true, because 'cd' is in the wordlist
streamChecker.query('e');          // return false
streamChecker.query('f');          // return true, because 'f' is in the wordlist
streamChecker.query('g');          // return false
streamChecker.query('h');          // return false
streamChecker.query('i');          // return false
streamChecker.query('j');          // return false
streamChecker.query('k');          // return false
streamChecker.query('l');          // return true, because 'kl' is in the wordlist
 

Note:

1 <= words.length <= 2000
1 <= words[i].length <= 2000
Words will only consist of lowercase English letters.
Queries will only consist of lowercase English letters.
The number of queries is at most 40000.

*/


class Trie{
    public:
    Trie* child[26] = {NULL};
    bool is_end = false;
};

class StreamChecker {
public:
    
    Trie *root;
    string previous_chars = "";
    int word_len_limit = 2000;
    
    StreamChecker(vector<string>& words) {
        /* Inserting all the words in the trie. 
           We store word in trie in reverse order eg if word is "abcde" then we store in trie like "edbca" 
           As in the query we need to search the letter from newest letter to all it's oldest letter so far came in the stream */
        root = new Trie();
        for(auto word : words) insert(word);
    }
    
    void insert(string word) {
        Trie *ptr = root;
        // starting in last as need to store the word in reverse order
        for(int i=word.size()-1; i>=0; i--) {
            int index = word[i] - 'a';
            if(ptr->child[index] == NULL) {
                ptr->child[index] = new Trie(); 
            }
            ptr = ptr->child[index];
        }
        ptr->is_end = true;
    }
    
    bool search(string word) {
        Trie *ptr = root;
        // starting in last as need to search the word from newest letter to all it's oldest letter so far came in the stream
        for(int i=word.size()-1; i>=0; i--) {
            int index = word[i] - 'a';
            if(ptr->child[index] == NULL) return false; 
            ptr = ptr->child[index];
            // if it's end of word simply return it
            if(ptr && ptr->is_end) return true;
        }
        return false;
    }
    
    bool query(char letter) {
        // appending letter to our global string as it need in future query 
        previous_chars += letter;
        // in the question is given that the max word size up to 2000 so at any time our previous_chars
        // is greater than 2000 then removing one char from begning 
        if (previous_chars.size() > word_len_limit) 
            previous_chars.erase(0);
        // now searching in trie
        return search(previous_chars);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
