/*

Kth Smallest Element in a Sorted Matrix

Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.


*/


class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int r = matrix.size();
        int c = matrix[0].size();
        
        // as kth min so taking max heap
        priority_queue<int> max_heap;
        
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(max_heap.size() < k) {
                     max_heap.push(matrix[i][j]);
                }
                else if(matrix[i][j] < max_heap.top()){
                    max_heap.pop();
                    max_heap.push(matrix[i][j]);
                }
            }
        }
        return max_heap.top();
    }
};
