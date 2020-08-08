/*

Closest Binary Search Tree Value

Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Note:

Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.
Example:

Input: root = [4,2,5,1,3], target = 3.714286

    4
   / \
  2   5
 / \
1   3

Output: 4

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
    double min;
    int closest = 0;
    
    void findClosest(TreeNode* root, double target) {
        if(root==NULL) return;
        double diff = abs(root->val - target);
        if(min>diff) {
            min = diff;
            closest = root->val;
        }
        findClosest(root->left, target);
        findClosest(root->right, target);
    }
    
    int closestValue(TreeNode* root, double target) {
        // calculating initial only for further comparison
        // then do preorder traversal
        min = abs(root->val - target);
        closest = root->val;
        findClosest(root, target);
        return closest;
    }
};
