/*

Sum of Left Leaves

Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.

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
    int get_sum(TreeNode* root, bool is_left) {
        if(root == NULL) return 0;
        if(is_left && root->left == NULL && root->right == NULL)
            return root->val;
        return get_sum(root->left, true) + get_sum(root->right, false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return get_sum(root, false);
    }
};
