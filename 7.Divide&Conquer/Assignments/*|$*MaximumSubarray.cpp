https://leetcode.com/problems/maximum-subarray/description/
// CAN SOLVE THIS QUESTION USING KADANE'S ALGORITHM 
// Given an integer array nums, find the 
// subarray
//  with the largest sum, and return its sum.

 

// Example 1:

// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.
// Example 2:

// Input: nums = [1]
// Output: 1
// Explanation: The subarray [1] has the largest sum 1.
// Example 3:

// Input: nums = [5,4,-1,7,8]
// Output: 23
// Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.


// in this we are diving the array from mid and finding the max sum from both side and also check if the joining of both 
// left and right i.e right border and left border gives us the max sum so we check all that and return 
//the left and right max will be given us through the recursion but the cross should be calculated
//i.e to check if the array makes maximum subarray with somepart of left and right

class Solution {
public:
    int maxSubArrayHelper(vector<int>&nums,int start,int end){
        if(start>=end){
            return nums[start];
        }
        int maxLeftBorderSum=INT_MIN,maxRightBorderSum=INT_MIN;
        int mid=start+((end-start)>>1);
        //as the max subarray sum can be on the left or right or in between 
        //maxLeftSum and maxRightSum calculated the max sum of left and right
        //and crossBorderSum calculates the max including the left and right 
        //if there is an subarray whoes sum is greater by includeingg some part
        //of left and right then it is done in crossBordersum
        int maxLeftSum=maxSubArrayHelper(nums,start,mid);
        int maxRightSum=maxSubArrayHelper(nums,mid+1,end);
        int leftBorderSum=0,rightBorderSum=0;
        //calcuting the leftBorder sum for cross Border sum
        for(int i=mid;i>=start;i--){
            leftBorderSum+=nums[i];
            if(leftBorderSum>maxLeftBorderSum){
                maxLeftBorderSum=leftBorderSum;
            }
        }
        //calcuting the rightBorder sum for cross Border sum
        for(int i=mid+1;i<=end;i++){
            rightBorderSum+=nums[i];
            if(rightBorderSum>maxRightBorderSum){
                maxRightBorderSum=rightBorderSum;
            }
        }
        int crossBorderSum=maxLeftBorderSum+maxRightBorderSum;
        return max(maxLeftSum,max(maxRightSum,crossBorderSum));

    }
    int maxSubArray(vector<int>& nums) {
        return maxSubArrayHelper(nums,0,nums.size()-1);
    }
};
