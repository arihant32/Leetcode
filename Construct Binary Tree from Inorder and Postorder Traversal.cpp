/*

Construct Binary Tree from Inorder and Postorder Traversal

Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7

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
  
  // is: inorder start
  // ie: inorder end
  // ps: postorder start
  // pe : postorder end
  TreeNode* build_tree(vector<int>& inorder, vector<int>& postorder, int is, int ie, int ps, int pe){
      if(is > ie) return NULL;
      
      int root_val = postorder[pe];
      TreeNode* root = new TreeNode(root_val);
      
      int root_index;
      for(int i=is; is<=ie; i++) {
          if(inorder[i] == root_val) {
              root_index = i;
              break;
          }
      }
      
      int left_tree_size = root_index - is;
      int right_tree_size = ie - root_index;
      
      root->left = build_tree(inorder, postorder, is, root_index-1, ps, ps+left_tree_size-1);
      root->right = build_tree(inorder, postorder, root_index+1, ie, pe-right_tree_size, pe-1);
      return root;
  }

  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      int ln = inorder.size();
      return build_tree(inorder, postorder, 0, ln-1, 0, ln-1);
  }

};
