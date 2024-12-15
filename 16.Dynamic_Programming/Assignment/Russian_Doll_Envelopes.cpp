https://leetcode.com/problems/russian-doll-envelopes/
// You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.
// One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.
// Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).
// Note: You cannot rotate an envelope.
// Example 1:

// Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
// Output: 3
// Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
*//logic
  // we are sorting the envelopes then apply LIS so that we can find the maximum number of envelopes that can be stored in one another
*//solved using recursion
class Solution {
public:
    int solve(vector<vector<int>>& envelopes,int prev,int i){
        if(i==envelopes.size())return 0;
        int include=INT_MIN;
        if(prev==-1||envelopes[prev][0]<envelopes[i][0] && envelopes[prev][1]<envelopes[i][1]){
            include=1+solve(envelopes,i,i+1);
        }
        int exclude=solve(envelopes,prev,i+1);
        return max(include,exclude);
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end());
        return solve(envelopes,-1,0);
    }
};
*//solved using memoisation (MEMORY LIMIT EXCEEDED)
class Solution {
public:
    int solveMem(vector<vector<int>>& envelopes,int prev,int i,vector<vector<int>>&dp){
        if(i==envelopes.size())return 0;
        int include=INT_MIN;
        if(dp[prev+1][i]!=-1){
            return dp[prev+1][i];
        }
        if(prev==-1||envelopes[prev][0]<envelopes[i][0] && envelopes[prev][1]<envelopes[i][1]){
            include=1+solveMem(envelopes,i,i+1,dp);
        }
        int exclude=solveMem(envelopes,prev,i+1,dp);
        dp[prev+1][i]=max(include,exclude);//+1 because as prev is starting from -1 so we are starting it from 0 
        return dp[prev+1][i];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end());
        vector<vector<int>>dp(envelopes.size()+1,vector<int>(envelopes.size()+1,-1));
        return solveMem(envelopes,-1,0,dp);
    }
};
*//solve optimals //code of LIS//explained clearly in https://github.com/syedumarfarooq/Comp_Coding/edit/main/16.Dynamic_Programming/13.Russian_Doll_Envelopes.cpp
class Solution {
public:
    bool check(vector<int>& curr, vector<int>& prev) {
        if(prev[0] < curr[0] && prev[1]<curr[1] )
            return true;
        else
            return false;
    }
    int solveOptimal(vector<vector<int>>& arr) {
        if(arr.size() == 0)
            return 0;
        vector<vector<int>> ans;
        ans.push_back(arr[0]);

        for(int i=1; i<arr.size(); i++) {
            if(check(arr[i] , ans.back())) {
                //include
                ans.push_back(arr[i]);
            }
            else {
                auto index = lower_bound(ans.begin(), ans.end(),arr[i],[](const vector<int>& a,const vector<int>& b) {
                    return a[1] < b[1];
                });
                *index = arr[i];
            }
        }
        return ans.size();
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        sort(envelopes.begin(),envelopes.end(),[](vector<int>&a ,vector<int>&b){
            if(a[0]==b[0])
                return a[1]>b[1];
            return a[0]<b[0];
        });
        return solveOptimal(envelopes);
    }
    
};
