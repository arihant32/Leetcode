/**

Random Pick with Weight

Given an array w of positive integers, where w[i] describes the weight of index i, write a function pickIndex which randomly picks an index in proportion to its weight.

Note:

1 <= w.length <= 10000
1 <= w[i] <= 10^5
pickIndex will be called at most 10000 times.
Example 1:

Input: 
["Solution","pickIndex"]
[[[1]],[]]
Output: [null,0]
Example 2:

Input: 
["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
[[[1,3]],[],[],[],[],[]]
Output: [null,0,1,1,1,0]
Explanation of Input Syntax:

The input is two lists: the subroutines called and their arguments. Solution's constructor has one argument, the array w. pickIndex has no arguments. Arguments are always wrapped with a list, even if there aren't any.
**/


class Solution {
public:
    int sum = 0;
    int ln = 0;
    vector<int> cumulative;
    Solution(vector<int>& w) {
        ln = w.size();
        for(auto val : w) {
            sum = sum + val;
            cumulative.push_back(sum);
        }
    }
    
    int get_index(int r) {
        int l = 0;
        int h = ln -1;
        while(l<h) {
            int m = (l+h)/2;
            if(cumulative[m] < r)
                l = m+1;
            else
                h = m;
        }
        return l;
    }
    int pickIndex() {
        // let say my sum is 5 so i need to generate numbers that has equal probability 
        // that is 1, 2, 3, 4, 5
        // if simple take modulo, it will give 0, 1, 2 3, 4 so adding 1 for all the number
        int r = (rand()%sum)+1;
        return get_index(r);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
