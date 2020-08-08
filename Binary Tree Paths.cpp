/*

Binary Tree Paths


Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3

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
    vector<string> results;
    void binaryTreePathsHelper(TreeNode* root, string s) {
        if(root==NULL) return;
        s = s + to_string(root->val);
        if(root->left==NULL && root->right==NULL) {
            results.push_back(s);
        }
        binaryTreePathsHelper(root->left, s+"->");
        binaryTreePathsHelper(root->right, s+"->");
        // to remove the last node value that we added in the path when we backtrack
        s.erase(s.size()-1);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        binaryTreePathsHelper(root, "");
        return results;
    }
};
