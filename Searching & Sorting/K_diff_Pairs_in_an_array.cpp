// https://leetcode.com/problems/k-diff-pairs-in-an-array/description/
// Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

// A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

// 0 <= i, j < nums.length
// i != j
// |nums[i] - nums[j]| == k
// Notice that |val| denotes the absolute value of val.

 

// Example 1:

// Input: nums = [3,1,4,1,5], k = 2
// Output: 2
// Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
// Although we have two 1s in the input, we should only return the number of unique pairs.
// Example 2:

// Input: nums = [1,2,3,4,5], k = 1
// Output: 4
// Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
// 1)bruteforce
// consider each and every pair and perform subtraction
// for(i=0;i<n;i++){
//   for(j=i+1;j<=n;j++){
//       if(abs(arr[i]-arr[j])==k){
//         count++;
//       }
//   }
// }
// 2)two pointer approach
//  int findPairs(vector<int>& nums, int k) {
    //     sort(nums.begin(),nums.end());
    //     set<pair<int,int>> ans;
    //     int i=0,j=1;
    //     while(j<nums.size()){
    //         int diff=nums[j]-nums[i];
    //         if(diff==k){
    //             ans.insert({nums[i],nums[j]});
    //             i++,j++;
    //         }
    //         else if(diff<k){
    //             j++;
    //         }
    //         else{
    //             i++;
    //         }
    //         if(i==j){
    //             j++;
    //         }
    //     }
    //     return ans.size();
    // }
// 3)using binary search
class Solution {
public:
    int bn(vector<int>& nums,int start,int k){
        int s=start,e=nums.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==k){
                return mid;
            }else if(nums[mid]<k){
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        return -1;
    }
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        set<pair<int,int>> ans;
        for(int i=0;i<nums.size()-1;i++){
            int j=bn(nums,i+1,nums[i]+k);
            if(j!=-1){
                ans.insert({nums[i],nums[j]});
            }
        }
        return ans.size();
    }

};
