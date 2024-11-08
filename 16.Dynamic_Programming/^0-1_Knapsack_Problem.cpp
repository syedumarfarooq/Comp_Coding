https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
// You are given the weights and values of items, and you need to put these items in a knapsack of capacity capacity to achieve the maximum total value in the knapsack. Each item is available in only one quantity.

// In other words, you are given two integer arrays val[] and wt[], which represent the values and weights associated with items, respectively. You are also given an integer capacity, which represents the knapsack capacity. Your task is to find the maximum sum of values of a subset of val[] such that the sum of the weights of the corresponding subset is less than or equal to capacity. You cannot break an item; you must either pick the entire item or leave it (0-1 property).

// Examples :

// Input: capacity = 4, val[] = [1, 2, 3], wt[] = [4, 5, 1] 
// Output: 3
// Explanation: Choose the last item, which weighs 1 unit and has a value of 3.
*//Using 2DDP as there are two dimenstions changing
*//Logic
// we are including and excluding whichever gives maximum answer will be returned
*//similar to knapsack problem's pattern 
// -subset sum
// -equal subset sum partition
// -min subset sum difference
  *//Using recursion
//   class Solution {
//   public:
// int solveUsingRecursion(int capacity,int index,vector<int> &val, vector<int> &wt){
//         //index= index of last element, and we are traversing right to left
//         //base case ->only one 1 item left
//         if(index==0){
//             if(wt[0]<=capacity){
//                 return val[0];
//             }else{
//                 return 0;
//             }
//         }
//         int include=0;
//         if(wt[index]<=capacity){
//             include=val[index]+solveUsingRecursion(capacity-wt[index],index-1,val,wt);
//         }
//         int exclude=0+solveUsingRecursion(capacity,index-1,val,wt);
//         int ans=max(include,exclude);
//         return ans;
//     }
//     int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
//         int n=val.size()-1;
//         int ans=solveUsingRecursion(capacity,n,val,wt);
//         return ans;
//     }
// };
  *//Using memoisation
// class Solution {
//   public:
//     // Function to return max value that can be put in knapsack of capacity.
    

//     int solveUsingMem(int capacity,int index,vector<int> &val, vector<int> &wt, vector<vector<int>>&dp){
//         //index= index of last element, and we are traversing right to left
//         //base case ->only one 1 item left
//         if(index==0){
//             if(wt[0]<=capacity){
//                 return val[0];
//             }else{
//                 return 0;
//             }
//         }
//         if(dp[index][capacity]!=-1){
//             return dp[index][capacity];
//         }
//         int include=0;//used this bcz will include only if weight less than capacity orelse 0
//         if(wt[index]<=capacity){
//             include=val[index]+solveUsingMem(capacity-wt[index],index-1,val,wt,dp);
//         }
//         int exclude=0+solveUsingMem(capacity,index-1,val,wt,dp);
//         dp[index][capacity]=max(include,exclude);
//         return dp[index][capacity];
//     }
//     int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
//         int n=val.size()-1;
//         //as there are 2 parameters changing so using 2DDP
//         vector<vector<int>>dp(n+1,vector<int>(capacity+1,-1));
//         int ans=solveUsingMem(capacity,n,val,wt,dp);
//         return ans;
//     }
// };
