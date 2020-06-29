/*

All Nodes Distance K in Binary Tree


We are given a binary tree (with root node root), a target node, and an integer value K.

Return a list of the values of all nodes that have a distance K from the target node.  The answer can be returned in any order.

 

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2

Output: [7,4,1]

Explanation: 
The nodes that are a distance 2 from the target node (with value 5)
have values 7, 4, and 1.



Note that the inputs "root" and "target" are actually TreeNodes.
The descriptions of the inputs above are just serializations of these objects.
 

Note:

The given tree is non-empty.
Each node in the tree has unique values 0 <= node.val <= 500.
The target node is a node in the tree.
0 <= K <= 1000.


*/



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> resutl;
    
    void print_k_distance_down_from_root(TreeNode* root, int k) {
        if(root == NULL || k < 0) return;
        if(k==0) {
            resutl.push_back(root->val);
            return;
        } 
        print_k_distance_down_from_root(root->left, k-1);
        print_k_distance_down_from_root(root->right, k-1);  
    }
    
    int k_distance_from_target(TreeNode* root, TreeNode* target, int k) {
        
        if(root == NULL) return -1;
        
        if(root == target) {
            print_k_distance_down_from_root(root, k);
            return 0;
        }
            
        int dl = k_distance_from_target(root->left, target, k);
        
        if(dl!=-1) {
        
            if (dl + 1 == k) 
                resutl.push_back(root->val);
            else
                print_k_distance_down_from_root(root->right, k-dl-2); 
            
            return 1 + dl;   
        }
        
        int dr = k_distance_from_target(root->right, target, k);
        
        if(dr!=-1) {
        
            if (dr + 1 == k) 
                resutl.push_back(root->val);
            else
                print_k_distance_down_from_root(root->left, k-dr-2); 
            
            return 1 + dr;   
        }
        
        return -1;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        k_distance_from_target(root, target, k);
        return resutl;
    }
};
