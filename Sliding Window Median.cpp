/*

Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

Examples:
[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Your job is to output the median array for each window in the original array.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Median
---------------               -----
[1  3  -1] -3  5  3  6  7       1
 1 [3  -1  -3] 5  3  6  7       -1
 1  3 [-1  -3  5] 3  6  7       -1
 1  3  -1 [-3  5  3] 6  7       3
 1  3  -1  -3 [5  3  6] 7       5
 1  3  -1  -3  5 [3  6  7]      6
Therefore, return the median sliding window as [1,-1,-1,3,5,6].

Note:
You may assume k is always valid, ie: k is always smaller than input array's size for non-empty array.
Answers within 10^-5 of the actual value will be accepted as correct.



*/


class Solution {
public:
    
    // it store sorted order also support duplicate elements
    multiset<long int> mset;
    vector<double> results;
    
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int ln = nums.size();
        
        if(ln < k) return results;
        for(int i = 0; i<k; i++) {
            mset.insert(nums[i]);
        }
        
        double median;
        
        int ind = k/2;
        
        // odd case
        if(k%2 != 0)
            // starting iterator, distance (from which position element address u want)
            median = *next(mset.begin(), ind);
        else
            // even case
            median = (*next(mset.begin(), ind-1) + *next(mset.begin(), ind))/2.0;
        
        results.push_back(median);
        
        for(int i=k; i<ln; i++) {
            // remove element that is out of window
            int remove_ind = i - k;
            mset.erase(mset.find(nums[remove_ind]));
            // adding new element that is in current window
            mset.insert(nums[i]);
            if(k%2 != 0)
                median = *next(mset.begin(), ind);
            else
                median = (*next(mset.begin(), ind-1) + *next(mset.begin(), ind))/2.0;
            
            results.push_back(median);  
        }
        
        return results;
    }
};
