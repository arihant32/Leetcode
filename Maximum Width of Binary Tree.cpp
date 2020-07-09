/*

Maximum Width of Binary Tree

Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.

The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.

Example 1:

Input: 

           1
         /   \
        3     2
       / \     \  
      5   3     9 

Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
Example 2:

Input: 

          1
         /  
        3    
       / \       
      5   3     

Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).
Example 3:

Input: 

          1
         / \
        3   2 
       /        
      5      

Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).
Example 4:

Input: 

          1
         / \
        3   2
       /     \  
      5       9 
     /         \
    6           7
Output: 8
Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).


Note: Answer will in the range of 32-bit signed integer.

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
    int widthOfBinaryTree(TreeNode* root) {
        deque<TreeNode*> dq;
        dq.push_back(root);
        int max_width = 0;
        while(!dq.empty()) {
            
            // eg : NULL NULL A B NULL C D NULL NULL
            // removing left most NULL node 
            while(!dq.empty() && dq.front()==NULL) dq.pop_front();
            // removing right most NULL node 
            while(!dq.empty() && dq.back()==NULL) dq.pop_back();
            // now it will like :  A B NULL C D
            // then check the size
            int s = dq.size();
            if(s>max_width) max_width = s;

            while(s--) {
                TreeNode *tmp = dq.front();
                dq.pop_front();
                
                // for left child
                if(tmp==NULL)
                    dq.push_back(NULL);
                else if(tmp->left) 
                    dq.push_back(tmp->left);
                else
                    dq.push_back(NULL);
                
                 // for right child
                if(tmp==NULL)
                    dq.push_back(NULL);
                else if(tmp->right) 
                    dq.push_back(tmp->right);
                else
                    dq.push_back(NULL);  
            }
        }

        return max_width;
    }
};



