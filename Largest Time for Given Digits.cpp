/*

Largest Time for Given Digits


Given an array of 4 digits, return the largest 24 hour time that can be made.

The smallest 24 hour time is 00:00, and the largest is 23:59.  Starting from 00:00, a time is larger if more time has elapsed since midnight.

Return the answer as a string of length 5.  If no valid time can be made, return an empty string.

 

Example 1:

Input: [1,2,3,4]
Output: "23:41"
Example 2:

Input: [5,5,5,5]
Output: ""
 

Note:

A.length == 4
0 <= A[i] <= 9

*/


class Solution {
public:
    
    string ans = "";
    int time = 0;
    
    void generate_permutation(vector<int>& a, int index) {
        if(index == a.size()) {
            // generating two digit
            int hh = a[0]*10 + a[1];
            int mm = a[2]*10 + a[3];
            string s = to_string(a[0])+to_string(a[1])+":"+to_string(a[2])+to_string(a[3]);
            if(mm<=59 && hh<=23) {
                // for checking max time
                // 23 59 => 23*100 + 59 => 2359
                int temp_time = hh*100 + mm;
                if(temp_time >= time) {
                    time = temp_time;
                    ans = s;
                }      
            }
        }
        for(int i=index; i<a.size(); i++) {
            int t = a[i];
            a[i] = a[index];
            a[index] = t;
            generate_permutation(a, index+1);
            t = a[i];
            a[i] = a[index];
            a[index] = t;
        }
    }
    string largestTimeFromDigits(vector<int>& A) {
        generate_permutation(A, 0);
        return ans;
    }
};
