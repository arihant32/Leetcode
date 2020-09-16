/*

Maximum XOR of Two Numbers in an Array


Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231.

Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.

Could you do this in O(n) runtime?

Example:

Input: [3, 10, 5, 25, 2, 8]

Output: 28

Explanation: The maximum result is 5 ^ 25 = 28.

*/



class TrieNode { 
    public:
       TrieNode *left = NULL; // when bit is zero will add node in left 
       TrieNode *right = NULL; // when bit is one will add node in right 
};

class Solution {
public:
    
    void insert(TrieNode* root, int val){
        TrieNode* ptr = root;
        for(int i=31; i>=0; i--) {
            // taking single bit from the number
            int bit = 1 & (val>>i);
            if(bit == 0) {
                // move to left if left not present then create left node and move
                if(ptr->left == NULL)
                    ptr->left = new TrieNode();
                ptr = ptr->left;
            }
            else if(bit == 1){
                // move to right if right not present then create right node and move
                if(ptr->right == NULL)
                    ptr->right = new TrieNode();
                ptr = ptr->right;
            }
        }
    }
    
    int get_max_xor(TrieNode* root, vector<int>& nums) {
       
        int ln = nums.size();
        int max_xor = INT_MIN;
        
        for(int i=0; i<ln; i++) {
            
            TrieNode* ptr = root;
            int val = nums[i];
            int current_xor = 0;
            // will get the max xor when we will get the max 1 opposite to it 0
            for(int j=31; j>=0; j--) {
                // taking single bit from the number
                int bit = 1 & (val>>j);
                if(bit == 0) {
                    // moving to 1 side as need opposite bits
                    if(ptr->right) {
                        current_xor += pow(2, j);
                        ptr = ptr->right;
                    }
                    else  
                        ptr = ptr->left;
                }
                else if(bit == 1){
                    // moving to 0 side as need opposite bits
                    if(ptr->left){
                         current_xor += pow(2, j);
                         ptr = ptr->left;
                    }
                    else  
                        ptr = ptr->right;
                }
            }
            if(current_xor > max_xor) max_xor = current_xor;
        }
        
        return max_xor;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();
        int ln = nums.size();
        
        for(int i=0; i<ln; i++) {
             insert(root, nums[i]);
        }
        
        return get_max_xor(root, nums);
        
    }
    
    
};
