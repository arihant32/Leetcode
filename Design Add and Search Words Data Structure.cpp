/*

Design Add and Search Words Data Structure


Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
 

Example:

Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True
 

Constraints:

1 <= word.length <= 500
word in addWord consists lower-case English letters.
word in search consist of  '.' or lower-case English letters.
At most 50000 calls will be made to addWord and search.



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
