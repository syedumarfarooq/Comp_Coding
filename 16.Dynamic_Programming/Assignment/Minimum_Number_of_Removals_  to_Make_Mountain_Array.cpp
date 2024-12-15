https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/
// You may recall that an array arr is a mountain array if and only if:

// arr.length >= 3
// There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
// arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
// arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
// Given an integer array nums​​​, return the minimum number of elements to remove to make nums​​​ a mountain array.
// Example 1:

// Input: nums = [1,3,1]
// Output: 0
// Explanation: The array itself is a mountain array so we do not need to remove any elements.
*//logic
  // in this we have to find the minimum number of elements to remove to make a mountain array for that if we find the maximum size mountain
// array and subtract it with nums.length it will be the elements that needs to be removed to make mountain array
  // for finding the maximum size mountain array using longest increasing subsequence
// i.e we find longest increasing subsequence of every element by making it the pivot and then also find logest decreasing subsequence
// eg:nums:2,1,1,5,6,2,3,1
//     LIS:1,1,1,2,3,2,3,1
//     LDS:2,1,1,3,3,2,2,1//if we reverse the nums and apply lis to it that is reversed LDS  and then reverse it to find LDS
//   current ith size of mountain array=LIS[i]+LDS[i]-1//-1 because in both the pivot element is counted so we include it once
//   eg:6 has lis 3 (1,5,6) and lds(6,3,1) if we add both and remove one 6 we get the longest mountain array with pivot 6
  //if LIS[i] or LDS[i] is 1 that is when we ignore for making a mountain we need atleast 2 from both LIS ans LDS as it will be added up to 
  // 4 and we remove as there is repetition of pivot and there must be minimum 3 elements to make it to make a mountain i.e one on the left
  // and one on the right
  //so at last we are finding max of LIS[i]+lDS[i]-1 whichever i gives the maximum it is the maximum size mountain and if we minus it with
  //nums.length then we will get the extra elements that needs to removed
*//solved using Longest Increasing subsequence
  class Solution {
public:
    int solveOptimal(vector<int>& arr,vector<int>& lis) {
        if(arr.size() == 0)
            return 0;
        vector<int> ans;
        lis.push_back(1);//adding 1 to the first element if arr[1] is pivot there is no increasing subsequence until arr[1]
        ans.push_back(arr[0]);

        for(int i=1; i<arr.size(); i++) {
            if(arr[i] > ans.back()) {
                //include
                ans.push_back(arr[i]);
                lis.push_back(ans.size());//ans.size contains the number of increasing subsequence until i so for every i the ans length
              //will give the longest increasing subsequence for arr[i] as pivot
            }
            else {
                int index = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
                ans[index] = arr[i];
                lis.push_back(index+1);//so  at whichever index we are swapping the  arr[i]that index will give us number of lis until arr[i]
              // or arr[i] as the pivot as the index indicates
              //the number of elements present in ans and it is the LIS as the indexing starts from 0 we add 1
            }
        }
        return ans.size();
    }
    int minimumMountainRemovals(vector<int>& nums) {
        vector<int>lds,lis;
        solveOptimal(nums,lis);
        reverse(nums.begin(),nums.end());
        solveOptimal(nums,lds);
        //main logic
        int largestMountain=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(lis[i]==1||lds[nums.size()-i-1]==1)continue;//as the lds is reversed due to finding lds of it by apply lis to the reversed
          // array and the answer is also reversed we start i from beginning for lis and from end for lds
            largestMountain=max(largestMountain,lis[i]+lds[nums.size()-i-1]-1);
        }
        int minRemovals=nums.size()-largestMountain;
        return minRemovals;
    }
};
