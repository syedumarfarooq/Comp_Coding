https://leetcode.com/problems/target-sum/
// You are given an integer array nums and an integer target.

// You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

// For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
// Return the number of different expressions that you can build, which evaluates to target.

 

// Example 1:

// Input: nums = [1,1,1,1,1], target = 3
// Output: 5
// Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
// -1 + 1 + 1 + 1 + 1 = 3
// +1 - 1 + 1 + 1 + 1 = 3
// +1 + 1 - 1 + 1 + 1 = 3
// +1 + 1 + 1 - 1 + 1 = 3
// +1 + 1 + 1 + 1 - 1 = 3
*//logic
//   in this we are adding the current element in one way and subtracting in another way with target if all the elements are either added 
  // or subtracted and we get 0 at the end of the array then that is a possible solution so if it is a possible solution we return 1 in
  //the base case 
*//solved using recursion
class Solution {
public:
    int solve(vector<int>& nums, int target,int i){
        if(i==nums.size()){
            return target==0 ? 1 : 0;
        }
        int way1=solve(nums,target-nums[i],i+1);
        int way2=solve(nums,target+nums[i],i+1);
        return way1+way2;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums,target,0);
    }
};
*//solved using memoisation
class Solution {
public:
    int solveMem(vector<int>& nums, int target,int i, map<pair<int,int>,int>&dp){
        if(i==nums.size()){
            return target==0 ? 1 : 0;
        }
        if(dp.find({i,target})!=dp.end()){
            return dp[{i,target}];
        }
        int way1=solveMem(nums,target-nums[i],i+1,dp);
        int way2=solveMem(nums,target+nums[i],i+1,dp);
        dp[{i,target}]=way1+way2;
        return dp[{i,target}];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        //as target can go negative we are using map
        map<pair<int,int>,int>dp;//{i,target}->no of ways
        return solveMem(nums,target,0,dp);
    }
};
*//solve using tabulation
class Solution {
public:
    int solveTab(vector<int>& nums,int target){
        //as target can go negative we are using map
        map<pair<int,int>,int>dp;//{i,target}->no of ways
        dp[{nums.size(),0}]=1;
        int total=0;
        for(auto num:nums)total+=num;//as target might go into negative value  when we minus nums[i]
        //at most worst case it can go if we add all
        //elements or subtract all elements in nums and the target is 0 the target might go from -total to total
        for(int i=nums.size()-1;i>=0;i--){
            for(int target=-total;target<=total;target++){
                int way1=dp[{i+1,target-nums[i]}];
                int way2=dp[{i+1,target+nums[i]}];
                dp[{i,target}]=way1+way2;
            }
        }
        
        return dp[{0,target}];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        return solveTab(nums,target);
    }
};
