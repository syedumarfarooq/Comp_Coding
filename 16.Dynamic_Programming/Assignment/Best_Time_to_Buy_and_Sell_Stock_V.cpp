https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
// You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

// Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

// Note:

// You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
// The transaction fee is only charged once for each stock purchase and sale.
 

// Example 1:

// Input: prices = [1,3,2,8,4,9], fee = 2
// Output: 8
// Explanation: The maximum profit can be achieved by:
// - Buying at prices[0] = 1
// - Selling at prices[3] = 8
// - Buying at prices[4] = 4
// - Selling at prices[5] = 9
// The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
*//logic
  //same as best time to buy and sell stocks II as we can make any number of transaction but at the end of the transaction we should deduct
  //the fee from the profit and return the profit
*//Solved using recursion
class Solution {
public:
    int solve(vector<int>&prices,int i,int buy,int fee){
        if(i>=prices.size()){
            return 0;
        }
        int profit=0;
        if(buy){
            int buyItProfit= -prices[i]+solve(prices,i+1,0,fee);
            int skipProfit=solve(prices,i+1,1,fee);
            profit=max(buyItProfit,skipProfit);
        }else{
            int sellItProfit= prices[i]+solve(prices,i+1,1,fee)-fee;//this is where a transaction is complete and fee will also be deducted
            int skipProfit=solve(prices,i+1,0,fee);
            profit=max(sellItProfit,skipProfit);
        }
        return profit;
    }
    int maxProfit(vector<int>& prices,int fee) {
        return solve(prices,0,1,fee);
    }
};
*//solved using mem
class Solution {
public:
    int solveUsingMem(vector<int>&prices,int i,int buy,vector<vector<int>>&dp,int fee){
        if(i>=prices.size()){
            return 0;
        }
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }
        int profit=0;
        if(buy){
            int buyItProfit= -prices[i]+solveUsingMem(prices,i+1,0,dp,fee);
            int skipProfit=solveUsingMem(prices,i+1,1,dp,fee);
            profit=max(buyItProfit,skipProfit);
        }else{
            int sellItProfit= prices[i]+solveUsingMem(prices,i+1,1,dp,fee)-fee;
            int skipProfit=solveUsingMem(prices,i+1,0,dp,fee);
            profit=max(sellItProfit,skipProfit);
        }
        dp[i][buy]=profit;
        return dp[i][buy];
    }
    int maxProfit(vector<int>& prices,int fee) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return solveUsingMem(prices,0,1,dp,fee);
    }
};
*//Solved using tab
class Solution {
public:
    int solveUsingTab(vector<int>&prices,int fee){
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,0));
        for(int i=prices.size()-1;i>=0;i--){//O(n*2)=>O(n)
            for(int buy=0;buy<2;buy++){
                int profit=0;
                if(buy){
                    int buyItProfit= -prices[i]+dp[i+1][0];
                    int skipProfit=dp[i+1][1];
                    profit=max(buyItProfit,skipProfit);
                }else{
                    int sellItProfit= prices[i]+dp[i+1][1]-fee;
                    int skipProfit=dp[i+1][0];
                    profit=max(sellItProfit,skipProfit);
                }
                dp[i][buy]=profit;
            }
            
        }
        
        
        return dp[0][1];
    }
    int maxProfit(vector<int>& prices,int fee) {
        
        return solveUsingTab(prices,fee);
    }
};
*//space optimisation
class Solution {
public:
    int solveUsingTab(vector<int>&prices,int fee){
        vector<int> next(2,0);
        vector<int> curr(2,0);
        for(int i=prices.size()-1;i>=0;i--){
            for(int buy=0;buy<2;buy++){
                int profit=0;
                if(buy){
                    int buyItProfit= -prices[i]+next[0];
                    int skipProfit=next[1];
                    profit=max(buyItProfit,skipProfit);
                }else{
                    int sellItProfit= prices[i]+next[1]-fee;
                    int skipProfit=next[0];
                    profit=max(sellItProfit,skipProfit);
                }
                curr[buy]=profit;
            }
            next=curr;
        }
        
        
        return curr[1];
    }
    int maxProfit(vector<int>& prices,int fee) {
        
        return solveUsingTab(prices,fee);
    }
};
