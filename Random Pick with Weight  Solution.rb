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
    
    vector<int> temp;
    int sum;
    
    Solution(vector<int>& w) {
        // calculating cumulative sum and total array sume
        sum = 0;
        for(int i=0; i<w.size(); i++) 
        {
            sum = sum + w[i];
            temp.push_back(sum);
        }
    }
    
    int get_index(int rn) {
        int l = 0;
        int r = temp.size()-1;
        while(l<r)
        {
            int mid = (l+r)/2;
            if(temp[mid] < rn)
                l = mid+1;
            else
                r = mid;
        }
        return l;
    }
    int pickIndex() {
        int rn = rand()%sum + 1;
        return get_index(rn);    
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
