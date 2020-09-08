/*

Sum of Root To Leaf Binary Numbers


Given a binary tree, each node has value 0 or 1.  Each root-to-leaf path represents a binary number starting with the most significant bit.  For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.

For all leaves in the tree, consider the numbers represented by the path from the root to that leaf.

Return the sum of these numbers.

 

Example 1:



Input: [1,0,1,0,1,0,1]
Output: 22
Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
 

Note:

The number of nodes in the tree is between 1 and 1000.
node.val is 0 or 1.
The answer will not exceed 2^31 - 1.

*/

class Solution {
public:
    
    int get_sum(TreeNode* root, string num_s) {
        if(root == NULL) return 0;
        num_s += to_string(root->val);
        if(root->left == NULL && root->right == NULL) {
            int num = 0, p = 0;
            for(int i = num_s.size()-1; i>=0; i--) {
                num = num + pow(2,p)*(num_s[i] - 48);
                p++;
            }
            return num;
        }
        return get_sum(root->left, num_s) + get_sum(root->right, num_s);
    }
    int sumRootToLeaf(TreeNode* root) {
        return get_sum(root, "");
    }
};
