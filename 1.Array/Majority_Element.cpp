https://leetcode.com/problems/majority-element/
// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

// Example 1:

// Input: nums = [3,2,3]
// Output: 3
// Example 2:

// Input: nums = [2,2,1,1,1,2,2]
// Output: 2
*//Intiution
  // we are using boyer-moore majority voting algorithm to find the majority element then confirm it by counting the number
  //of elements in the array
  //in the algorithm we start with one element and count++ if there is same element and count-- if there is any other elment
  //if the count becomes zero then it is no the majority element as majority element is more than the half so if the count
  // becomes zero then it is equal to half so not considered as majority so we move to the next element

  //we decrement the count when we find any other element because for the element to be majority it should have count more
  // than the half of the toatl number of elements so we cancel the other element from the count to check if it is majority
  // if the count becomes zero it means the element is not majority i.e it is element is equal to the all the other element
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int ele=0;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                ele=nums[i];
                count=1;
            }else if(ele==nums[i]){
                count++;
            }else{
                count--;
            }
        }

        int count1=0;
        for(int i=0;i<nums.size();i++){
            if(ele==nums[i])count1++;
        }

        if(count1>(nums.size()/2))return ele;
        return -1;
    }
};
