https://leetcode.com/problems/burst-balloons/
// You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.
// If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.
// Return the maximum coins you can collect by bursting the balloons wisely.
// Example 1:

// Input: nums = [3,1,5,8]
// Output: 167
// Explanation:
// nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
// coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
*//logic
  in this we are going from bottom to top not from top to bottom bcz if we have 6 ballons B1,B2,B3,B4,B5,B6 if we take B4 and burst it
then we need solve{B1,B2,B3}+(B3*B4*B5)+solve{B5,B6} and to solve {B1,B2,B3} sub problem if we want to burst B3 , we need B5 (as B4 is already burst)but 
B5 is not part of that subproblem and its dependency is on another subproblem as it is trying to access B5
this is a independency between subproblems and we know Subproblems are independent in dp
*//Subproblems are independent in dp
// so this is the reason we are applying bottom up approach
// eg:3,1,5,8
//  [8]=> 1*8*1, then 8  bursts
//  [3]=>1*3*8, then 3 bursts
//  [5]=>3*5*8, then 5 bursts
//  [1]=>3*1*5,first 1 bursts
  *//how to implement
//   we add 1 on both sides bcz it is said in question if there are only one ballon left on the left and right multiply with 1 
// we iterative trought sart to end adding  one ballon in every step and check which gives the maximum coins
// eg:3,1,5,8
//   1,3,1,e,8,1 start is [1] and end is [4]
//   we check every value from 1-4 for example lets take 5
//   nums[start-1]*nums[i]*nums[end+1]=1*5*1
//   then solve(nums,1,2) and solve(nums,4,4)
//   for this solve(nums,1,2) lets take 3 [1] as i
//   nums[start-1]*nums[i]*nums[end+1]=1*3*5//as 5 was the previous ballon burst
//   it goes on
*//solved using recursion
  class Solution {
public:
    int solve(vector<int>& nums,int start,int end){
        if(start>end)return 0;
        int coins=INT_MIN;
        for(int i=start;i<=end;i++){
            coins=max(coins,
                      nums[start-1]*nums[i]*nums[end+1]//this calcuates the currenct ballon burst
                      +solve(nums,start,i-1)
                      +solve(nums,i+1,end)
            );
        }
        return coins;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);//we are inserting 1 in the beginning and end 
        nums.insert(nums.end(),1);
        return solve(nums,1,nums.size()-2);//as there is 1 and 1 present at both beginning and ending we start from 1 and nums.size()-2
    }
};
*//solved using memoisation
class Solution {
public:
    int solveMem(vector<int>& nums,int start,int end,vector<vector<int>>&dp){
        if(start>end)return 0;
        if(dp[start][end]!=-1){
            return dp[start][end];
        }
        int coins=INT_MIN;
        for(int i=start;i<=end;i++){
            coins=max(coins,
                      nums[start-1]*nums[i]*nums[end+1]
                      +solveMem(nums,start,i-1,dp)
                      +solveMem(nums,i+1,end,dp)
            );
        }
        dp[start][end]= coins;
        return dp[start][end];
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));//for dp[start][end] what is the max coins
        return solveMem(nums,1,nums.size()-2,dp);
    }
};
*//solved using tabulation
class Solution {
public:
    int solveTab(vector<int>& nums){
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),0));
        for(int start=nums.size()-2;start>=1;start--){
            for(int end=1;end<=nums.size()-2;end++){
                if(start>end)continue;//if start>end we dont calculate it is base case of else we can start end= start
                int coins=INT_MIN;
                for(int i=start;i<=end;i++){
                    coins=max(coins,
                            nums[start-1]*nums[i]*nums[end+1]
                            +dp[start][i-1]
                            +dp[i+1][end]
                    );
                }
                dp[start][end]= coins;
                    }
                }
                
        return dp[1][nums.size()-2];
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);
        return solveTab(nums);
    }
};
