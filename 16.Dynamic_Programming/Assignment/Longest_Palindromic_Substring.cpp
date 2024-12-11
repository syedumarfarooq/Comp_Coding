https://leetcode.com/problems/longest-palindromic-substring/
// Given a string s, return the longest 
// palindromic
 
// substring
//  in s.

 

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.
// Example 2:

// Input: s = "cbbd"
// Output: "bb"
*//logic
  // we are making all the combination of substring using two for loops and using solve we are checking if it palindrome if it is palindrome
// then we check if it length is maximum if yes we store the start point in start and len of it in maxlen so that it can be later used to 
  //return ans
*//solve using recursion
  class Solution {
public:
    int start=0,maxlen=1;
    bool solve(string s,int i,int j){
        if(i>=j){
            return true;
        }
        bool flag=false;
        if(s[i]==s[j]){
            flag=solve(s,i+1,j-1);
        }
        if(flag){
            int currlen=j-i+1;
            if(currlen>maxlen){
                maxlen=currlen;
                start=i;
            }
        }
        return flag;
    }
    string longestPalindrome(string s) {
        for(int i=0;i<s.size();i++){
            for(int j=0;j<s.size();j++){
                bool flag=solve(s,i,j);
            }
        }
        return s.substr(start,maxlen);
    }
};
*//solved using memoisation
class Solution {
public:
    int start=0,maxlen=1;
    bool solve(string s,int i,int j,vector<vector<int>>&dp){
        if(i>=j){
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        bool flag=false;
        if(s[i]==s[j]){
            flag=solve(s,i+1,j-1,dp);
        }
        if(flag){
            int currlen=j-i+1;
            if(currlen>maxlen){
                maxlen=currlen;
                start=i;
            }
        }
        dp[i][j]=flag;
        return dp[i][j];
    }
    string longestPalindrome(string s) {
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),-1));//this stores if the substring from i to j is palindrome
        for(int i=0;i<s.size();i++){
            for(int j=0;j<s.size();j++){
                bool flag=solve(s,i,j,dp);
            }
        }
        return s.substr(start,maxlen);
    }
};
