/** Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings. **/


# code :-

struct tnode {
    struct tnode *child[26] = {NULL};
    bool end_of = false; //end of string
};

typedef struct tnode node;
    
class Trie {
    
    public:
    
    /** Initialize your data structure here. */
    node *root;
    
    Trie() {
        root = new node;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        node *ptr = root;
        int ln = word.size();
        int i=0;
        while(i<ln)
        {
            int ind = word[i]-'a';
            if(ptr->child[ind] == NULL)
                ptr->child[ind] = new node;
            ptr = ptr->child[ind];
            i++;
        }
        ptr->end_of = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        node *ptr = root;
        int ln = word.size();
        int i=0;
        while(i<ln)
        {
            int ind = word[i]-'a';
            if(ptr->child[ind]==NULL)
                return false;
            ptr = ptr->child[ind];
            i++;
        }
        if(ptr!=NULL && ptr->end_of == true)
            return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        node *ptr = root;
        int ln = prefix.size();
        int i=0;
        while(i<ln)
        {
            int ind = prefix[i]-'a';
            if(ptr->child[ind]==NULL)
                return false;
            ptr = ptr->child[ind];
            i++;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

