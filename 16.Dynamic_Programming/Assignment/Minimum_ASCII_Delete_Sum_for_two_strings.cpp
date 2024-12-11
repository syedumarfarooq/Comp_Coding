https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/
// Given two strings s1 and s2, return the lowest ASCII sum of deleted characters to make two strings equal.

 

// Example 1:

// Input: s1 = "sea", s2 = "eat"
// Output: 231
// Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
// Deleting "t" from "eat" adds 116 to the sum.
// At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
*//logic
  // we are iterating through every character if they both are same we are not adding the cose that is their ascii values if not we check 
// by deleting starting character of s1 and s2 and adding thier cost and let the rest for recursion which ever is minimum we return 
// if one string becomes empty then we delete the rest of elements in the other string to make it equal and add their cost
*//solved using recursion
  class Solution {
public:
    int solve(string s1,string s2,int i,int j){
        int cost=0;
      //return the sum of ASCII of remaining char of remaining string
        if(i==s1.size()||j==s2.size()){
            for(int x=i;x<s1.size();x++){
                cost+=s1[x];
            }
            for(int x=j;x<s2.size();x++){
                cost+=s2[x];
            }
            return cost;
        }
        if(s1[i]==s2[j]){
            cost=solve(s1,s2,i+1,j+1);
        }else{
            int cost1=s1[i]+solve(s1,s2,i+1,j);
            int cost2=s2[j]+solve(s1,s2,i,j+1);
            cost=min(cost1,cost2);
        }
        return cost;
    }
    int minimumDeleteSum(string s1, string s2) {
        return solve(s1,s2,0,0);
    }
};
*//solved using memoisation
class Solution {
public:
    int solveMem(string&s1,string&s2,int i,int j,vector<vector<int>>&dp){
        int cost=0;
        if(i==s1.size()||j==s2.size()){
            for(int x=i;x<s1.size();x++){
                cost+=s1[x];
            }
            for(int x=j;x<s2.size();x++){
                cost+=s2[x];
            }
            return cost;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s1[i]==s2[j]){
            cost=solveMem(s1,s2,i+1,j+1,dp);
        }else{
            int cost1=s1[i]+solveMem(s1,s2,i+1,j,dp);
            int cost2=s2[j]+solveMem(s1,s2,i,j+1,dp);
            cost=min(cost1,cost2);
        }
        return dp[i][j]=cost;
    }
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        return solveMem(s1,s2,0,0,dp);
    }
};
*//solved using tabulation
class Solution {
public:
    int solveMem(string&s1,string&s2){
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,0));//from ith index in s1 and jth index in
        //s2 what is the minimum cost needed to make them both equal
        //base case
        //s2 is at the end so we are removing all the elements in s1 by adding their cost
        //if s2 is at end then i can be between 0 to s1.size() if i is at 0 then we have to add cost of all the element from 0 to end
        //if i is at 1 we count that then the rest until end
        for(int i=s1.size()-1;i>=0;i--){
            dp[i][s2.size()]=s1[i]+dp[i+1][s2.size()];//counting the ith and taking the rest from dp[i+1][s2.size()]    
        }
        //s1 is at the end so we are removing all the elements in s2
        for(int i=s2.size()-1;i>=0;i--){
            dp[s1.size()][i]=s2[i]+dp[s1.size()][i+1];       
        }
        for(int i=s1.size()-1;i>=0;i--){
            for(int j=s2.size()-1;j>=0;j--){
                int cost=0;
                if(s1[i]==s2[j]){
                    cost=dp[i+1][j+1];
                }else{
                    int cost1=s1[i]+dp[i+1][j];
                    int cost2=s2[j]+dp[i][j+1];
                    cost=min(cost1,cost2);
                }
                dp[i][j]=cost;
            }
            
        }
        
        return dp[0][0];
    }
    int minimumDeleteSum(string s1, string s2) {
        
        return solveMem(s1,s2);
    }
};
