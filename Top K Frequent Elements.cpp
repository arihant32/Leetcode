/*

Top K Frequent Elements


Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
You can return the answer in any order.



*/




class Solution {
public:
    
    typedef pair<int,int> pp;
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int ln = nums.size();
        vector<int> result;
        
        // used to count no of elements
        unordered_map<int,int> mp;
        for(auto val : nums) {
            mp[val]++;
        }
        
        // Min Heap using STL
        priority_queue<pp, vector<pp>, greater<pp>> min_heap;
        
        for(auto ptr=mp.begin(); ptr!=mp.end(); ptr++) {
            min_heap.push({ptr->second, ptr->first});
            if(min_heap.size()>k)
                min_heap.pop();   
        }
        
        while(!min_heap.empty()) {
            result.push_back(min_heap.top().second);
            min_heap.pop();
        }
        
        return result;
    }
};
