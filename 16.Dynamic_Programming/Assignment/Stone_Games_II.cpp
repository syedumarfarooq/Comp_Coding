https://leetcode.com/problems/stone-game-ii/
// Alice and Bob continue their games with piles of stones. There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i]. The objective of the game is to end with the most stones.
// Alice and Bob take turns, with Alice starting first.
// On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M. Then, we set M = max(M, X). Initially, M = 1.
// The game continues until all the stones have been taken.
// Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.
// Example 1:
// Input: piles = [2,7,9,4,4]
// Output: 10
// Explanation:
// If Alice takes one pile at the beginning, Bob takes two piles, then Alice takes 2 piles again. Alice can get 2 + 4 + 4 = 10 stones in total.
// If Alice takes two piles at the beginning, then Bob can take all three piles left. In this case, Alice get 2 + 7 = 9 stones in total.
// So we return 10 since it's larger.
*//logic
  // so in this alice takes the maximum it can from all the possibilities and bob have to choose maximum so that alice next piles sum should be 
// returned MINIMUM as bob returns alices points based on how many it chose so bob chooses in a way that alice will get minimum 
  //this is how they stay optimal
*//solved using recursion
  class Solution {
public:
    int solve(vector<int>& piles,int i,int M,int alice){
        if(i==piles.size())return 0;
        int ans=alice?INT_MIN:INT_MAX;
        int total=0;
        for(int X=1;X<=2*M;X++){
            if(i+X-1>=piles.size())break;
            total+=piles[i+X-1];
            if(alice){
                ans=max(ans,total+solve(piles,i+X,max(X,M),!alice));
            }else{
                ans=min(ans,solve(piles,i+X,max(X,M),!alice));
            }
        }
        return ans;
    }
    int stoneGameII(vector<int>& piles) {
        return solve(piles,0,1,true);
    }
};
*//solved using memoisation
class Solution {
public:
    int solveMem(vector<int>& piles,int i,int M,int alice,vector<vector<vector<int>>>&dp){
        if(i==piles.size())return 0;
        if(dp[i][M][alice]!=-1){
            return dp[i][M][alice];
        }
        int ans=alice?INT_MIN:INT_MAX;
        int total=0;
        for(int X=1;X<=2*M;X++){
            if(i+X-1>=piles.size())break;
            total+=piles[i+X-1];
            if(alice){
                ans=max(ans,total+solveMem(piles,i+X,max(X,M),!alice,dp));
            }else{
                ans=min(ans,solveMem(piles,i+X,max(X,M),!alice,dp));
            }
        }
        dp[i][M][alice]= ans;
        return dp[i][M][alice];
    }
    int stoneGameII(vector<int>& piles) {
        vector<vector<vector<int>>>dp(piles.size()+1,vector<vector<int>>(piles.size()+1,vector<int>(2,-1)));
        //m can be one initial or  can go upto the array size not more than that
      //whatever the size of M may be but it can only consume the whole array 
        return solveMem(piles,0,1,true,dp);
    }
};
*//solved using tabulation
 class Solution {
public:
    int solveTab(vector<int>& piles){
        vector<vector<vector<int>>>dp(piles.size()+1,vector<vector<int>>(piles.size()+1,vector<int>(2,0)));
        for(int i=piles.size()-1;i>=0;i--){
            for(int M=piles.size();M>=1;M--){//-2 bcz for piles=[1] =>expected output =1 but we use -1 gives error
                for(int alice=0;alice<2;alice++){
                    int ans=alice?INT_MIN:INT_MAX;
                    int total=0;
                    for(int X=1;X<=2*M;X++){
                        if(i+X-1>=piles.size())break;
                        total+=piles[i+X-1];
                        if(alice){
                            ans=max(ans,total+dp[i+X][max(X,M)][!alice]);
                        }else{
                            ans=min(ans,dp[i+X][max(X,M)][!alice]);
                        }
                    }
                    dp[i][M][alice]= ans;
                }
            }
        }
        
        return dp[0][1][1];
    }
    int stoneGameII(vector<int>& piles) {
        return solveTab(piles);
    }
};
