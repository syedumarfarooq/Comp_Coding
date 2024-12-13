https://leetcode.com/problems/distinct-subsequences/
// Given two strings s and t, return the number of distinct subsequences of s which equals t.

// The test cases are generated so that the answer fits on a 32-bit signed integer.
// Example 1:

// Input: s = "rabbbit", t = "rabbit"
// Output: 3
// Explanation:
// As shown below, there are 3 ways you can generate "rabbit" from s.
// rabbbit
// rabbbit
// rabbbit
*//logic 
  // in this we iterate i and j if the characters match we move forward and also check by increasing only i'th index to check if this can make
  // a possible solution 
// eg:s="bbag" t="bag" in this first i is on 0 it matches and goes forward and then me move only i then again it maches with b this also
// make another solution so that is why we are checking both
*//solved using recursion
  class Solution {
public:
    int solve(string&s,string&t,int i,int j){
        if(j==t.size())return 1;//j is only moved when s[i]==t[j] so if it in the end then all character of t are matched return 1
      
      //the order is also important for both the base case if we found a solution it will directly return 1 if not then 0
        if(i==s.size())return 0;//if i reaches the end it means all elements are not matched and j has some elements left
        int ans=0;
        if(s[i]==t[j]){
            ans+=solve(s,t,i+1,j+1);
        }
        ans+=solve(s,t,i+1,j);
        return ans;
    }
    int numDistinct(string s, string t) {
        return solve(s,t,0,0);
    }
};
*//solved using memoisation
class Solution {
public:
    int solveMem(string&s,string&t,int i,int j,vector<vector<int>> &dp){
        if(j==t.size())return 1;
        if(i==s.size())return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(s[i]==t[j]){
            ans+=solveMem(s,t,i+1,j+1,dp);
        }
        ans+=solveMem(s,t,i+1,j,dp);
        dp[i][j]=ans;
        return dp[i][j];
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,-1));//from ith index of s and jth index of t how many subsequences of s are 
      //equal to t
        return solveMem(s,t,0,0,dp);
    }
};
*//solved using tabulation
class Solution {
public:
    int solveTab(string&s,string&t){
        vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,0));
        // if(j==t.size())return 1;
        // if(i==s.size())return 0;
        for(int i=0;i<=s.size();i++){//<= bcz if the i and j both end then it is a solution
            dp[i][t.size()]=1;
        }
        for(int i=s.size()-1;i>=0;i--){
            for(int j=t.size()-1;j>=0;j--){
                long long ans=0;//using long long bcz in one case the answer goes out of bound that is out of 32bit
              //but u may get doubt but the dp[i][j] is int how is it able to store value more than 32 bit without any problem
              //so what it is doing is while storing into the dp[][] it in being convereted into int size that is it is trucating itself
              // In C++, truncate generally refers to reducing or limiting a value by cutting off extra data, such as decimal places or 
              // characters. This can apply to numbers, strings, or file operations.
                if(s[i]==t[j]){
                    ans+=dp[i+1][j+1];
                }
                ans+=dp[i+1][j];
                dp[i][j]=ans;
            }
        }
        
        return dp[0][0];
    }
    int numDistinct(string s, string t) {
        
        return solveTab(s,t);
    }
};
