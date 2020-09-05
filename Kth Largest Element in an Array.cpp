/*
Kth Largest Element in an Array

Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.


*/


class Solution {
public:
    
    void max_heap(vector<int>& nums, int i, int ln) {
        
        int l = 2*i + 1;
        int r = 2*i + 2;
        int lar = i;
        
        if(l < ln && nums[lar] < nums[l])
            lar = l;
        
        if(r < ln && nums[lar] < nums[r])
            lar = r;
        
        if(i!=lar){
            int tmp = nums[i];
            nums[i] = nums[lar];
            nums[lar] = tmp;
            max_heap(nums, lar, ln);
        }
        
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int ln = nums.size();
        for(int i=(ln/2)-1; i>=0; i--){
            max_heap(nums, i, ln);
        }
    
        for(int i=ln-1; i>=ln-k; i--) {
            int tmp = nums[0];
            nums[0] = nums[i];
            nums[i] = tmp;
            max_heap(nums, 0, i);
        }
        return nums[ln- k];
    }
};



// more efficient solution 



class Solution {
public:
    
    // Min heap code
    void heapify(vector<int> &arr, int i, int k) {
        
        int l = 2*i+1;
        int r = 2*i+2;
        int lar = i;
        
        if(l<k && arr[l]<arr[lar])
            lar = l;
        
        if(r<k && arr[r]<arr[lar])
            lar = r;
        
        if(i!=lar) {
            int t = arr[i];
            arr[i] = arr[lar];
            arr[lar] = t;
            heapify(arr, lar, k);
        }
        
    }
    int findKthLargest(vector<int>& nums, int k) {
        
        // taking k size space to build min heap
        vector<int> arr(k);
        // inserting my first k elements to arr
        for(int i=0; i<k; i++)
            arr[i] = nums[i];
        
        //now making min heap of size k => T.C (k long k)
        for(int i = (k/2)-1; i>=0; i--){
            heapify(arr, i, k);
        }
        
        // checking now rest elements
        for(int i=k; i<nums.size(); i++) {
            // if value >= to min heap root then insert in my min heap root and heapify
            // and value < of min heap root then do nothing
            if(nums[i]>=arr[0]) {
                arr[0] = nums[i];
                heapify(arr, 0, k);
            }
        }
        
        return arr[0];
        
    }
};



// or


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minheap;
        
        for(int i=0; i<nums.size(); i++) {
            if(minheap.size() < k){
                minheap.push(nums[i]);
            }else{
                minheap.push(nums[i]);
                minheap.pop();
            }
        }
        
        return minheap.top();
    }
};



// or

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minheap;
        
        for(int i=0; i<nums.size(); i++) {
            if(minheap.size() < k){
                minheap.push(nums[i]);
            }else if(nums[i] > minheap.top()){
                minheap.pop();
                minheap.push(nums[i]);
            }
        }
        
        return minheap.top();
    }
};

