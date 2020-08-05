/*

Add and Search Word - Data structure design


Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

Example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.


*/


class Tnode {
    public: 
        Tnode *arr[26];
        bool is_end;
        Tnode() {
            for(int i=0; i<26; i++) arr[i] = NULL;
            is_end = false;
        }
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    Tnode *tnode;
    WordDictionary() {
        tnode = new Tnode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Tnode *ptr = tnode;
        // or
        // Tnode *ptr = this->tnode;
        for(int i=0; i<word.size(); i++) {
            int index = word[i] - 'a';
            if(ptr->arr[index] == NULL) 
                ptr->arr[index] = new Tnode();
            ptr = ptr->arr[index];
        }
        ptr->is_end = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word, Tnode *temp = NULL) {
        Tnode *ptr = (temp ? temp : tnode);
        for(int i=0; i<word.size(); i++) {
            int index = word[i] - 'a';
            if(word[i]=='.') {
                for(int j=0; j<26; j++){
                    if(ptr->arr[j]!=NULL)
                        if(search(word.substr(i+1), ptr->arr[j])) return true;
                }
                return false;
            }
            if(index>=0 && index<26) {
                if(ptr->arr[index] == NULL) return false;
                ptr = ptr->arr[index];
            }
        }
        return ptr && ptr->is_end;
    }
};


/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
