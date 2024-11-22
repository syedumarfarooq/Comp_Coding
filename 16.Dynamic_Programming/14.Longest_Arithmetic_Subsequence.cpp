https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/
// Given an integer array arr and an integer difference, return the length of the longest subsequence in arr which is an arithmetic sequence such that the difference between adjacent elements in the subsequence equals difference.
// A subsequence is a sequence that can be derived from arr by deleting some or no elements without changing the order of the remaining elements.
// Example 1:
// Input: arr = [1,2,3,4], difference = 1
// Output: 4
// Explanation: The longest arithmetic subsequence is [1,2,3,4].
*//logic
https://github.com/syedumarfarooq/Comp_Coding/blob/main/16.Dynamic_Programming/12.Longest_Increasing_Subsequence.cpp
*//we are using the logic of longest increasing subsequence in that we add the elemnt if the current is greater than the prev in this we do
*// the same logic with minute changes we add the element  only if the difference of curr and prev is equal to the difference
*//same logic can be use to solve https://leetcode.com/problems/maximum-height-by-stacking-cuboids/
  *//solve using space optimisation
  *//TLE 
 class Solution {
public:
    int solveUsingTabSO(vector<int>& arr,int difference) {
        int n = arr.size();
        //vector<vector<int> > dp(n+1, vector<int>(n+1, 0));
        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);

        for(int curr = n-1; curr>=0; curr--) {
            for(int prev = curr - 1; prev >= -1; prev--) {
                //include
                int include = 0;
                if(prev == -1 || arr[curr]-arr[prev]==difference)//changes made here
                    include = 1 + nextRow[curr + 1];

                //excude
                int exclude = 0 + nextRow[prev + 1];

                currRow[prev + 1] = max(include, exclude);   
            }
            //shift
            nextRow = currRow;
        }
        return nextRow[0];
    }
    int longestSubsequence(vector<int>& arr, int difference) {
        int ans=solveUsingTabSO(arr,difference);
        return ans;
    }
};
*//Solve optimal 
*//logic
  //if u want to get the answer of current then we have to add 1(as u r including current element) and the dp of the previous number that 
  //comes in ur ap
    // An Arithmetic Progression (AP) is a sequence of numbers in which the difference between any two consecutive terms is constant
  //eg: 7,5,3,1 and difference =-2 for 7 , 9 should be there for 5 seven should be there sp for dp[5]=dp[7]+1;as the number before in the
  // ap is 7 (5-(-2) =7
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int>dp;
        int ans=0;
        
        for(int i=0;i<arr.size();i++){
            int temp=arr[i]-difference;
            int tempAns=0;
          
            if(dp.count(temp))//checks if the dp is present 
                tempAns=dp[temp];
            dp[arr[i]]=1+tempAns;
            ans=max(ans,dp[arr[i]]);//compares everytime and stores the maximum out of all the sequence
        }
        return ans;
    }
};
