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
*//Using Tabular method
//  class Solution {
//   public:
//     // Function to return max value that can be put in knapsack of capacity.
    

//     int solveUsingTabular(int capacity,int index,vector<int> &val, vector<int> &wt){
//         //index= index of last element , and we are traversing right to left
        
//         //here 2 d array tell for that index and capacity(j) what is the maximum value can be put
//         // eg:capacity = 4, val[] = [1, 2, 3], wt[] = [4, 5, 1]  here for index 0 the value
//         // 1 value can be placed if capacity is 4 or more as it takes that much of capacity
//         int n=val.size()-1;
//         vector<vector<int>>dp(n+1,vector<int>(capacity+1,0));
        
//         // at index i the value i will be placed only if it has that much weight left in the bag 
//         //so the capacity start from weight[0] as the value of i can be placed if weight i is left
//         for(int w=wt[0];w<=capacity;w++){
//             if(wt[0]<=capacity){
//                 dp[0][w]=val[0];
//             }else{
//                 dp[0][w]=0;
//             }
//         }
        
//         for(int index=1; index<=n; index++) {
//     for(int w=0; w<=capacity; w++) {
//       //include and exclude
//       int include = 0;
//       if(wt[index] <= w)
//         include = val[index] + dp[index-1][w - wt[index]];
    
//       int exclude = 0 + dp[index-1][w];
    
//       dp[index][w]= max(include, exclude);
      
//     }
//   }
//   return dp[n][capacity]; 
//     }
//  int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
//         int n=val.size()-1;
        
//         int ans=solveUsingTabular(capacity,n,val,wt);
//         return ans;
//     }
// };
 *//Using space optimisation
 // as from above we need only two array one is current to save value and prev one which is to retrieve value to find include and exclude
 class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity.
    

    int solveUsingSO(int capacity,int n,vector<int> &val, vector<int> &wt){
        //index= index of last element , and we are traversing right to left
        vector<int> prev(capacity+1,0);
        vector<int> curr(capacity+1,0);
        for(int w=wt[0];w<=capacity;w++){
            if(wt[0]<=capacity){
                prev[w]=val[0];
            }else{
                prev[w]=0;
            }
        }
        
    for(int index=1; index<=n; index++) {
        for(int w=0; w<=capacity; w++) {
          //include and exclude
          int include = 0;
          if(wt[index] <= w)
            include = val[index] + prev[w - wt[index]];
        
          int exclude = 0 + prev[w];
        
          curr[w]= max(include, exclude);
          
        }
        //shift
          prev=curr;//might make mistake here
    }
  
  return prev[capacity]; 
    }
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        int n=val.size()-1;
        
        int ans=solveUsingSO(capacity,n,val,wt);
        return ans;
    }
};
