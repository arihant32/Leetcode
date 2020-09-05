/*

Kth Largest Element in a Stream

Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Your KthLargest class will have a constructor which accepts an integer k and an integer array nums, which contains initial elements from the stream. For each call to the method KthLargest.add, return the element representing the kth largest element in the stream.

Example:

int k = 3;
int[] arr = [4,5,8,2];
KthLargest kthLargest = new KthLargest(3, arr);
kthLargest.add(3);   // returns 4
kthLargest.add(5);   // returns 5
kthLargest.add(10);  // returns 5
kthLargest.add(9);   // returns 8
kthLargest.add(4);   // returns 8
Note:
You may assume that nums' length ≥ k-1 and k ≥ 1.



*/

class KthLargest {
public:
    int k_size;
    vector<int> v;
    KthLargest(int k, vector<int>& nums) {
        k_size = k;
        int ln = nums.size();
        if(ln>0) {
            int h_size = (k<=ln) ? k : ln;
            v.resize(h_size);
            build_min_heap_of_k_size(nums);
        }     
    }
    
    void build_min_heap_of_k_size(vector<int>& nums) {
        int ln = nums.size();
        // if k is large and nums of elements are less
        for(int i=0; (i<k_size && i<ln); i++)
            v[i] = nums[i];
        
        // if v having less than k elements
        for(int i=(v.size()/2)-1; i>=0; i--) {
            heapify(v, i, v.size());
        }
        
        // for rest elements
        for(int i=k_size; i<nums.size(); i++) {
            if(nums[i]>=v[0]) {
                v[0] = nums[i];
                heapify(v, 0, k_size);
            }     
        }
    }
    
    void heapify(vector<int> &v, int i, int k) {
        int l = 2*i+1;
        int r = 2*i+2;
        int lar = i;
        
        if(l<k && v[l]<v[lar])
            lar = l;
        
        if(r<k && v[r]<v[lar])
            lar = r;
        
        if(lar!=i) {
            int t = v[lar];
            v[lar] = v[i];
            v[i] = t;
            heapify(v, lar, k);
        }    
    }
    
    int add(int val) {
        if(v.empty()) {
            v.resize(k_size);
            v[0] = val;
            heapify(v, 0, 1);
        }
        else if(v.size() < k_size) {
            v.push_back(val);
            heapify(v, 0, v.size());
        }
        else if(val>=v[0]) {
            v[0] = val;
            heapify(v, 0, k_size);
        }
        return v[0];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */




// or


class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minheap;
    int K;
    
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(int i=0; i<nums.size(); i++) {
            if(minheap.size() < K){
                minheap.push(nums[i]);
            }
            else{
                minheap.push(nums[i]);
                minheap.pop();
            }
        }
    }
    
    int add(int val) {
        if(minheap.size() < K) {
            minheap.push(val);
        } 
        else {
            minheap.push(val);
            minheap.pop(); 
        }
        return minheap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

