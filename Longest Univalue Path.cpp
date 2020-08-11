/*

Longest Univalue Path

Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.

The length of path between two nodes is represented by the number of edges between them.

 

Example 1:

Input:

              5
             / \
            4   5
           / \   \
          1   1   5
Output: 2

 

Example 2:

Input:

              1
             / \
            4   5
           / \   \
          4   4   5
Output: 2

 

Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.

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
    int max_path = 0;
    
    int lup(TreeNode* root) {
        if(root==NULL) return 0;
        int left_tree = lup(root->left);
        int right_tree = lup(root->right);
        if(root->left && root->val == root->left->val)
            left_tree += 1;
        else
            left_tree = 0;
        
        if(root->right && root->val == root->right->val)
            right_tree += 1;
        else
            right_tree = 0;
        
        max_path = max(max_path, left_tree+right_tree);
        return max(left_tree, right_tree);
    }
    int longestUnivaluePath(TreeNode* root) {
        // doing post order traversal
        lup(root);
        return max_path;
    }
};
