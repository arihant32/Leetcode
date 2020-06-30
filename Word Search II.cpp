/*

Word Search II

Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

 

Example:

Input: 
board = [
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
words = ["oath","pea","eat","rain"]

Output: ["eat","oath"]


*/


class Solution {
public:
    
    int r,c;
    int x_dir[4] = {-1, 0, 0, 1};
    int y_dir[4] = {0, -1, 1, 0};
    vector<string> result;
    string str = "";
    unordered_map<string,bool> mp;
    

    void dfs(vector<vector<char>>& board, vector<string>& words, int i, int j, vector<vector<bool>> &visited) {
        
        if(i<0 || i>=r || j<0 || j>=c || visited[i][j] == true) return;
        
        visited[i][j] = true;
        
        str = str + board[i][j];
        
        if(mp[str] == true) {
            result.push_back(str);
            mp[str] = false;
        }
        
        for(int k=0; k<4; k++) {
            dfs(board, words, i+x_dir[k], j+y_dir[k], visited);
        }
        
        visited[i][j] = false;
        str.erase(str.size()-1); 
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        r = board.size();
        c = board[0].size();
        int lnw = words.size();

        vector<vector<bool>> visited(r, vector<bool>(c,false));
        
        for(int i=0; i<lnw; i++) mp[words[i]] = true;

        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                str = "";
                dfs(board, words, i, j, visited);
                // if we found number of words same as given works then break it
                if(result.size() == lnw) break;
            }
        }
            
        return result;
    }
};



// Trie solution


class Tnode{
    
    public:
    
        Tnode *child[26];
        bool is_word; //end of string

        Tnode() {
            for(int i=0; i<26; i++) child[i] = NULL;
            is_word = false;
        }

};

class Solution {
    
    public:

        int r,c;
        int x_dir[4] = {-1, 0, 0, 1};
        int y_dir[4] = {0, -1, 1, 0};
        vector<string> result;
        Tnode *root;

        void insert(string word) {
            Tnode *ptr = root;
            int ln = word.size();
            int i=0;
            while(i<ln)
            {
                int ind = word[i]-'a';
                if(ptr->child[ind] == NULL)
                    ptr->child[ind] = new Tnode();
                ptr = ptr->child[ind];
                i++;
            }
            ptr->is_word = true;
         }
    
        void dfs(vector<vector<char>>& board, int i, int j, string word, vector<vector<bool>> &visited, Tnode *node) {
        
        if(i<0 || i>=r || j<0 || j>=c || visited[i][j] || node->child[board[i][j]-'a'] == NULL)
            return;
        
        visited[i][j] = true;
        
        node = node->child[board[i][j]-'a'];
        
        if(node->is_word) {
             result.push_back(word + board[i][j]);
             node->is_word = false;
        }
            
            
        for(int k=0; k<4; k++)
            dfs(board, i+x_dir[k], j+y_dir[k], word + board[i][j], visited, node);

        visited[i][j] = false;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        r = board.size();
        c = board[0].size();
        int w_ln = words.size();

        root = new Tnode();

        for(int i=0; i<w_ln; i++) insert(words[i]);
        
        vector<vector<bool>> visited(r, vector<bool>(c,false));

        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                char c = board[i][j];
                if(root->child[c-'a'] != NULL)
                    dfs(board,i, j, "" , visited, root);
            }
        }

        return result;
    }
};




