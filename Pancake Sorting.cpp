/*

Pancake Sorting


Given an array of integers A, We need to sort the array performing a series of pancake flips.

In one pancake flip we do the following steps:

Choose an integer k where 0 <= k < A.length.
Reverse the sub-array A[0...k].
For example, if A = [3,2,1,4] and we performed a pancake flip choosing k = 2, we reverse the sub-array [3,2,1], so A = [1,2,3,4] after the pancake flip at k = 2.

Return an array of the k-values of the pancake flips that should be performed in order to sort A. Any valid answer that sorts the array within 10 * A.length flips will be judged as correct.

 

Example 1:

Input: A = [3,2,4,1]
Output: [4,2,4,3]
Explanation: 
We perform 4 pancake flips, with k values 4, 2, 4, and 3.
Starting state: A = [3, 2, 4, 1]
After 1st flip (k = 4): A = [1, 4, 2, 3]
After 2nd flip (k = 2): A = [4, 1, 2, 3]
After 3rd flip (k = 4): A = [3, 2, 1, 4]
After 4th flip (k = 3): A = [1, 2, 3, 4], which is sorted.
Notice that we return an array of the chosen k values of the pancake flips.
Example 2:

Input: A = [1,2,3]
Output: []
Explanation: The input is already sorted, so there is no need to flip anything.
Note that other answers, such as [3, 3], would also be accepted.
 

Constraints:

1 <= A.length <= 100
1 <= A[i] <= A.length
All integers in A are unique (i.e. A is a permutation of the integers from 1 to A.length).

*/



class Solution {
public:
    
    int get_max_ele_index(vector<int>& a, int ln) {
        int max_index = 0;
        for(int i=0; i<ln; i++) {
            if(a[i] > a[max_index]) max_index = i;
        }
        return max_index;
    }
    
    void reverse(vector<int>& a, int i, int j) {
        while(i < j) {
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
            i++;
            j--;
        }
    }
    
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> results;
        int ln = A.size();
        // as need to sort n-1 element and last one element will automatically sort at index 0
        while(ln>1) {
            // finding first max element in the array and storing it's index
            int index = get_max_ele_index(A, ln);
            // now reverse that array from begning to till the max element index
            reverse(A, 0, index);
            // storing how many flips we took
            results.push_back(index+1);
            // now reversing that entrie array to move our max element to end of array
            reverse(A, 0, ln-1);
            results.push_back(ln);
            // as now one element already sorted and moved in the end of array so decrement the size of arr
            ln--;
        }
        return results;
    }
};
