// https://leetcode.com/problems/house-robber/description/
// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

// Example 1:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.
// Example 2:

// Input: nums = [2,7,9,3,1]
// Output: 12
// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
// Total amount you can rob = 2 + 9 + 1 = 12.
TIME LIMIT EXCEEDED USE DYNAMIC PROGRAMMING
QUESTION NOT UNDERSTOOD COMPLETELY AS THE RECURSION TREE IS NOT UNDERSTABEL BUT ONE THING SOLVE FOR ONE CASE 
class Solution {
public:
    int robHelper(vector<int>& nums,int i){
        if(i>=nums.size()){
            return 0;
        }
        //solve for 1 case
        int robAmt1=nums[i]+robHelper(nums,i+2);
        int robAmt2=0+robHelper(nums,i+2);
        return max(robAmt1,robAmt2);
    }
    int rob(vector<int>& nums) {
        return robHelper(nums,0);
    }
};
// Time Complexity:O(2^N)//same as fibonnaci as single funcition is calling 2 function taught in !Time_and_space_Complexity_of_recursion
// Space Complexity:O(N)
