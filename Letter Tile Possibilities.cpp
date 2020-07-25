/*

Letter Tile Possibilities

You have a set of tiles, where each tile has one letter tiles[i] printed on it.  Return the number of possible non-empty sequences of letters you can make.

 

Example 1:

Input: "AAB"
Output: 8
Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
Example 2:

Input: "AAABBC"
Output: 188
 

Note:

1 <= tiles.length <= 7
tiles consists of uppercase English letters.

*/


class Solution {
public:
    set<string> st;
    
    void generate(string tiles, string new_str, vector<bool> &visited) {
        if(new_str.size() > 0) {
            st.insert(new_str);
        }
        
        for(int i=0; i<tiles.size(); i++) {
            if(visited[i]) continue;
            visited[i] = true;
            generate(tiles, new_str+tiles[i], visited);
            visited[i] = false;
        }   
    }
    
    int numTilePossibilities(string tiles) {
        int ln = tiles.size();
        vector<bool> visited(ln, false); 
        generate(tiles, "", visited);
        return st.size();
    }
};
