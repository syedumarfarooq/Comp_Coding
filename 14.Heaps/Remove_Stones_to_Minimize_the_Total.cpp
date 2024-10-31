https://leetcode.com/problems/remove-stones-to-minimize-the-total/description/
// You are given a 0-indexed integer array piles, where piles[i] represents the number of stones in the ith pile, and an integer k. You should apply the following operation exactly k times:

// Choose any piles[i] and remove floor(piles[i] / 2) stones from it.
// Notice that you can apply the operation on the same pile more than once.

// Return the minimum possible total number of stones remaining after applying the k operations.

// floor(x) is the greatest integer that is smaller than or equal to x (i.e., rounds x down).

 

// Example 1:

// Input: piles = [5,4,9], k = 2
// Output: 12
// Explanation: Steps of a possible scenario are:
// - Apply the operation on pile 2. The resulting piles are [5,4,5].
// - Apply the operation on pile 0. The resulting piles are [3,4,5].
// The total number of stones in [3,4,5] is 12.
*//LOGIC********
//as the question say we can divide a stone by 2 and subtract from the total and this operation can be done k times on any of the stone to minimize the total 
//Basic logic say if we do the operation on the bigger rocks than only we can minimize the total 
*//SOLUTION********
  class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> maxHeap;
        for(int i=0;i<piles.size();i++){
            maxHeap.push(piles[i]);
        }
        while(k--){
            int maxElement=maxHeap.top();
            maxHeap.pop();
            maxElement=maxElement-floor(maxElement/2);
            maxHeap.push(maxElement);
        }
        int sum=0;
        while(!maxHeap.empty()){
            sum+=maxHeap.top();
            maxHeap.pop();
        }
        return sum;
    }
};
