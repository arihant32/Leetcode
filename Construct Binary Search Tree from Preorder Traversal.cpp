/**

Construct Binary Search Tree from Preorder Traversal :https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

It's guaranteed that for the given test cases there is always possible to find a binary search tree with the given requirements.

Example 1:

Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

 

Constraints:

1 <= preorder.length <= 100
1 <= preorder[i] <= 10^8
The values of preorder are distinct.
**/

// code : O(n*2) solution

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
    
    TreeNode* new_node(int val){
        TreeNode* tmp = new TreeNode();
        tmp->val = val;
        tmp->left = tmp->right = NULL;
        return tmp;
    }
    
    TreeNode* making_bst(TreeNode* ptr, int val) {
        if(ptr == NULL)
            return new_node(val);

        if(val < ptr->val)
            ptr->left = making_bst(ptr->left, val);
            
        if(val > ptr->val)
            ptr->right = making_bst(ptr->right, val);
        
        return ptr;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size() == 0)
            return NULL;
        
        // creating a root node.
        TreeNode* root = new_node(preorder[0]);
        
        if(preorder.size() == 1)
            return root;
        
        // adding rest of preorder node one by one as per BST property.
        for(int i=1; i<preorder.size(); i++)
            making_bst(root, preorder[i]);
            
        return root;
    }
};
