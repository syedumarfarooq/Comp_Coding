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
class Solution {
public:
    int solveTab(vector<int>& nums){
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),0));
        for(int i=0;i<nums.size();i++){
            dp[i][i]=nums[i];
        }
        int i=nums.size();
        for(int start=nums.size()-1;start>=0;start--){
            for(int end=i;end<nums.size();end++){
                 int diffByStart=nums[start]-dp[start+1][end];
                 int diffByEnd=nums[end]-dp[start][end-1];
                 dp[start][end]=max(diffByStart,diffByEnd);
            }
            --i;
        }
        
       
        
        return dp[0][nums.size()-1];
    }
    bool predictTheWinner(vector<int>& nums) {
        
        return solveTab(nums)>=0;
    }
};
*//as for finding the max score difference  of either of player if the difference comes positive then the player 1 has won if not player 2 
// as diff=p1 -p2 if p1 is greater the difference will be > 0 
*//for negativeon the starting and ending index we need [row+1][col] and [row][col+1] so if we start col from 0 then we have to access col
*//-1 which gives error and row we start from i=nums.size() for end=i then we decrease one after every for loop 
eg:[1,5,2]
0,0|0,1|0,2
------------
1,0|1,1|1,2
------------
2,0|2,1|2,2
*//based on my understanding as in top down we start from 0-n in this we start from n-0 
*//we have answers placed in all the diagonal places with thier respective nums[i] as base condition
  *//and we know for any index we have to have previous column in same row and new row same column
  *//so we have to start from 0,2 so that we can iterate and get answers
  *//we are taking i as nums.size() rather than nums.size()-1 because of start as in the last row we dont need to find anything
  *//as we are keeping start as nums.size()-1 for easily starting the top down process 
  *//if we keep end =i as nums.size and end<nums.size() it wont run for the last row so it will simply skip the i is decremented
  *//for next row in the start is nums.size()-2 the end=i comes to nums.size()-1 then we find max difference for that index
  *//and continue until we find the answer which is present in the 0th row and last index 
  *//as we are going from bottom to top and end kinda 0 to end so it will be in the end
*//eg:for 1,2 we need 1,1 and 2,2 as they are base case they will contain max difference in them
  *//then we find 0,1 with help of 0,0 and 1,1 the 0,2 with the help of 0,1 and 1,2 so this is how this works
  
