*//Question 4
  https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1
// Minimum Cost rope
// Given an array, arr[] of rope lengths, connect all ropes into a single rope with the minimum total cost. The cost to connect two ropes is the sum of their lengths. 
*//logic
  // in this we are using greedy method by joing the minimum length ropes first then the next and so on
  //we use min heap as it returns minimum element in O(1)
  class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    int minCost(vector<int>& arr) {
        priority_queue<int, vector<int>, greater<int> > pq;
        for(int i=0; i<arr.size(); i++) {
            pq.push(arr[i]);
        }
        int cost = 0;
        while(pq.size() != 1) {//will do processing until there is one element left 
            int first = pq.top();//fetching the first minimum element
            pq.pop();
            int second = pq.top();//fetching the second minimum element
            pq.pop();
        
            cost += first + second;//adding it to the cost 
            int newLength = first + second;//adding the joined rope back to the pq
            pq.push(newLength);
        
          }
          return cost;
    }
};
