https://www.geeksforgeeks.org/problems/largest-subarray-of-0s-and-1s/1
// Given an array of 0s and 1s. Find the length of the largest subarray with equal number of 0s and 1s.

// Examples:

// Input: n = 4, arr[] = {0,1,0,1}
// Output: 4
// Explanation: The array from index [0...3] contains equal number of 0's and 1's. Thus maximum length of subarray having equal number of 0's and 1's is 4.
// Input: n = 5, arr[] = {0,0,1,0,0}
// Output: 2
*//LOGIC//
  https://github.com/syedumarfarooq/Comp_Coding/blob/main/15.Hashmaps%26Tries/Assignments/Largest_subarray_with_0_sum.cpp
//   using the same logic as largest subarray with 0 sum by replacing 0 to -1 in the original array as this will make the sum 0 if ther are 
// equal number of 0 and 1 
class Solution {
  public:
    int maxLen(int arr[], int n) {
         unordered_map<int,int>map;
        int csum=0;
        int ans=0;//max length of the subarray with sum 0
        for(int i=0;i<n;i++){
            int val=arr[i]==0?-1:arr[i];
            csum+=val;
            if(csum==0){//this means it is cancelling whole array until i
            //i.e sum of the subarray is 0
                ans=max(ans,i+1);
            }else if(map.find(csum)==map.end()){
                map[csum]=i;
            }else{
                ans=max(ans,i-map[csum]);
            }
        }
        return ans;
    }
};
