https://leetcode.com/problems/single-number/description/
// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
// You must implement a solution with a linear runtime complexity and use only constant extra space.
// Example 1:
// Input: nums = [2,2,1]
// Output: 1
// Example 2:

// Input: nums = [4,1,2,1,2]
// Output: 4
*//logic
  // in this if we xor same number it will be zero that one only number left will be the single element present in the nums array eg:4^4=0 , 4^4^1=1 as 4^4 is 0
*//code 
int singleNumber(vector<int>&nums){
  int ans=0;
  for(int i=0;i<nums.size();i++){
    ans=ans^nums[i];
    
  }
  return ans;
}
