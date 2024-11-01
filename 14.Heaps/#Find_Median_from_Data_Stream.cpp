https://leetcode.com/problems/find-median-from-data-stream/
// The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

// For example, for arr = [2,3,4], the median is 3.
// For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
// Implement the MedianFinder class:

// MedianFinder() initializes the MedianFinder object.
// void addNum(int num) adds the integer num from the data stream to the data structure.
// double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
 

// Example 1:

// Input
// ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
// [[], [1], [2], [], [3], []]
// Output
// [null, null, null, 1.5, null, 2.0]

// Explanation
// MedianFinder medianFinder = new MedianFinder();
// medianFinder.addNum(1);    // arr = [1]
// medianFinder.addNum(2);    // arr = [1, 2]
// medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
// medianFinder.addNum(3);    // arr[1, 2, 3]
// medianFinder.findMedian(); // return 2.0
*//LOGIC****
// we will use the combination of max and min heap the first half we will put it in maxheap the second half in min heap so that after the 
// greatest element of the left half there will be a median present after that the smallest number in the second half then it will continue
*//LEETCODE SOLUTION****
//   class MedianFinder {
// public:
//     priority_queue<int> maxHeap;
//     priority_queue<int, vector<int>, greater<int> > minHeap;
//     MedianFinder() {
//         maxHeap.push(INT_MIN);//doing this because if it is null showing error
//         minHeap.push(INT_MAX);//doing this because if it is null showing error
//     }
    
    
//     int signum(int a , int b) {
//         if(a == b) 
//                 return 0;
//         if(a > b )
//                 return -1;
//         if(a < b)
//                 return 1;
//         return 2;
//         }       
//     void addNum(int num) {
        
//          switch(signum(maxHeap.size(),minHeap.size())) {
//                 case 0:if(num > findMedian()) {
//                         minHeap.push(num);
//                         }
//                         else {
//                         maxHeap.push(num);
//                        }
//                         break;
//                 case 1: if(num >findMedian() ) {
//                         int minTop = minHeap.top();
//                         minHeap.pop();
//                         maxHeap.push(minTop);
//                         minHeap.push(num);
//                         }
//                         else {
//                         maxHeap.push(num);
//                         }
//                         break;
//                 case -1: if(num > findMedian()) {
//                         minHeap.push(num);
//                          }
//                          else {
//                         int maxTop = maxHeap.top();
//                         maxHeap.pop();
//                         minHeap.push(maxTop);
//                         maxHeap.push(num);
//                         }
//                         break;

//         }
        
        
    
//     }
    
//     double findMedian() {
//         switch(signum(maxHeap.size(),minHeap.size())) {
//                 case 0:return (minHeap.top() + maxHeap.top())/2.0;
//                         break;
//                 case 1: return minHeap.top()*1.0;
//                         break;
//                 case -1: return maxHeap.top()*1.0;
//                         break;

//         }
//         return 0.0;
//     }
// };

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
*//Solution to Understand****
