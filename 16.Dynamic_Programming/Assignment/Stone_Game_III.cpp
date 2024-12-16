https://leetcode.com/problems/stone-game-iii/
// Alice and Bob continue their games with piles of stones. There are several stones arranged in a row, and each stone has an associated value which is an integer given in the array stoneValue.
// Alice and Bob take turns, with Alice starting first. On each player's turn, that player can take 1, 2, or 3 stones from the first remaining stones in the row.
// The score of each player is the sum of the values of the stones taken. The score of each player is 0 initially.
// The objective of the game is to end with the highest score, and the winner is the player with the highest score and there could be a tie. The game continues until all the stones have been taken.
// Assume Alice and Bob play optimally.
// Return "Alice" if Alice will win, "Bob" if Bob will win, or "Tie" if they will end the game with the same score.
// Example 1:
// Input: stoneValue = [1,2,3,7]
// Output: "Bob"
// Explanation: Alice will always lose. Her best move will be to take three piles and the score become 6. Now the score of Bob is 7 and Bob wins.
*//logic
  // we are taking 1,2 and 3 piles and checking which will give the maximum answer for each player first alice total is subtracted with bob
// through recursion in bob's(turn2) function it will add the pilse 1,2or3 and - alice(turn3) piles and return the ans which will then be 
// subtracted by alice(turn 1)
  //basically the recursion is giving the maximum of bob's(alice,bob,alice,bob until it end) in first iteration which is subtracted from 
  // alice if alice points are more she wins 
*//solved using recursion
class Solution {
public:
    int solve(vector<int>& stoneValue,int i){
        if(i==stoneValue.size())return 0;
        int ans=INT_MIN;
        int total=0;
        for(int X=1;X<=3;X++){
            if(i+X-1>=stoneValue.size())break;//checking if x goes out of bound
            total+=stoneValue[i+X-1];
            ans=max(ans,total-solve(stoneValue,i+X));
        }
        return ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int ans=solve(stoneValue,0);
        if(ans<0)return "Bob";
        if(ans>0)return "Alice";
        return "Tie";
    }
};
*//solved using memoisation
class Solution {
public:
    int solve(vector<int>& stoneValue,int i,vector<int>&dp){
        if(i==stoneValue.size())return 0;
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=INT_MIN;
        int total=0;
        for(int X=1;X<=3;X++){
            if(i+X-1>=stoneValue.size())break;
            total+=stoneValue[i+X-1];
            ans=max(ans,total-solve(stoneValue,i+X,dp));
        }
        dp[i]=ans;
        return dp[i];
    }
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int>dp(stoneValue.size()+1,-1);
        int ans=solve(stoneValue,0,dp);
        if(ans<0)return "Bob";
        if(ans>0)return "Alice";
        return "Tie";
    }
};
*//solved using tabulation
class Solution {
public:
    int solve(vector<int>& stoneValue){
        vector<int>dp(stoneValue.size()+1,0);
        for(int i=stoneValue.size()-1;i>=0;i--){
            int ans=INT_MIN;
            int total=0;
            for(int X=1;X<=3;X++){
                if(i+X-1>=stoneValue.size())break;
                total+=stoneValue[i+X-1];
                ans=max(ans,total-dp[i+X]);
            }
            dp[i]=ans;
        }
        
        return dp[0];
    }
    string stoneGameIII(vector<int>& stoneValue) {
        
        int ans=solve(stoneValue);
        if(ans<0)return "Bob";
        if(ans>0)return "Alice";
        return "Tie";
    }
};
