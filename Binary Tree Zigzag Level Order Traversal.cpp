/*

Binary Tree Zigzag Level Order Traversal

Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(root);
        bool flag = true;
        while(!s1.empty() || !s2.empty()) {
            vector<int> tmp;
            if(flag) {
                while(!s1.empty())
                {
                    TreeNode *f = s1.top();
                    s1.pop();
                    tmp.push_back(f->val);
                    if(f->left) s2.push(f->left);
                    if(f->right) s2.push(f->right); 
                }
            }
            else
            {
                 while(!s2.empty())
                {
                    TreeNode *f = s2.top();
                    s2.pop();
                    tmp.push_back(f->val);
                    if(f->right) s1.push(f->right); 
                    if(f->left) s1.push(f->left);
                    
                }
            }
            flag = !flag;
            ans.push_back(tmp);
        }
        return ans;
    }
};
