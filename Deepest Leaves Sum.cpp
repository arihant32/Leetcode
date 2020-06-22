/*

Deepest Leaves Sum

Given a binary tree, return the sum of values of its deepest leaves.
 

Example 1:



Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15


*/

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        if(root == NULL)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int sum = 0;
        while(!q.empty()) {
            int s = q.size();
            int total=0;
            while(s) {
                TreeNode* ptr = q.front();
                q.pop();
                total = total + ptr->val;
                if(ptr->left) q.push(ptr->left);
                if(ptr->right) q.push(ptr->right);
                s--;
            }
            sum = total;
        }
        return sum;
    }
};
