https://leetcode.com/problems/ones-and-zeroes/
// You are given an array of binary strings strs and two integers m and n.

// Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.

// A set x is a subset of a set y if all elements of x are also elements of y.

 

// Example 1:

// Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
// Output: 4
// Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
// Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
// {"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.
*//logic
  we are first converting the string into pair of 0's and 1's so that it easier to solve then we only include if the current pair has suffient
number of zeros and ones to be included if yes we add and then we also check by excluding and return the maximum among them
*//solve using recursion
class Solution {
public:
    void convertStrsToNumStrs(vector<string>& strs,vector<pair<int,int>>&numStrs){
        for(auto str:strs){
            int zeros=0,ones=0;
            for(auto ch:str){
                if(ch=='0')++zeros;
                else ones++;
            }
            numStrs.push_back({zeros,ones});
        }
    }
    int solve(vector<pair<int,int>>&numStrs,int i,int m,int n){
        if(i==numStrs.size())return 0;
        int zeros=numStrs[i].first;
        int ones=numStrs[i].second;
        int include=0,exclude=0;
        if(m-zeros >=0 && n-ones >=0){//include only when they have enough number of zeors and ones i.e m n
            include=1+solve(numStrs,i+1,m-zeros,n-ones);
        }
        exclude=solve(numStrs,i+1,m,n);
        return max(include,exclude);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>>numStrs;//converting the vector string into vector int by just keeping the count of 0's and 1's 
      //{no of 0's, no of 1's}
        convertStrsToNumStrs(strs,numStrs);
        return solve(numStrs,0,m,n);
    }
};
*//solved using memoisation
  class Solution {
public:
    void convertStrsToNumStrs(vector<string>& strs,vector<pair<int,int>>&numStrs){
        for(auto str:strs){
            int zeros=0,ones=0;
            for(auto ch:str){
                if(ch=='0')++zeros;
                else ones++;
            }
            numStrs.push_back({zeros,ones});
        }
    }
    int solveMem(vector<pair<int,int>>&numStrs,int i,int m,int n,vector<vector<vector<int>>>&dp){
        if(i==numStrs.size())return 0;
        if(dp[i][m][n]!=-1){
            return dp[i][m][n];
        }
        int zeros=numStrs[i].first;
        int ones=numStrs[i].second;
        int include=0,exclude=0;
        if(m-zeros >=0 && n-ones >=0){
            include=1+solveMem(numStrs,i+1,m-zeros,n-ones,dp);
        }
        exclude=solveMem(numStrs,i+1,m,n,dp);
        dp[i][m][n]= max(include,exclude);
        return dp[i][m][n];
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>>numStrs;
        convertStrsToNumStrs(strs,numStrs);
        vector<vector<vector<int>>>dp(strs.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return solveMem(numStrs,0,m,n,dp);
    }
};
*//solved using tabulation
class Solution {
public:
    void convertStrsToNumStrs(vector<string>& strs,vector<pair<int,int>>&numStrs){
        for(auto str:strs){
            int zeros=0,ones=0;
            for(auto ch:str){
                if(ch=='0')++zeros;
                else ones++;
            }
            numStrs.push_back({zeros,ones});
        }
    }
    int solveTab(vector<pair<int,int>>&numStrs,int i,int m,int n){
        vector<vector<vector<int>>>dp(numStrs.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,0)));
     //here dp[i][m][n] tells for the value of m and n  the maximum subset of str that can be included up and until i i.e from end to i
        for(int i=numStrs.size()-1;i>=0;i--){
            for(int j=0;j<=m;j++){
                for(int k=0;k<=n;k++){
                    int zeros=numStrs[i].first;
                    int ones=numStrs[i].second;
                    int include=0,exclude=0;
                    if(j-zeros >=0 && k-ones >=0){
                        include=1+dp[i+1][j-zeros][k-ones];
                    }
                    exclude=dp[i+1][j][k];
                    dp[i][j][k]= max(include,exclude);
                }
            }
        }
        
        return dp[0][m][n];
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>>numStrs;
        convertStrsToNumStrs(strs,numStrs);
        
        return solveTab(numStrs,0,m,n);
    }
};
