https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// Find the maximum profit you can achieve. You may complete at most two transactions.

// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

// Example 1:

// Input: prices = [3,3,5,0,0,3,1,4]
// Output: 6
// Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
// Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
*//logic
  // same as best time to buy and sell stocks II but in this we can do only 2 transaction so we use a extra parameter limit we only reduce it
// when the stock is sold and limit keeps a track on number of transactions done so as it reaches 0 we return 0;
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
    int maxProfit(vector<int>& prices) {
        return solve(prices,0,1,2);//sending 2 as limit because we can only do 2 transaction
    }
};
