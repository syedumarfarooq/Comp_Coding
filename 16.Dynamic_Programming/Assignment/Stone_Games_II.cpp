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
