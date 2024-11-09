https://leetcode.com/problems/partition-equal-subset-sum/
// Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.
// Example 1:

// Input: nums = [1,5,11,5]
// Output: true
// Explanation: The array can be partitioned as [1, 5, 5] and [11].
// Example 2:

// Input: nums = [1,2,3,5]
// Output: false
// Explanation: The array cannot be partitioned into equal sum subsets.
*//Logic
  // we are adding all the elements in the num and dividing it into two ,if the sum is odd then we return false as we cannot find equal subset
  // we are setting the target as half of sum if we find the subset whose sum is equal to target then there will be another subset with equal 
  // value we are using include exclude method to create subsets
*//Solved using recursion
// class Solution {
// public:
//     bool solveUsingRecursion(int index,vector<int>&nums,int target){
//         int n=nums.size();
//         if(index>=n){
//             return false;
//         }
//         if(target<0){
//             return false;
//         }
//         if(target==0){
//             return true;
//         }
//         bool include=solveUsingRecursion(index+1,nums,target-nums[index]);
//         bool exclude=solveUsingRecursion(index+1,nums,target);
//         return (include||exclude);
//     }
//     bool canPartition(vector<int>& nums) {
//         int sum=0;
//         for(int i=0;i<nums.size();i++){
//             sum+=nums[i];
//         }
//         if(sum&1){//tend to forget
//             return false;//bcz if the sum is odd we cannot find equal subset
//         }
//         int target=sum/2;
//         int index=0;
//         bool ans=solveUsingRecursion(index,nums,target);
//         return ans;
//     }
// };
  *//Solved Using memoisation
//   class Solution {
// public:
//     bool solveUsingMem(int index,vector<int>&nums,int target,vector<vector<int>>&dp){
//         int n=nums.size();
//         if(index>=n){
//             return false;
//         }
//         if(target<0){
//             return false;
//         }
//         if(target==0){
//             return true;
//         }
//         if(dp[index][target]!=-1){
//             return dp[index][target];        
//         }
//         bool include=solveUsingMem(index+1,nums,target-nums[index],dp);
//         bool exclude=solveUsingMem(index+1,nums,target,dp);
//         dp[index][target]=(include||exclude);
//         return dp[index][target];
//     }
//     bool canPartition(vector<int>& nums) {
//         int sum=0;
//         for(int i=0;i<nums.size();i++){
//             sum+=nums[i];
//         }
//         if(sum&1){//tend to forget
//             return false;//bcz if the sum is odd we cannot find equal subset
//         }
//         int target=sum/2;
//         int index=0;
//         // 2DDP array because there are 2 parameter which are changing in function one is index and another is target
//         vector<vector<int>>dp(nums.size(),vector<int>(target+1,-1));

//         bool ans=solveUsingMem(index,nums,target,dp);
//         return ans;
//     }
// };
  *//Using Tabulation method
//   class Solution {
// public:
//     bool solveUsingTabulation(vector<int>&nums,int target){
//         vector<vector<int>>dp(nums.size()+1,vector<int>(target+1,0));
//         //if target ==0 then that can be asolution 
//         for(int i=0;i<nums.size();i++){
//             dp[i][0]=1;
//         }
//         //the dp tells for which index and target there can be a posible solution 
        
//         //opposite of top down method or memoisation
//         for(int index=nums.size()-1;index>=0;index--){
//             //for a index to be a possible solution then the next index with or without included should be a possible solution 
//             //as we are coming from the last index the solution is possible only if the current index and next index together gives us a possible solution
//             for(int t=1;t<=target;t++){
//                 bool include=0;
//                 if(t-nums[index]>=0)
//                   include=dp[index+1][t-nums[index]];
//                 bool exclude=dp[index+1][t];
//                 dp[index][t]=(include||exclude);
                 
//             }
//         }
        
//        return dp[0][target];
//     }
//     bool canPartition(vector<int>& nums) {
//         int sum=0;
//         for(int i=0;i<nums.size();i++){
//             sum+=nums[i];
//         }
//         if(sum&1){//tend to forget
//             return false;//bcz if the sum is odd we cannot find equal subset
//         }
//         int target=sum/2;
//         int index=0;
//         bool ans=solveUsingTabulation(nums,target);
//         return ans;
//     }
// };
  *//Solved using space optimisation
// class Solution {
// public:
//     bool solveUsingSO(vector<int>&nums,int target){
//         vector<int>curr(target+1,0); 
//         vector<int>next(target+1,0); 
//         //if target ==0 then that can be a solution 
        
//             next[0]=1;
        
       
//         for(int index=nums.size()-1;index>=0;index--){
//             for(int t=1;t<=target;t++){
//                 bool include=0;
//                 if(t-nums[index]>=0)
//                   include=next[t-nums[index]];
//                 bool exclude=next[t];
//                 curr[t]=(include||exclude);
                 
//             }
//             //shifting
//             next=curr;
//         }
        
//        return next[target];
//     }
//     bool canPartition(vector<int>& nums) {
//         int sum=0;
//         for(int i=0;i<nums.size();i++){
//             sum+=nums[i];
//         }
//         if(sum&1){//tend to forget
//             return false;//bcz if the sum is odd we cannot find equal subset
//         }
//         int target=sum/2;
//         int index=0;
//         bool ans=solveUsingSO(nums,target);
//         return ans;
//     }
// };
*//Solved using space optimisation 2
class Solution {
public:
    bool solveUsingSO2(vector<int>&nums,int target){
        vector<int>curr(target+1,0); 
         
        //if target ==0 then that can be a solution 
        
            curr[0]=1;
        
       //as curr wants t-nums[index] that is on the left or current node value
       //if we go fom left to right we may override some of the previous values which we might need from curr
       //but if we go from right to left we can change values without overiding the values we might need as we need values from left side
        for(int index=nums.size()-1;index>=0;index--){
            for(int t=target;t>=0;t--){
                bool include=0;
                if(t-nums[index]>=0)
                  include=curr[t-nums[index]];
                bool exclude=curr[t];
                curr[t]=(include||exclude);
                 
            }
        }
        
       return curr[target];
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum&1){//tend to forget
            return false;//bcz if the sum is odd we cannot find equal subset
        }
        int target=sum/2;
        int index=0;
        bool ans=solveUsingSO(nums,target);
        return ans;
    }
};
