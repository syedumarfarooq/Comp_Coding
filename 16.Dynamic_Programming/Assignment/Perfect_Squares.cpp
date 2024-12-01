https://leetcode.com/problems/perfect-squares/
// Given an integer n, return the least number of perfect square numbers that sum to n.

// A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.
// Example 1:

// Input: n = 12
// Output: 3
// Explanation: 12 = 4 + 4 + 4.
// Example 2:

// Input: n = 13
// Output: 2
// Explanation: 13 = 4 + 9.
*//Using recursion
class Solution {
public:
    int numSquareHelper(int n){
        if(n==0){
            return 0;
        }
        if(n<0){
            return 10000;//returning a large number indicating a invalid path and highest n can go is 10000
        }
        int i=1;
        int ans=INT_MAX;
        int end=sqrt(n);
        while(i<=end){
            int perfectsquare=i*i;
            int numberofPerfectSquare=1+numSquareHelper(n-perfectsquare);//as it has to count every numsquare that is used to make n we add 1 in every step to count number of perfectsquare added to make n 
            if(numberofPerfectSquare<ans){
                ans=numberofPerfectSquare;
            }
            i++;
            
        }
        return ans;
    }
    int numSquares(int n) {
        return numSquareHelper(n);
    }
};
*//Using mem
class Solution {
public:
    int numSquareMem(int n,vector<int>&dp){
        if(n==0){
            return 0;
        }
        if(n<0){
            return 10000;//returning a large number indicating a invalid path and highest n can go is 10000
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int i=1;
        int ans=INT_MAX;
        int end=sqrt(n);
        while(i<=end){
            int perfectsquare=i*i;
            int numberofPerfectSquare=1+numSquareMem(n-perfectsquare,dp);//as it has to count every numsquare that is used to make n we add 1 in every step to count number of perfectsquare added to make n 
            if(numberofPerfectSquare<ans){
                ans=numberofPerfectSquare;
            }
            i++;
            
        }
        dp[n]=ans;
        return dp[n];
    }
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return numSquareMem(n,dp);
    }
};
*//using tabulation 
class Solution {
public:
    int numSquareTab(int n){//O(n*√n)=>O(n)
        vector<int> dp(n+1,0);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            int start=1;
            int ans=INT_MAX;
            int end=sqrt(i);
            while(start<=end){
                int perfectsquare=start*start;
                int numberofPerfectSquare=1+dp[i-perfectsquare];
                if(numberofPerfectSquare<ans){
                    ans=numberofPerfectSquare;
                }
                start++;
                
            }
            dp[i]=ans;
        }
        
        
        return dp[n];
    }
    int numSquares(int n) {
        
        return numSquareTab(n);
    }
};
