https://leetcode.com/problems/stone-game/
// Alice and Bob play a game with piles of stones. There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].
// The objective of the game is to end with the most stones. The total number of stones across all the piles is odd, so there are no ties.
// Alice and Bob take turns, with Alice starting first. Each turn, a player takes the entire pile of stones either from the beginning or rom the end of the row. This continues until there are no more piles left, at which point the person with the most stones wins.
// Assuming Alice and Bob play optimally, return true if Alice wins the game, or false if Bob wins.
// Example 1:

// Input: piles = [5,3,4,5]
// Output: true
// Explanation: 
// Alice starts first, and can only take the first 5 or the last 5.
// Say she takes the first 5, so that the row becomes [3, 4, 5].
// If Bob takes 3, then the board is [4, 5], and Alice takes 5 to win with 10 points.
// If Bob takes the last 5, then the board is [3, 4], and Alice takes 4 to win with 9 points.
// This demonstrated that taking the first 5 was a winning move for Alice, so we return true.
*//logic
//   1.no tie as ther are total number of stones are odd
//   2.alice starts first
//   3.there will be atleast one way by which alice will win irrespective of what ever she chooses
// 4.and the question say they play optimaly so they choose bigger numbers
//for every test case there is a possible way alice will win so return true 
  *//try solving this once
*//solved
  class Solution {
public:
    bool stoneGame(vector<int>& piles) {
      //there will be at least one way by which alice will win.
      //that means, we should return true;
      //bcz problem is asking is there any way that Alice can win
        return true;
    }
};
