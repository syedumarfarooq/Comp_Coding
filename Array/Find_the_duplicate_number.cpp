// https://leetcode.com/problems/find-the-duplicate-number/
// hint:if the range is form i to n then we can consider elements as index
// #Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
// There is only one repeated number in nums, return this repeated number.
// You must solve the problem without modifying the array nums and uses only constant extra space.
// Example 1:
//   Input: nums = [1,3,4,2,2]
//   Output: 2
// Example 2:
//   Input: nums = [3,1,3,4,2]
//   Output: 3
// 1)sorting method
// wrong answer and does not meet the question because it says without modifying the array
// first sort then check if the adjacent number is same i.e i and i+1 if same then found the duplicate number
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         for(int i=0;i<nums.size()-1;i++){
//             if(nums[i]==nums[i+1]){
//                 return nums[i];
//             }
//         }
//         return -1;
//     }
// };
// 2)marking negative
//wrong answer and does not meet the question because it says without modifying the array
//marking negative to the index for the elements if the elements is already negative then it is visited once and it is duplicate
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         int ans=-1;
//         for(int i=0;i<nums.size();i++){
//             index=abs(nums[i]);
//             if(num[index]<0){
//                 ans=index;
//                 break;
//             }
//             nums[index]*=-1;
//         }
//         return ans;
//     }
// };
// 3)positioning the element to its right place(index), then if there is a same element you are trying to put in that index then return that element
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        while(nums[0]!=nums[nums[0]]){
            swap(nums[0],nums[nums[0]]);
        }
        return nums[0];
    }
};
// [1,3,4,2,2]
// [3,1,4,2,2]
// [2,1,4,3,2]
// [4,1,2,3,2]
// [2,1,2,3,4]
// =>2
