https://leetcode.com/problems/reducing-dishes/
// A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.
// Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].
// Return the maximum sum of like-time coefficient that the chef can obtain after preparing some amount of dishes.
// Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.
// Example 1:

// Input: satisfaction = [-1,-8,0,5,-9]
// Output: 14
// Explanation: After Removing the second and last dish, the maximum total like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14).
// Each dish is prepared in one unit of time.
*//logic
  // in this we are following include exclude pattern where we check once by including then excludeing and return the maximum
//if we include we multiply the time with current satisfaction and let the rest taken care by the recursion
//we sort the satisfaction because if the end satisfaction is highest then the time also will be highest at the endas the time taken to cook 
  // that dish is the time taken by all the dishes previously +current so if we multiply the highest number with the most time taken dish we 
  // will get maximum value we can sort only because as the question says in any order and we can remove any number of dishes but we have to 
  //get the maximum lifeTimeCoeff possible
*//solved using recursion
  class Solution {
public:
    int solve(vector<int>& satisfaction,int i,int time){
        if(i==satisfaction.size())return 0;
        int includeLikeTimeCoeff=time*satisfaction[i]+solve(satisfaction,i+1,time+1);
        int excludeLikeTimeCoeff=solve(satisfaction,i+1,time);//not incrementing time as the current dish is exclude 
        return max(includeLikeTimeCoeff,excludeLikeTimeCoeff);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        return solve(satisfaction,0,1);
    }
};
*//solved using memoisation
class Solution {
public:
    int solveMem(vector<int>& satisfaction,int i,int time,vector<vector<int>>&dp){
        if(i==satisfaction.size())return 0;
        if(dp[i][time] !=-1){
            return dp[i][time] ;
        }
        int includeLikeTimeCoeff=time*satisfaction[i]+solveMem(satisfaction,i+1,time+1,dp);
        int excludeLikeTimeCoeff=solveMem(satisfaction,i+1,time,dp);
        dp[i][time] = max(includeLikeTimeCoeff,excludeLikeTimeCoeff);
        return dp[i][time];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        vector<vector<int>>dp(satisfaction.size(),vector<int>(satisfaction.size()+1,-1));//for ith dish and time what is the maximum liketime coeff
      //time will start at 1 for the first index and can go upto the size of satisfaction that is y we use +1
        return solveMem(satisfaction,0,1,dp);
    }
};
*//solved using tabulation
class Solution {
public:
    int solveTab(vector<int>& satisfaction){
        vector<vector<int>>dp(satisfaction.size()+1,vector<int>(satisfaction.size()+2,0));
        for(int i=satisfaction.size()-1;i>=0;i--){
            for(int time=satisfaction.size();time>=1;time--){
                int includeLikeTimeCoeff=time*satisfaction[i]+dp[i+1][time+1];
                int excludeLikeTimeCoeff=dp[i+1][time];
                dp[i][time] = max(includeLikeTimeCoeff,excludeLikeTimeCoeff);
            }
        }
        
        return dp[0][1];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        
        return solveTab(satisfaction);
    }
};
