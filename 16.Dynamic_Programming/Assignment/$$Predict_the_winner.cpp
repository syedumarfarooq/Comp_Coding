https://leetcode.com/problems/predict-the-winner/
// You are given an integer array nums. Two players are playing a game with this array: player 1 and player 2.

// Player 1 and player 2 take turns, with player 1 starting first. Both players start the game with a score of 0. At each turn, the player takes one of the numbers from either end of the array (i.e., nums[0] or nums[nums.length - 1]) which reduces the size of the array by 1. The player adds the chosen number to their score. The game ends when there are no more elements in the array.

// Return true if Player 1 can win the game. If the scores of both players are equal, then player 1 is still the winner, and you should also return true. You may assume that both players are playing optimally.
// Example 1:

// Input: nums = [1,5,2]
// Output: false
// Explanation: Initially, player 1 can choose between 1 and 2. 
// If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2). 
// So, final score of player 1 is 1 + 2 = 3, and player 2 is 5. 
// Hence, player 1 will never be the winner and you need to return false.
*//logic
  // in this we are calculating the difference of score of p1 and p2 if it is greater than or equal to 0 then return true 
*//solve using recursion
  class Solution {
public:
    int solve(vector<int>& nums,int start,int end){
        if(start==end)return nums[start];//if we reach the last element we return that number
        //diff=P1-P2
        int diffByStart=nums[start]-solve(nums,start+1,end);//the p1 is adding the start element and then p2 element is left to recursion
      //that will give score of p2 with further score deducted from it with the p1 
        int diffByEnd=nums[end]-solve(nums,start,end-1);
        return max(diffByStart,diffByEnd);
    }
    bool predictTheWinner(vector<int>& nums) {
        return solve(nums,0,nums.size()-1)>=0;
    }
};
*//solve using memoisation
class Solution {
public:
    int solveMem(vector<int>& nums,int start,int end,vector<vector<int>>&dp){
        if(start==end)return nums[start];
        if(dp[start][end]!=-1){
            return dp[start][end];
        }
        //diff=P1-P2
        int diffByStart=nums[start]-solveMem(nums,start+1,end,dp);
        int diffByEnd=nums[end]-solveMem(nums,start,end-1,dp);
        dp[start][end]=max(diffByStart,diffByEnd);
        return dp[start][end];
    }
    bool predictTheWinner(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
        return solveMem(nums,0,nums.size()-1,dp)>=0;
    }
};
*//solve using tabulation
