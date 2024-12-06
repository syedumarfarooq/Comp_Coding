https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

// Find and return the maximum profit you can achieve.

 

// Example 1:

// Input: prices = [7,1,5,3,6,4]
// Output: 7
// Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
// Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
// Total profit is 4 + 3 = 7.
// Example 2:

// Input: prices = [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
// Total profit is 4.
*//logic
 //go through best time to buy and sell stocks 1 before solving this
  // we are taking a variable buy which tells us that we can buy or not and we can sell only if we have bought it,we calculate profit 
// the profit formula is sellprice-buy price so while buying the profit formula becomes -buyprice+sell price it all the same
*//using recursion
class Solution {
public:
    int solve(vector<int>&prices,int i,int buy){
        if(i>=prices.size()){
            return 0;
        }
        int profit=0;
        if(buy){
            int buyItProfit= -prices[i]+solve(prices,i+1,0);//-buyingPrice(currentday price) + selling price which is in the future for this
          //we have to mark buy as 0 as we already bought
            int skipProfit=solve(prices,i+1,1);//if we want to skip this buying
            profit=max(buyItProfit,skipProfit);
        }else{
            int sellItProfit= prices[i]+solve(prices,i+1,1);//selling only happens only when there is something bought earlier and the
          //recursive code is asking the value of selling prices so we send the selling price with the profit for the next iteration too
          //so the solve will iterativily find the total profit from the next index and addes it to the sellitprofit then the buyitprofit will 
          //minus the total profit which includes the selling price and the next profit of the remaining days and give answer
            int skipProfit=solve(prices,i+1,0);
            profit=max(sellItProfit,skipProfit);
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        return solve(prices,0,1);
    }
};
*//Solve using mem
class Solution {
public:
    int solveUsingMem(vector<int>&prices,int i,int buy,vector<vector<int>>&dp){
        if(i>=prices.size()){
            return 0;
        }
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }
        int profit=0;
        if(buy){
            int buyItProfit= -prices[i]+solveUsingMem(prices,i+1,0,dp);
            int skipProfit=solveUsingMem(prices,i+1,1,dp);
            profit=max(buyItProfit,skipProfit);
        }else{
            int sellItProfit= prices[i]+solveUsingMem(prices,i+1,1,dp);
            int skipProfit=solveUsingMem(prices,i+1,0,dp);
            profit=max(sellItProfit,skipProfit);
        }
        dp[i][buy]=profit;
        return dp[i][buy];
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return solveUsingMem(prices,0,1,dp);
    }
};
*//Solved using tabulation
class Solution {
public:
    int solveUsingTab(vector<int>&prices){
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,0));
        for(int i=prices.size()-1;i>=0;i--){//O(n*2)=>O(n)
            for(int buy=0;buy<2;buy++){
                int profit=0;
                if(buy){
                    int buyItProfit= -prices[i]+dp[i+1][0];
                    int skipProfit=dp[i+1][1];
                    profit=max(buyItProfit,skipProfit);
                }else{
                    int sellItProfit= prices[i]+dp[i+1][1];
                    int skipProfit=dp[i+1][0];
                    profit=max(sellItProfit,skipProfit);
                }
                dp[i][buy]=profit;
            }
            
        }
        
        
        return dp[0][1];
    }
    int maxProfit(vector<int>& prices) {
        
        return solveUsingTab(prices);
    }
};
*//Space optimisation
class Solution {
public:
    int solveUsingTab(vector<int>&prices){
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
                    int sellItProfit= prices[i]+next[1];
                    int skipProfit=next[0];
                    profit=max(sellItProfit,skipProfit);
                }
                curr[buy]=profit;
            }
            next=curr;
        }
        
        
        return curr[1];
    }
    int maxProfit(vector<int>& prices) {
        
        return solveUsingTab(prices);
    }
};
