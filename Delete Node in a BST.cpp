/*

Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
Note: Time complexity should be O(height of tree).

Example:

root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

Given key to delete is 3. So we find the node with value 3 and delete it.

One valid answer is [5,4,6,2,null,null,7], shown in the following BST.

    5
   / \
  4   6
 /     \
2       7

Another valid answer is [5,2,6,null,4,null,7].

    5
   / \
  2   6
   \   \
    4   7

*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* get_inorder_successor(TreeNode* root) {
        TreeNode* current = root;
        while(current->left){
            current = current->left;
        }
        return current;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;
        
        if(key < root->val)
            root->left = deleteNode(root->left, key);
        else if(root->val < key)
            root->right = deleteNode(root->right, key);
        else {
            // one child
            if(root->left == NULL){
                TreeNode* temp = root->right;
                delete(root);
                return temp;
            }
            // one child
            if(root->right == NULL){
                TreeNode* temp = root->left;
                delete(root);
                return temp;
            }else{
                // two childs
                TreeNode* successor = get_inorder_successor(root->right);
                root->val = successor->val;
                root->right = deleteNode(root->right, successor->val);
            }
        }
        
        return root;
    }
};
