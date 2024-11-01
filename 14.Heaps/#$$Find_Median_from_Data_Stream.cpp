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
#include <iostream>
#include<queue>
#include<vector>
using namespace std;
 
int signum(int a , int b) {
        if(a == b) 
                return 0;
        if(a > b )
                return -1;
        if(a < b)
                return 1;
}

void callMedian(double &median, priority_queue<int>& maxHeap, priority_queue<int, vector<int>, greater<int> >& minHeap, int element) {

        switch(signum( maxHeap.size(),minHeap.size())) {
                case 0:if(element > median) {
                        minHeap.push(element);
                        median = minHeap.top();
                        }
                        else {
                        maxHeap.push(element);
                        median = maxHeap.top();
                       }
                        break;
                case 1: if(element > median ) {//as there is extra element on the right so if the element is
                //greatere than median we have to add it on the right but this makes the right side which is
                //the minHeap even bigger by the size of 2 (which myght create in finding median as it comes in 
                // between) to equate it we remove the top element of minHeap and 
                // add it to maxHeap by this we can add the element to the minHeap to equate it
                
                        int minTop = minHeap.top();
                        minHeap.pop();
                        maxHeap.push(minTop);
                        minHeap.push(element);
                        median = (minHeap.top() + maxHeap.top())/2.0;
                        }
                        else {
                        //as there is an extra element on the right side i.e is minHeap there no problem in adding element
                        //to maxHeap i.e on the left side this makes it equal
                        maxHeap.push(element);
                        median = (minHeap.top() + maxHeap.top())/2.0;
                        }
                        break;
                case -1: if(element > median) {
                        //in this the left side maxHeap is greater so if the element is greater than median then we 
                        //have to add it on the right side which creates no problem as it will equate the side on both
                        // sides
                        minHeap.push(element);
                        median = (minHeap.top() + maxHeap.top())/2.0;
                         }
                         else {
                        int maxTop = maxHeap.top();
                        maxHeap.pop();
                        minHeap.push(maxTop);
                        maxHeap.push(element);
                        median = (minHeap.top() + maxHeap.top())/2.0;
                        }
                        break;

        }

}

int main() {
        int arr[12] = {5,15,1,3,2,8,7,9,10,6,11,4};
        int n = 12;

        //5 6 5 6 5 6
        double median = 0;
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int> > minHeap;
        for(int i=0; i<n; i++) {
                int element = arr[i];
                callMedian(median, maxHeap,minHeap, element);
                cout << "arr[i]->median:  " << median << endl;
        }cout << endl;



        return 0;
}
