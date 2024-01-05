// !!!!!problem in submitting the answer but answer works fine first answer second answer works fine using hash(map)
// https://www.geeksforgeeks.org/problems/first-repeating-element4018/1
// First Repeating Element


// Given an array arr[] of size n, find the first repeating element. The element should occur more than once and the index of its first occurrence should be the smallest.

// Note:- The position you return should be according to 1-based indexing. 

// Example 1:

// Input:
// n = 7
// arr[] = {1, 5, 3, 4, 3, 5, 6}
// Output: 2
// Explanation: 
// 5 is appearing twice and 
// its first appearence is at index 2 
// which is less than 3 whose first 
// occuring index is 3.
// First Repeating Element
// EasyAccuracy: 32.57%Submissions: 212K+Points: 2
// 90% Refund available on all premium courses 
// Discover How  

// banner
// Given an array arr[] of size n, find the first repeating element. The element should occur more than once and the index of its first occurrence should be the smallest.

// Note:- The position you return should be according to 1-based indexing. 

// Example 1:

// Input:
// n = 7
// arr[] = {1, 5, 3, 4, 3, 5, 6}
// Output: 2
// Explanation: 
// 5 is appearing twice and 
// its first appearence is at index 2 
// which is less than 3 whose first 
// occuring index is 3.
// class Solution {
//   public:
//     // Function to return the position of the first repeating element.
//     int firstRepeated(int arr[], int n) {
//         // code here
//         int maxi=INT_MIN;
//         for(int i=0;i<n;i++){
//             if(arr[i]>maxi){
//                 maxi=arr[i];
//             }
//         }
//         int size=0;
//         if(n>maxi){
//             size=n;
            
//         }
//         else{
//             size=maxi;
//         }
//         int hash[size]={0};
        
//         for(int i=0;i<n;i++){
//             hash[arr[i]]++;
//         }
//         for(int i=0;i<n;i++){
//             if(hash[arr[i]]>1){
            
//                 return i+1;
               
//             }
//         }
//         return -1;
//     }
// };
// 2)using map
class Solution {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n) {
        // code here
        unordered_map<int,int>hash;
        for(int i=0;i<n;i++){
            hash[arr[i]]++;
            
        }
        for(int i=0;i<n;i++){
            if(hash[arr[i]]>1){
                return i+1;
            }
        }
        return -1;
    }
    
};

