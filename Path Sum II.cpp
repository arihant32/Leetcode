/*

Path Sum II


Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]

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
    vector<vector<int>> results;
    vector<int> temp;
    void pathSumHelper(TreeNode* root, int sum, int i) {
        if(root==NULL) return;
        temp[i] = root->val;
        if(sum-root->val==0 && root->left==NULL && root->right==NULL) {
            // as we need path from 0 to i but below return till less than i so used i+1
            vector<int> path(temp.begin(), temp.begin()+i+1);
            results.push_back(path);
        }
        pathSumHelper(root->left, sum-root->val, i+1);
        pathSumHelper(root->right, sum-root->val, i+1);
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        temp.resize(1000);
        pathSumHelper(root, sum, 0);
        return results;
    }
};
