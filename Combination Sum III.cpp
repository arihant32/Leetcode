/*

Combination Sum III

Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Note:

All numbers will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]


*/



class Solution {
public:
    
    vector<vector<int>> results;
    // to avoid duplicate taking set
    set<vector<int>> myset;
    vector<int> temp;
    
    void solve(int k, int n, int index) {
        if(n < 0 || temp.size() > k) 
            return;
        
        if(temp.size() == k && n==0) {
            myset.insert(temp);
            return;
        }
        
        for(int i=index; i<=9; i++) {
            temp.push_back(i);
            solve(k, n-i, i+1);
            temp.pop_back();
            solve(k, n, i+1);
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        solve(k, n, 1);
        for(auto s : myset) results.push_back(s);
        return results;
    }
};
