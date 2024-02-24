// https://leetcode.com/problems/find-k-closest-elements/description/
// Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

// An integer a is closer to x than an integer b if:

// |a - x| < |b - x|, or
// |a - x| == |b - x| and a < b
 

// Example 1:

// Input: arr = [1,2,3,4,5], k = 4, x = 3
// Output: [1,2,3,4]
// Example 2:

// Input: arr = [1,2,3,4,5], k = 4, x = -1
// Output: [1,2,3,4]
// 1)two pointer approach
// class Solution {
// public:
//     vector<int> findClosestElements(vector<int>& arr, int k, int x) {
//         int l=0,h=arr.size()-1;
//         while((h-l)>=k){
//             if(abs(arr[l]-x)>abs(arr[h]-x)){
//                 l++;
//             }else{
//                 h--;
//             }
//         }
//         vector<int> ans;             
//         for(int i=l;i<=h;i++){
//             ans.push_back(arr[i]);
//         }
//         return ans;
//     }
// };
// Time complexity:we are reducing the array from n to k so it takes n-k comparison
//                 O(n-k)
// Space complexity:we have used O(k) for ans
