https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
// Given a string s. In one step you can insert any character at any index of the string.
// Return the minimum number of steps to make s palindrome.
// A Palindrome String is one that reads the same backward as well as forward.
// Example 1:

// Input: s = "zzazz"
// Output: 0
// Explanation: The string "zzazz" is already palindrome we do not need any insertions.
*//good word u wrote the solution all by urself without any help ,good, be deligent
*//logic
//   in this i am taking two pointer start and end and move both it they are same if not i add a element in the start and check and add a 
// element in the end and check and the minimum is returned 
//if i add element in the start then i count one and won't move the pointer of start as i have already added an extra character 
// matching to the so the start stays there only the end is dicremented
// if i add element in the end then i count one character and wont move the pointer of the end as i have already added an extra character 
// match the start so the start is increment and end stays there
//both of this give a answer that how many elements are needed to be added to make it a palindrome we will return the minimum
*//solved using recursion my solution 
  class Solution {
public:
    int solve(string s,int start,int end){
        if(start>end)return 0;
        int ans=0;
        if(s[start]==s[end]){
            ans=solve(s,start+1,end-1);
        }else{
            int addingElementInStart=1+solve(s,start,end-1);
            int addingElementInEnd=1+solve(s,start+1,end);
            ans=min(addingElementInStart,addingElementInEnd);
        }
        return ans;
    }
    int minInsertions(string s) {
        return solve(s,0,s.size()-1);
    }
};
*//solved using memoisation MY SOLUTION
class Solution {
public:
    int solveMem(string&s,int start,int end,vector<vector<int>>&dp){
        if(start>end)return 0;
        int ans=0;
        if(dp[start][end]!=-1){
            return dp[start][end];
        }
        if(s[start]==s[end]){
            ans=solveMem(s,start+1,end-1,dp);
        }else{
            int left=1+solveMem(s,start,end-1,dp);
            int right=1+solveMem(s,start+1,end,dp);
            ans=min(left,right);
        }
        dp[start][end]=ans;
        return dp[start][end];
    }
    int minInsertions(string s) {
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),-1));
        return solveMem(s,0,s.size()-1,dp);
    }
};
*//solved using Tabulation MY SOLUTION
class Solution {
public:
    int solveTab(string&s){
        vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,0));
        int ans=0;
        int i=s.size();
        for(int start=s.size()-1;start>=0;start--){//copying the pattern of Predict the winner
          // https://github.com/syedumarfarooq/Comp_Coding/blob/main/16.Dynamic_Programming/Assignment/%24%24Predict_the_winner.cpp
          //as the value of start,end depend on [start][end-1] and [start+1][end] similar to predict the winner question
            for(int end=i;end<s.size();end++){
                if(s[start]==s[end]){
                    ans=dp[start+1][end-1];
                }else{
                    int left=1+dp[start][end-1];
                    int right=1+dp[start+1][end];
                    ans=min(left,right);
                }
                dp[start][end]=ans;
            }
            --i;
        }
        
        
        return dp[0][s.size()-1];
    }
    int minInsertions(string s) {
        
        return solveTab(s);
    }
};
