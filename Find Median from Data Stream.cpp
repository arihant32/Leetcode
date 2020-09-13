/*

Find Median from Data Stream


Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

For example,
[2,3,4], the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
 

Example:

addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3) 
findMedian() -> 2
 

Follow up:

If all integer numbers from the stream are between 0 and 100, how would you optimize it?
If 99% of all integer numbers from the stream are between 0 and 100, how would you optimize it?


*/




class MedianFinder {
public:
    /** initialize your data structure here. */
    
    // Taking two heaps max and min
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        // 1. Initialy both the heaps is empty so adding it in maxHeap
        // 2. if num is less than max heap root then add it in maxHeap else minHeap
        // Eg :      1  2  3         4  5  6
        //       (MaxHeap block)  (MinHeap block)
        
        if(maxHeap.empty() && minHeap.empty())
            maxHeap.push(num);
        else if(num < maxHeap.top())
            maxHeap.push(num); 
        else
            minHeap.push(num);
        
        // difference b/w size of maxheap and minheap should be less than equal to one
        // if not then balance both the heap
        
        int max_h_size = maxHeap.size();
        int min_h_size = minHeap.size();
        
        if(max_h_size - min_h_size > 1) {
            int t = maxHeap.top();
            maxHeap.pop();
            minHeap.push(t);
        } else if(min_h_size - max_h_size > 1){
            int t = minHeap.top();
            minHeap.pop();
            maxHeap.push(t);
        }
    }
    
    double findMedian() {
        
        double median;
        
        int max_h_size = maxHeap.size();
        int min_h_size = minHeap.size();
        
        // even length case
        if(max_h_size == min_h_size) {
            median = (maxHeap.top() + minHeap.top())/2.0;
        } 
        // old length case
        else if(max_h_size > min_h_size) {
            median = maxHeap.top();
        // old length case
        }else{
            median = minHeap.top();
        }
        
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
