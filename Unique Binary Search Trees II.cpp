/*

Unique Binary Search Trees II

Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

Example:

Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
 

Constraints:

0 <= n <= 8
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
    vector<TreeNode*> constructTrees(int start, int end) { 
        vector<TreeNode*> list; 
        /*  if start > end   then subtree will be empty so returning NULL 
            in the list */
        if (start > end) 
        { 
            list.push_back(NULL); 
            return list; 
        } 
  
        /*  iterating through all values from start to end  for constructing\ 
            left and right subtree recursively  */
        for (int i = start; i <= end; i++) 
        { 
            /*  constructing left subtree   */
            vector<TreeNode*> lst  = constructTrees(start, i - 1); 

            /*  constructing right subtree  */
            vector<TreeNode*> rst = constructTrees(i + 1, end); 

            /*  now looping through all left and right subtrees and connecting 
                them to ith root  below  */
            for (int j = 0; j < lst.size(); j++) 
            { 
                TreeNode* left = lst[j]; 
                for (int k = 0; k < rst.size(); k++) 
                {  
                    TreeNode* right = rst[k];
                    
                    TreeNode* node = new TreeNode(i); // making value i as root 
                    node->left = left;               // connect left subtree 
                    node->right = right;             // connect right subtree 
                    list.push_back(node);            // add this tree to list 
                } 
            } 
        } 
        return list; 
    } 
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> result;
        if(n<1) return result;
        return constructTrees(1, n);
    }
};
