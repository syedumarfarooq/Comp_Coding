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
// for n partitions(diving them into two different parts as there are n elements we can divide them in n eg;1,2,3,4,5  , 1 and 2345 , 12 and 345 , 123 and 45 , 1234 and 5, 12345
// ) there are n trees among those n trees there is n sums of non leaf nodes
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
//         for(int i=left;i<right;i++){//the partition can be done from first to last elements and it gives and doing(partition) it in a way where there is  atleast one child  
 // in both subtree i.e we cannot have all the elements in one subtree and another empty as the question says there mustbe two or zero children
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
           *//we are using map even though  unordered map is efficient because In unordered_map, you cannot directly use pair as a key because 
           *//unordered_map requires keys to be hashable, and std::pair does not have a built-in hash function.
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
class Solution {
public:
    int solveUsingTabulation(vector<int>& arr,map<pair<int,int>,int> &maxi,int left,int right){
        int n = arr.size();
        vector<vector<int> > dp(n+1, vector<int>(n+1, 0));
        //in memoisation left is moving from 0 to n-1 and right is moving from n-1 to 0 so we do the opposite in tabulation method
        for(int left = n-1; left>=0; left--) {
            for(int right=0; right<=n-1; right++) {

                if(left>=right)
                    continue;
                else {
                    //valid range
                      int ans = INT_MAX;

                    for(int i=left; i<right; i++) {
                        ans = min(ans, 
                        maxi[{left,i}]*maxi[{i+1, right}] 
                        + dp[left][i]
                        + dp[i+1][right]);
                    }
                    dp[left][right] =  ans;
                    
                }

            }
        }
    return dp[0][n-1];
    }
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int,int>,int> maxi;
        //pre computation
        //we are creating a data structure in which with O(1) we can find the 
        // maximum number in that range
        // i and j are ranges and it stores the maximum number in that range i.e for every range there will be a maximum stored in the map
        for(int i=0;i<arr.size();i++){
            maxi[{i,i}]=arr[i];
            for(int j=i+1;j<arr.size();j++){
                maxi[{i,j}]=max(arr[j],maxi[{i,j-1}]);
            }
        }
        int n=arr.size();
        
        
        int ans=solveUsingTabulation(arr,maxi,0,n-1);
        return ans;
    }
};
