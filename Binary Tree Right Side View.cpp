/*

Binary Tree Right Side View

Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

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
    vector<int> ans;
    
    vector<int> right_view(TreeNode* root, int l, int &max) {
        if(root == NULL)
            return ans;
        if(l > max) {
            max = l;
            ans.push_back(root->val);
        }
        right_view(root->right, l+1, max);
        right_view(root->left, l+1, max);
        return ans;
    }
    vector<int> rightSideView(TreeNode* root) {
        int max = 0;
        int l = 1;
        return right_view(root,l, max);
    }
};
