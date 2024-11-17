https://leetcode.com/problems/guess-number-higher-or-lower-ii/
// We are playing the Guessing Game. The game will work as follows:

// I pick a number between 1 and n.
// You guess a number.
// If you guess the right number, you win the game.
// If you guess the wrong number, then I will tell you whether the number I picked is higher or lower, and you will continue guessing.
// Every time you guess a wrong number x, you will pay x dollars. If you run out of money, you lose the game.
// Given a particular n, return the minimum amount of money you need to guarantee a win regardless of what number I pick.

 

// Example 1:


// Input: n = 10
// Output: 16
// Explanation: The winning strategy is as follows:
// - The range is [1,10]. Guess 7.
//     - If this is my number, your total is $0. Otherwise, you pay $7.
//     - If my number is higher, the range is [8,10]. Guess 9.
//         - If this is my number, your total is $7. Otherwise, you pay $9.
//         - If my number is higher, it must be 10. Guess 10. Your total is $7 + $9 = $16.
//         - If my number is lower, it must be 8. Guess 8. Your total is $7 + $9 = $16.
//     - If my number is lower, the range is [1,6]. Guess 3.
//         - If this is my number, your total is $7. Otherwise, you pay $3.
//         - If my number is higher, the range is [4,6]. Guess 5.
//             - If this is my number, your total is $7 + $3 = $10. Otherwise, you pay $5.
//             - If my number is higher, it must be 6. Guess 6. Your total is $7 + $3 + $5 = $15.
//             - If my number is lower, it must be 4. Guess 4. Your total is $7 + $3 + $5 = $15.
//         - If my number is lower, the range is [1,2]. Guess 1.
//             - If this is my number, your total is $7 + $3 = $10. Otherwise, you pay $1.
//             - If my number is higher, it must be 2. Guess 2. Your total is $7 + $3 + $1 = $11.
// The worst case in all these scenarios is that you pay $16. Hence, you only need $16 to guarantee a win.
*//Logic
// we are choosing one number and then we are calculating the worst case that is maximum money needed for the game to win 
// we first choose one number then find the maximum money needed to reach every other number from 1-n then from that we choose the minimum
// out of all the possible answer and return it
// so after choosing ith number we find the maximum of 1 to i-1 and i+1to n
*//Solve using recursion
//   class Solution {
// public:

//     int solveUsingRecursion(int start,int end){
//         if(start>=end){
//             return 0;
//         }
//         int ans=INT_MAX;
//         for(int i=start;i<=end;i++){//for every number we are calculating the max amount that can be spent in that we are choosing minimum
//           // eg:n ranges from 1 to n for every number from 1 to n it will calculate the max amount that can be spent from that we choose minimum
//           //for every number money spent will be different  but we need to find the minimum
//           //as the question says quarentee a win as there can be n wins choosing n number with different amount we have to return minimum
//           // so for that we are calculating the max amount for all n and giving the minimum answer
//           // finding maximum number because with the maximum amount to win the game will let u win the game irrespective of choice u make next
//             ans=min(ans,i+max(solveUsingRecursion(start,i-1),solveUsingRecursion(i+1,end)));
//           //adding i because in worst case we are assuming the choosen number is wrong and adding it
//         }
//         return ans;
//     }
//     int getMoneyAmount(int n) {
//         int ans=solveUsingRecursion(1,n);
//         return ans;
//     }
// };
  *//Solve using memoisation
//   class Solution {
// public:
//     int solveUsingMem(int start,int end,vector<vector<int>>&dp){
//         if(start>=end){
//             return 0;
//         }
//         if(dp[start][end]!=-1){
//             return dp[start][end];
//         }
//         int ans=INT_MAX;
//         for(int i=start;i<=end;i++){
//              ans=min(ans,i+max(solveUsingMem(start,i-1,dp),solveUsingMem(i+1,end,dp)));
//         }
//         dp[start][end]=ans;
//         return dp[start][end];
//     }
//     int getMoneyAmount(int n) {
//         //in the start,end index of dp will give u the minimum among all the maximum amount spent from start to end
//         vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
//         int ans=solveUsingMem(1,n,dp);
//         return ans;
//     }
// };
  *//Solve using tabulation
  class Solution {
public:
    int solveUsingTab(int n) {
        //in the start,end index of dp  will give u the minimum among all the maximum amount spent from start to end
        vector<vector<int> > dp(n+2, vector<int>(n+2, 0));

        for(int start=n; start >= 1; start-- ) {
            for(int end = 1; end<=n; end++) {
                
                if(start>=end)
                    continue;
                else {
                    int ans = INT_MAX;
                    for(int i=start; i<=end; i++) {
                        ans = min(ans, i + max(dp[start][i-1],dp[i+1][end]));
                    }
                    dp[start][end] = ans;
                }
            }
        }
        return dp[1][n];

    }
    int getMoneyAmount(int n) {
        
        int ans=solveUsingTab(n);
        return ans;
    }
};
*//Cannot space optimize
// as we need values of all the rows and columns as i ranges from start to end 
