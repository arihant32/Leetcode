/*

Recover Binary Search Tree

Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Example 1:

Input: [1,3,null,null,2]

   1
  /
 3
  \
   2

Output: [3,1,null,null,2]

   3
  /
 1
  \
   2
Example 2:

Input: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

Output: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3
Follow up:

A solution using O(n) space is pretty straight forward.
Could you devise a constant space solution?

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
    
    vector<TreeNode*> data;
    
    void do_inorder(TreeNode* root) {
        if(root == NULL) return;
        do_inorder(root->left);
        data.push_back(root);
        do_inorder(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        
        //storing tree inorder traversal as we know inoder traversal returns result in sorted order
        do_inorder(root);
        
        // to store two pair that need to swap
        vector<TreeNode*> pair;
        
        // Example 1 Inorder : 3 2 1
        // Example 2 Inorder : 1 3 2 4
        // now need to find two pair (or one if adjacent node swapped eg 2) that not follow BST
        // that node follow decreasing then increasing order in inorder traversal (5 3)
        for(int i=0; i<data.size()-1; i++) { 
            if(data[i]->val > data[i+1]->val){
                pair.push_back(data[i]);
                pair.push_back(data[i+1]);
            }
        }
        
        // if only one pair (adjacent case)
        if(pair.size() == 2) {
            int t = pair[0]->val;
            pair[0]->val = pair[1]->val;
            pair[1]->val = t;
         
        // if only two pair then swap first val of first pair with second val of second pair : eg (3, 2) and (2, 1)
        }else if(pair.size() == 4) {
            int t = pair[0]->val;
            pair[0]->val = pair[3]->val;
            pair[3]->val = t;
        }
        
    }
};




