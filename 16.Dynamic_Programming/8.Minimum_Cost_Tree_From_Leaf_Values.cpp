https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/
// Given an array arr of positive integers, consider all binary trees such that:

// Each node has either 0 or 2 children;
// The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
// The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.
// Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node. It is guaranteed this sum fits into a 32-bit integer.

// A node is a leaf if and only if it has zero children.

 

// Example 1:


// Input: arr = [6,2,4]
// Output: 32
// Explanation: There are two possible trees shown.
// The first has a non-leaf node sum 36, and the second has non-leaf node sum 32.
*//Logic
// for n partitions there are n trees among those n trees there is n sums of non leaf nodes
// partition is done because to divide the tree into two trees then we find the maximum element from the unordered map from both the trees
// and multiply and store the answer as the parent node and its two children are the the two trees partitioned before
*//Solved using recursion
// class Solution {
// public:
//     int solveUsingRecursion(vector<int>& arr,map<pair<int,int>,int> &maxi,int left,int right){
//         if(left==right){
//             return 0;
//         }
//         int ans=INT_MAX;
//         for(int i=left;i<right;i++){//the partition can be done from first to last elements and it gives 
//             ans=min(ans,
//             maxi[{left,i}]*maxi[{i+1,right}]+//here maximum of left and right subtrees are multiplied and added to the answer as there are 
//               //non leaf node
//             solveUsingRecursion(arr,maxi,left,i)+//this is to calculate the left and right subtrees and return sum of thier non leaf node
//             solveUsingRecursion(arr,maxi,i+1,right)
//             );
//         }
//         return ans;
//     }
//     int mctFromLeafValues(vector<int>& arr) {
//         map<pair<int,int>,int> maxi;
//         //pre computation
//         //we are creating a data structure in which with O(1) we can find the 
//         // maximum number in that range
//         // i and j are ranges and it stores the maximum number in that range i.e for every range there will be a maximum stored in the map
//         for(int i=0;i<arr.size();i++){
//             maxi[{i,i}]=arr[i];
//             for(int j=i+1;j<arr.size();j++){
//                 maxi[{i,j}]=max(arr[j],maxi[{i,j-1}]);
//             }
//         }
//         int n=arr.size();
//         int ans=solveUsingRecursion(arr,maxi,0,n-1);
//         return ans;
//     }
// };
*//Solved using memoisation
// class Solution {
// public:
//     int solveUsingMem(vector<int>& arr,map<pair<int,int>,int> &maxi,int left,int right,vector<vector<int>>& dp){
//         if(left==right){
//             return 0;
//         }
//         if(dp[left][right]!=-1){
//             return dp[left][right];
//         }
//         int ans=INT_MAX;
//         for(int i=left;i<right;i++){
//             ans=min(ans,
//             maxi[{left,i}]*maxi[{i+1,right}]+
//             solveUsingMem(arr,maxi,left,i,dp)+
//             solveUsingMem(arr,maxi,i+1,right,dp)
//             );
//         }
//         dp[left][right]=ans;
//         return dp[left][right];
//     }
//     int mctFromLeafValues(vector<int>& arr) {
//         map<pair<int,int>,int> maxi;
//         //pre computation
//         //we are creating a data structure in which with O(1) we can find the 
//         // maximum number in that range
//         // i and j are ranges and it stores the maximum number in that range i.e for every range there will be a maximum stored in the map
//         for(int i=0;i<arr.size();i++){
//             maxi[{i,i}]=arr[i];
//             for(int j=i+1;j<arr.size();j++){
//                 maxi[{i,j}]=max(arr[j],maxi[{i,j-1}]);
//             }
//         }
//         int n=arr.size();
//         vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
//         int ans=solveUsingMem(arr,maxi,0,n-1,dp);
//         return ans;
//     }
// };
  *//Solved Using Tabulation
