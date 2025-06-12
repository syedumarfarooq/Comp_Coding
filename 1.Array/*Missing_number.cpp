https://leetcode.com/problems/missing-number/
// Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
// Example 1:
// Input: nums = [3,0,1]
// Output: 2
// Explanation:
// n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
// Example 2:
// Input: nums = [0,1]
// Output: 2
// Explanation:
// n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.
// Example 3:
// Input: nums = [9,6,4,2,3,5,7,0,1]
// Output: 8
// Explanation:
// n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = nums.size();// adding last index to the result becuase to find the sum of indexes we need all the index
        //but as we are considering the array for index there is one less index which is the last index so we add it
        //as there is one element missing in the array so the array will be smaller by one element so we add nums.size()
        //eg: arr:0,1,3 index:0,1,2 so for the sum of index should be 0+1+2+3 to find the difference and the missing element
        //0+1+2+3 - (0+1+3)(array sum) will give us the missing element
        // Because in a list of size n, the numbers should be from 0 to n. So:
        //     The indexes go from 0 to n-1
        //     But the numbers are from 0 to n (total n+1 numbers)
            // so n is missing
        for (int i = 0; i < nums.size(); i++) {
            res += i - nums[i];// sum of indexes= sum of elements in array if there are all the elements present in the array
        }
        //so sum of indexes- sum of elements will give us 0 if all the elements are present
        //if there is any missing number  sum of indexes- sum of elements will give us that number
        return res;        
    }
};
