/*

Pascal's Triangle II

Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]
Follow up:

Could you optimize your algorithm to use only O(k) extra space?

*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        if(rowIndex==0){
            result.push_back(1);
            return result;
        }
        vector<int> temp;
        temp.push_back(1);
        temp.push_back(1);
        rowIndex = rowIndex -2;
        while(rowIndex>=0) {
           vector<int> copy;
           copy.push_back(1);
           for(int i=0; i<temp.size()-1; i++) {
               int sum = temp[i] + temp[i+1];
               copy.push_back(sum);
           }
           copy.push_back(1);
           temp.clear();
           for(auto val : copy) 
               temp.push_back(val);
           rowIndex--; 
        }
        for(auto val : temp) {
            result.push_back(val);
        }
        return result;
    }
};
