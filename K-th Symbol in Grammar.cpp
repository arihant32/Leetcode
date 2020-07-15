/*

K-th Symbol in Grammar  :  https://www.youtube.com/watch?v=5P84A0YCo_Y


On the first row, we write a 0. Now in every subsequent row, we look at the previous row and replace each occurrence of 0 with 01, and each occurrence of 1 with 10.

Given row N and index K, return the K-th indexed symbol in row N. (The values of K are 1-indexed.) (1 indexed).

Examples:
Input: N = 1, K = 1
Output: 0

Input: N = 2, K = 1
Output: 0

Input: N = 2, K = 2
Output: 1

Input: N = 4, K = 5
Output: 1

Explanation:
row 1: 0
row 2: 01
row 3: 0110
row 4: 01101001
Note:

N will be an integer in the range [1, 30].
K will be an integer in the range [1, 2^(N-1)].

*/


class Solution {
public:
    int get_kth(int n, int k) {
        // base case
        if(n==1 && k==1) return 0;
        // calculate length (see the input sequence lenght is power of 2 in each row)
        int ln = pow(2,n-1);
        int mid = ln/2;
        if(k<=mid)
            return get_kth(n-1, k);
        else
            return !get_kth(n-1, k-mid);
    }
    
    int kthGrammar(int N, int K) {
        return get_kth(N, K); 
    }
};
