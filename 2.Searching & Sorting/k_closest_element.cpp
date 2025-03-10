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
// 2)binary search+ two pointer
class Solution {
public:
    int lowerbound(vector<int>& nums,int k){//finding the closest number to x >=x
        int s=0,e=nums.size()-1;
        int ans=e;//bcz if x greater than any of the number present in the array then the h should be the last number
        //eg:3,5,8,10 k=2,x=15 as 15 closest greater or equal to 15 is not present we should take the last number
        while(s<=e){//finding  closest element to x i.e >=x
            int mid=s+(e-s)/2;
            if(nums[mid]>=k){
                ans=mid;
                e=mid-1;
                
            }else if(nums[mid]<k){
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        return ans;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int h=lowerbound(arr,x);
        int l=h-1;
        while((h-l)<=k){
            if(l<0){
                h++;
            }
            else if(h>=arr.size()){
                l--;
            }
            else if((x-arr[l])>(arr[h]-x)){
                h++;
            }
            else{
                l--;
            }
        }
        return vector<int>(arr.begin()+l+1,arr.begin()+h);//as the condition in while loop will make the array contain extra 2 elements to
     //only get k values we are removing one from the front and one from the back ,as the end in vector is not included we are not doing -1
     
    }
};
