https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
// You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

// Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

// Example 1:

// Input: k = 2, prices = [2,4,1]
// Output: 2
// Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
*//logic
  // same as best time to buy and sell stock iii but here we have to change limits i.e no of transactions based on the question i.e k
*//solved using recursion
class Solution {
public:
    int solve(vector<int>&prices,int i,int buy,int limit){
        if(i>=prices.size()||limit==0){
            return 0;
        }
        int profit=0;
        if(buy){
            int buyItProfit= -prices[i]+solve(prices,i+1,0,limit);
            int skipProfit=solve(prices,i+1,1,limit);
            profit=max(buyItProfit,skipProfit);
        }else{
            int sellItProfit= prices[i]+solve(prices,i+1,1,limit-1);//only limit decrements here because this is where stock is sold and 
          //considered one traction as completed
            int skipProfit=solve(prices,i+1,0,limit);
            profit=max(sellItProfit,skipProfit);
        }
        return profit;
    }
    int maxProfit(int k,vector<int>& prices) {
        return solve(prices,0,1,2);//sending 2 as limit because we can only do 2 transaction
    }
};
*//solved using mem
class Solution {
public:
    int solveMem(vector<int>&prices,int i,int buy,int limit,vector<vector<vector<int>>>&dp){
        if(i>=prices.size()||limit==0){
            return 0;
        }
        if(dp[i][buy][limit]!=-1){
            return dp[i][buy][limit];
        }
        int profit=0;
        if(buy){
            int buyItProfit= -prices[i]+solveMem(prices,i+1,0,limit,dp);
            int skipProfit=solveMem(prices,i+1,1,limit,dp);
            profit=max(buyItProfit,skipProfit);
        }else{
            int sellItProfit= prices[i]+solveMem(prices,i+1,1,limit-1,dp);
            int skipProfit=solveMem(prices,i+1,0,limit,dp);
            profit=max(sellItProfit,skipProfit);
        }
        dp[i][buy][limit]=profit;
        return dp[i][buy][limit];
    }
    int maxProfit(int k,vector<int>& prices) {
        //as there variable are changing we are making 3d dp
       vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2,vector<int>(k+1,-1)));//as limit can have 3 values 0,1,2 so size is 3 
        return solveMem(prices,0,1,k,dp);
    }
};
*//solved using tab
class Solution {
public:
    int solveTab(vector<int>&prices,int k){
        vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        for(int i=prices.size()-1;i>=0;i--){
            for(int buy=0;buy<2;buy++){
                for(int limit=1;limit<k+1;limit++){//starting from limit 1 as for limit=0 we have to return 0 as
                //we are intialising everthing with 0 so we can start from 1
                    int profit=0;
                        if(buy){
                            int buyItProfit= -prices[i]+dp[i+1][0][limit];
                            int skipProfit=dp[i+1][1][limit];
                            profit=max(buyItProfit,skipProfit);
                        }else{
                            int sellItProfit= prices[i]+dp[i+1][1][limit-1];
                            int skipProfit=dp[i+1][0][limit];
                            profit=max(sellItProfit,skipProfit);
                        }
                        dp[i][buy][limit]=profit;
                }

            }
        }
        
        
        return dp[0][1][k];
    }
    int maxProfit(int k,vector<int>& prices) {
        //as there variable are changing we are making 3d dp
       
        return solveTab(prices,k);
    }
};
*//Space optimisation
class Solution {
public:
    int solveTab(vector<int>&prices,int k){
        // vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2,vector<int>(3,0)));
        vector<vector<int>>next(2,vector<int>(k+1,0));
        vector<vector<int>>curr(2,vector<int>(k+1,0));
        for(int i=prices.size()-1;i>=0;i--){
            for(int buy=0;buy<2;buy++){
                for(int limit=1;limit<k+1;limit++){
                    int profit=0;
                        if(buy){
                            int buyItProfit= -prices[i]+next[0][limit];
                            int skipProfit=next[1][limit];
                            profit=max(buyItProfit,skipProfit);
                        }else{
                            int sellItProfit= prices[i]+next[1][limit-1];
                            int skipProfit=next[0][limit];
                            profit=max(sellItProfit,skipProfit);
                        }
                        curr[buy][limit]=profit;
                }

            }
            next=curr;
        }
        
        
        return curr[1][k];
    }
    int maxProfit(int k,vector<int>& prices) {
       
       
        return solveTab(prices,k);
    }
};
*//another method space optimisation
  // in this we are creating 3 d only but the size is taken as 2 ,so as the curr depends on the next row itself
class Solution {
public:
    int solveTab(vector<int>&prices,int k){
        vector<vector<vector<int>>>dp(2,vector<vector<int>>(2,vector<int>(k+1,0)));
       
        for(int i=prices.size()-1;i>=0;i--){
            for(int buy=0;buy<2;buy++){
                for(int limit=1;limit<k+1;limit++){
                    int profit=0;
                        if(buy){
                            int buyItProfit= -prices[i]+dp[1][0][limit];
                            int skipProfit=dp[1][1][limit];
                            profit=max(buyItProfit,skipProfit);
                        }else{
                            int sellItProfit= prices[i]+dp[1][1][limit-1];
                            int skipProfit=dp[1][0][limit];
                            profit=max(sellItProfit,skipProfit);
                        }
                        dp[0][buy][limit]=profit;
                }

            }
            dp[1]=dp[0];
        }
        
        
        return dp[0][1][k];
    }
    int maxProfit(int k,vector<int>& prices) {
       
       
        return solveTab(prices,k);
    }
};
