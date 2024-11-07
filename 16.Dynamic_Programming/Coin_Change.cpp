https://leetcode.com/problems/coin-change/description/
// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.

 

// Example 1:

// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1
// Example 2:

// Input: coins = [2], amount = 3
// Output: -1
// Example 3:

// Input: coins = [1], amount = 0
// Output: 0
*//Using recursion TLE
// class Solution {
// public:
//     int solveUsingRecursion(vector<int>& coins,int amount){
//         if(amount==0){
//             return 0;
//         }
//         if(amount<0){
//             return INT_MAX;//we are not considering the not possible solution
//         }
//         int mini=INT_MAX;
//         for(int i=0;i<coins.size();i++){
//             int ans=solveUsingRecursion(coins,amount-coins[i]);
//             if(ans!=INT_MAX){
//                 mini=min(mini,1+ans);
//             }
//         }
//         return mini;
//     }
//     int coinChange(vector<int>& coins, int amount) {
//         int ans=solveUsingRecursion(coins,amount);
//         if(ans==INT_MAX){
//             return -1;
//         }else{
//             return ans;
//         }
//     }
// };
*//Top down method**
//  class Solution {
// public:
//     int solveMem(vector<int>& coins,int amount,vector<int>&dp){
//         if(amount==0){
//             return 0;
//         }
//         if(amount<0){
//             return INT_MAX;//we are not considering the not possible solution
//         }
//         if(dp[amount]!=-1){
//             return dp[amount];
//         }
//         int mini=INT_MAX;
//         for(int i=0;i<coins.size();i++){
//             int ans=solveMem(coins,amount-coins[i],dp);
//             if(ans!=INT_MAX){
//                 mini=min(mini,1+ans);
//             }
//         }
//         dp[amount]=mini;
//         return dp[amount];
//     }
//     int coinChange(vector<int>& coins, int amount) {
//         vector<int> dp(amount+1,-1);
//         int ans=solveMem(coins,amount,dp);
//         if(ans==INT_MAX){
//             return -1;
//         }else{
//             return ans;
//         }
//     }
// };
 *//Bottom up or tabular method
 class Solution {
public:
    int solveTab(vector<int>& coins,int amount){
        vector<int> dp(amount+1,INT_MAX);//here dp[i] determines the minimum number of coins neede so we are using intmax to compare
        dp[0]=0;

        
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(i-coins[j]>=0&&dp[i-coins[j]]!=INT_MAX){
                    int ans=dp[i-coins[j]];
                    dp[i]=min(dp[i],ans+1);
                }
                
            }
        }
        
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        
        int ans=solveTab(coins,amount);
        if(ans==INT_MAX){
            return -1;
        }else{
            return ans;
        }
    }
};
