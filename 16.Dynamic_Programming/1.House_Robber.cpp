https://leetcode.com/problems/house-robber/
// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

// Example 1:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.
*//Using Recursion TLE
//   class Solution {
// public:
//     int solveUsingRecursion(vector<int>& nums,int n){//n->represents the index of current house
//         if(n<0){
//             return 0;
//         }
//         if(n==0){
//             return nums[0];
//         }
//         //include
//         int include=solveUsingRecursion(nums,n-2) +nums[n];
//         int exclude=solveUsingRecursion(nums,n-1)+0;
//         return max(include,exclude);
//     }
//     int rob(vector<int>& nums) {
//         int n=nums.size()-1;
//         return solveUsingRecursion(nums,n);
//     }
// };
  *//using memoisation of top down 
//   class Solution {
// public:
//     int solveUsingMem(vector<int>& nums,int n,vector<int>&dp){//n->represents the index of current house
//         if(n<0){
//             return 0;
//         }
//         if(n==0){
//             return nums[0];
//         }
//         if(dp[n]!=-1){
//             return dp[n];
//         }
//         //include
//         int include=solveUsingMem(nums,n-2,dp) +nums[n];
//         int exclude=solveUsingMem(nums,n-1,dp)+0;
//         dp[n]=max(include,exclude);
//         return dp[n];
//     }
//     int rob(vector<int>& nums) {
//         int n=nums.size()-1;
//         vector<int> dp(n+1,-1);
//         return solveUsingMem(nums,n,dp);
//     }
// };
  *//Tabulation
//   class Solution {
// public:
//     int solveUsingTabulation(vector<int>& nums,int n){//n->represents the index of current house
//         vector<int> dp(n+1,0);
//         dp[0]=nums[0];
//         for(int i=1;i<=n;i++){
//             int temp=0;//for i=1 there is no i-2 so we are using 0
//             if(i-2>=0){//we are doing this only for i=1 if we minus i-2 error so
//                temp=dp[i-2];
//             }
//              int include=temp +nums[i];
//              int exclude=dp[i-1]+0;
//              dp[i]=max(include,exclude);
        
//         }
//         return dp[n];
        
        
//     }
//     int rob(vector<int>& nums) {
//         int n=nums.size()-1;
        
//         return solveUsingTabulation(nums,n);
//     }
// };
 *//Space Optimisation
 class Solution {
public:
    int solveUsingTabulation(vector<int>& nums,int n){//n->represents the index of current house
        int prev2=0;
        int prev1=nums[0];
        int curr=0;
        for(int i=1;i<=n;i++){
            int temp=0;
            if(i-2>=0){//we are doing this only for i=1 if we minus i-2 error so
               temp=prev2;
            }
             int include=temp +nums[i];
             int exclude=prev1+0;
             curr=max(include,exclude);
             prev2=prev1;
             prev1=curr;

        
        }
        return prev1;//we used prev1 insted of curr if nums had only one element
        //then we should print nums[0] itself and in the loop prev1 is set to curr
        
        
    }
    int rob(vector<int>& nums) {
        int n=nums.size()-1;
        
        return solveUsingTabulation(nums,n);
    }
};
