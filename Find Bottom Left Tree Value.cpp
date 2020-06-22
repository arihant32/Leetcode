/*

Find Bottom Left Tree Value

Given a binary tree, find the leftmost value in the last row of the tree.

Example 1:
Input:

    2
   / \
  1   3

Output:
1
Example 2:
Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

Output:
7
Note: You may assume the tree (i.e., the given root node) is not NULL.

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
    void get_left_view(TreeNode* root, int l, int &max,int &ans) {
        if(root == NULL)
            return;
        if(l>max)
        {
            max = l;
            ans = root->val;
        }
        get_left_view(root->left, l+1, max, ans);
        get_left_view(root->right, l+1, max, ans);
          
    }
    int findBottomLeftValue(TreeNode* root) {
        int max=0;
        int l=1;
        int ans=0;
        get_left_view(root, l, max, ans);
        return ans;
    }
};
