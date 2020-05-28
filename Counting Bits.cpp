/**

Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example 1:

Input: 2
Output: [0,1,1]
Example 2:

Input: 5
Output: [0,1,1,2,1,2]
Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.

**/

class Solution {
public:
    int get_one_count_in_even_no(int n) {
        //passing even number and counting number of 1's in it's binaray
        int count = 0;
        while(n) {
            if(n&1) count++;
            n = n>>1;
        }
        return count;
    }
    vector<int> countBits(int num) {
        vector<int> ans;
        ans.push_back(0);
        if(num == 0) return ans;
        if(num == 1) {;
            ans.push_back(1);
            return ans;
        }
        
        ans.push_back(1);
        int one_count = 0;
        
        for(int i=2; i <=num; i++) {
            // count the number of 1's in even number and for next odd number, the number of 1's in it binary is nomber of 1 in even no + 1
            if(i%2 == 0) {
               one_count =  get_one_count_in_even_no(i);
               ans.push_back(one_count);
            }
            else {
                ans.push_back(one_count+1);
            }   
        }
        
        return ans;
    }
};
