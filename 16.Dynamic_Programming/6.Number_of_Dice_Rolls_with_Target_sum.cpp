https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
// You have n dice, and each dice has k faces numbered from 1 to k.
// Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll the dice, so the sum of the face-up numbers equals target. Since the answer may be too large, return it modulo 109 + 7.
// Example 1
// Input: n = 1, k = 6, target = 3
// Output: 1
// Explanation: You throw one die with 6 faces.
// There is only one way to get a sum of 3.
// Example 2:

// Input: n = 2, k = 6, target = 7
// Output: 6
// Explanation: You throw two dice, each with 6 faces.
// There are 6 ways to get a sum of 7: 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.
*//Solved Using recursion TLE
// class Solution {
// public:
//     int solveUsingRecursion(int n,int k,int target){
//         if(n<=0){
//             return 0;
//         }
//         if(n==0&&target==0){
//             return 1;
//         }if(n==0&&target!=0){
//             return 0;
//         }if(n!=0&&target==0){
//             return 0;
//         }
//         int ans=0;
//         for(int i=1;i<=k;i++){
//             ans+=solveUsingRecursion(n-1,k,target-i);
//         }
//         return ans;
//     }
//     int numRollsToTarget(int n, int k, int target) {
//         return solveUsingRecursion(n,k,target);
//     }
// };
*//Solved Using Memoisation
//   class Solution {
// public:
//     long long int MOD=1000000007;
//     int solveUsingMem(int n,int k,int target,vector<vector<int>>&dp){
//         if(n<0){
//             return 0;
//         }
//         if(n==0&&target==0){
//             return 1;
//         }if(n==0&&target!=0){
//             return 0;
//         }if(n!=0&&target==0){
//             return 0;
//         }
//         if(dp[n][target]!=-1){
//             return dp[n][target];
//         }
//         int ans=0;
//         for(int i=1;i<=k;i++){
//             if(target-i>=0)
//                 ans=(ans%MOD+solveUsingMem(n-1,k,target-i,dp)%MOD)%MOD;
//         }
//        dp[n][target]=ans;
//        return dp[n][target];
//     }
//     int numRollsToTarget(int n, int k, int target) {
//         vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
//         dp[0][0]=1;

//         int ans= solveUsingMem(n,k,target,dp);
//         for(int i=0;i<=n;i++){
//             for(int j=0;j<=target;j++){
//                 cout<<dp[i][j]<<" ";
//             }
//             cout<<endl;
//         }
//         return ans;
//     }
// };
  *//Solved using tabulation
//   class Solution {
// public:
// long long int MOD = 1000000007;
//     int solveUsingTabulation(int n, int k, int target) {
//         vector<vector< long long int> > dp(n+1, vector< long long int>(target+1, 0));
//         dp[0][0] = 1;

//         for(int index = 1; index <=n; index++) {
//             for(int t=1; t<=target; t++) {

//                 long long int ans = 0;
//                 for(int i=1; i<=k; i++) {
//                     long long int recAns = 0;
//                     if(t - i >= 0 )
//                         recAns = dp[index-1][t-i];
//                     ans = (ans % MOD + recAns % MOD) % MOD;
//                 }
//                 dp[index][t] =  ans;
//             }
//         }

//     return dp[n][target];

//     }
//     int numRollsToTarget(int n, int k, int target) {
//         int ans=solveUsingTabulation(n,k,target);
//         return ans;
//     }
// };
  *//Space optimization
   int solveUsingTabulationSO(int n, int k, int target) {

        vector<int> prev(target+1, 0);
        vector<int> curr(target+1, 0);

        prev[0] = 1;

        for(int index = 1; index <=n; index++) {
            for(int t=1; t<=target; t++) {

                long long int ans = 0;
                for(int i=1; i<=k; i++) {
                    long long int recAns = 0;
                    if(t - i >= 0 )
                        recAns = prev[t-i];
                    ans = (ans % MOD + recAns % MOD) % MOD;
                }
                curr[t] =  ans;
            }
            //shift
            prev = curr;
        }

    return prev[target];

    }
