/*

Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
   
   

*/

class Solution {
public:
    int numTrees(int n) {
        // Answer is : nth catalen number
        // T(n) = (2n)! /(n+1)!(n!)
        
        long double two_n = 1, n_plus_one = 1, i;
        for(i=2*n; i>n; i--) {
            two_n = two_n*i;
        }
        
        for(i=n+1; i>=1; i--) {
            n_plus_one = n_plus_one*i;
        }   
        
        return two_n/(n_plus_one);
    }
};
