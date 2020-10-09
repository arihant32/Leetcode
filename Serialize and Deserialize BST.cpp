/*

Serialize and Deserialize BST


Serialization is converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You need to ensure that a binary search tree can be serialized to a string, and this string can be deserialized to the original tree structure.

The encoded string should be as compact as possible.

 

Example 1:

Input: root = [2,1,3]
Output: [2,1,3]
Example 2:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
0 <= Node.val <= 104
The input tree is guaranteed to be a binary search tree.



*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string level_order_str = "";
        if(root == NULL) return level_order_str;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            while(s--){
                TreeNode* temp = q.front();
                q.pop();
                level_order_str += to_string(temp->val) + ",";
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return level_order_str;
    }
    
    TreeNode* inser_in_tree(TreeNode* root, int val) {
        
        if(root == NULL) return new TreeNode(val);
        
        if(val < root->val) {
             root->left = inser_in_tree(root->left, val);
        }
        else{
            root->right = inser_in_tree(root->right, val);
        }
        return root;
    }
    

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        if(data.size() == 0) return NULL;
        
        vector<int> copy_data;
        int num = 0;
        for(int i=0; i<data.size()-1; i++){
            if(data[i] != ','){
               num = num*10 + (data[i] - '0');
            }else{
                copy_data.push_back(num);
                num = 0;
            }
        }
        
        copy_data.push_back(num);
        
        TreeNode* root = NULL;
        for(int i=0; i<copy_data.size(); i++){
            root = inser_in_tree(root, copy_data[i]);
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
