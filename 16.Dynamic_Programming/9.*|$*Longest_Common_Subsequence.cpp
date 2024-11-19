https://leetcode.com/problems/longest-common-subsequence/
// Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

// For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a subsequence that is common to both strings.

 

// Example 1:

// Input: text1 = "abcde", text2 = "ace" 
// Output: 3  
// Explanation: The longest common subsequence is "ace" and its length is 3.
*//Logic
  // we are using two pointer approach where i and j are pointer pointing text1 and text2 if the i and j match we move both of them to the next
// char and add one to count the common subsequence if not we excluding the character from the either of the text and find the maximum
  *//Solve using recursion
  class Solution {
public:
int solveUsingRecursion(string a, string b, int i, int j) {
        if(i == a.length()) {
            return 0;
        }
        if(j == b.length()) 
            return 0;

        int ans = 0;
        if(a[i] == b[j])//if the character matches add 1 to the answer and check for next
            ans =  1 + solveUsingRecursion(a,b, i+1, j+1);
        else {//if not matching then exclude a character from text 1 and check maximum common subsequence of exclude a charcter from text2
            ans =  0 + max(solveUsingRecursion(a,b,i,j+1),solveUsingRecursion(a,b,i+1,j));
        }
        return ans;

    } 
    int longestCommonSubsequence(string text1, string text2) {
        return solveUsingRecursion(text1,text2,0,0);
    }
};
*//Solved using memoisation
*//There was one case where it was giving TLE in this method then we passed the text1 and text2 by reference then it worked fine
class Solution {
public:
int solveUsingMem(string&a, string&b, int i, int j,vector<vector<int>>&dp) {
        if(i == a.length()) {
            return 0;
        }
        if(j == b.length()) 
            return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans = 0;
        if(a[i] == b[j])
            ans =  1 + solveUsingMem(a,b, i+1, j+1,dp);
        else {
            ans =  0 + max(solveUsingMem(a,b,i,j+1,dp),solveUsingMem(a,b,i+1,j,dp));
        }
        dp[i][j]= ans;
        return dp[i][j];
    } 
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.length(),vector<int>(text2.length(),-1));
        return solveUsingMem(text1,text2,0,0,dp);

    }
};
