https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
// Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

// Examples:

// Input: arr[] = {15,-2,2,-8,1,7,10,23}, n = 8
// Output: 5
// Explanation: The largest subarray with sum 0 is -2 2 -8 1 7.
// Input: arr[] = {2,10,4}, n = 3
// Output: 0
// Explanation: There is no subarray with 0 sum.
*//LOGIC**
  // in this we are creating an entry of it total sum for every elements of the array i.e for ith element i+i-1+i-2+....
  // we are doing this because if a sum after some calculation becomes same then the calculation happened in between is giving answer zero 
// that is why we are storing sum of all the indexes if sum of any element repeat it means the inbetween is getting cancelled 
// another case can be the sum  is becoming zero then we can directly store index as from intial the sum is zero this means the entire sum
  // of the array until i is zero

class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        unordered_map<int,int>map;
        int csum=0;
        int ans=0;//max length of the subarray with sum 0
        for(int i=0;i<n;i++){
            csum+=arr[i];
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
