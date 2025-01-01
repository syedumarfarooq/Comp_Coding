https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/0
*//my guess coin change can be solve using this method
// Given start, end and an array arr of n numbers. At each step, start is multiplied with any number in the array and then mod operation with 100000 is done to get the new start.

// Your task is to find the minimum steps in which end can be achieved starting from start. If it is not possible to reach end, then return -1.

// Example 1:

// Input:
// arr[] = {2, 5, 7}
// start = 3, end = 30
// Output:
// 2
// Explanation:
// Step 1: 3*2 = 6 % 100000 = 6 
// Step 2: 6*5 = 30 % 100000 = 30
*//logic
  // in this we are using bfs and considering start as the begining node we multiply with all the values in the array and make new nodes
  // and mark visited in the ans array by marking the arr[newNodes] to the steps taken to reach that node (i.e previous +1) as every step is counted one
//we are using bfs as the first time we are finding the destination is the shortest path to it
*//code
class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<int>q;
        const int mod=100000;//as the value of start and end can range until 100000 and multiplying them can takes us out of range
      //if we mod it with 100000 the value will be inside the range of 100000
        vector<int>ans(100000,-1);//will also work as visited array in BFS
        ans[start]=0;//marking the ans[start]=0 as it has taken 0 steps
        q.push(start);
        while(!q.empty()){
            int front=q.front();
            q.pop();
            if(front==end)return ans[end];
            for(auto it:arr){
                int newNode=(front*it)%mod;
                if(ans[newNode]==-1){//if the node is already created i.e visited then we dont visite again
                    ans[newNode]=ans[front]+1;
                    q.push(newNode);
                }
            }
        }
        return -1;
    }
};
