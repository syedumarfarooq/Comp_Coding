https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/
// You are given two integer arrays of the same length nums1 and nums2. In one operation, you are allowed to swap nums1[i] with nums2[i].

// For example, if nums1 = [1,2,3,8], and nums2 = [5,6,7,4], you can swap the element at i = 3 to obtain nums1 = [1,2,3,4] and nums2 = [5,6,7,8].
// Return the minimum number of needed operations to make nums1 and nums2 strictly increasing. The test cases are generated so that the given input always makes it possible.

// An array arr is strictly increasing if and only if arr[0] < arr[1] < arr[2] < ... < arr[arr.length - 1].

 

// Example 1:

// Input: nums1 = [1,3,5,4], nums2 = [1,2,3,7]
// Output: 1
// Explanation: 
// Swap nums1[3] and nums2[3]. Then the sequences are:
// nums1 = [1, 3, 5, 7] and nums2 = [1, 2, 3, 4]
// which are both strictly increasing.
*//logic
  // we are solving this by swapping and no swapping we swap only if the nums2 > p1 and nums1 >p2 and we will only not swap when 
// p1<nums1 and p2<nums2 and we are placing -1 in front of the input string as we have to access previous for first index and -1 is considered as
// previous for first index
// eg:nums1 = [1, 3, 5, 4] and nums2 = [1, 2, 3, 7] let i be at 3rd index and p1 pointing to 5 and p2 pointing to 3 as they satisfy the 
// condition of swapping we swap and for not satisfying the codition for no swap 
*//solved using recursion
class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2,int index,bool swapped){
        if(index==nums1.size())return 0;//length of both the arrays are same

        int ans=INT_MAX;

        int prev1=nums1[index-1];
        int prev2=nums2[index-1];
        //if the previous indexed were swapped then it is marked 1 then we swap the previous as we have not made any changes
        //directly into the array so the value will be same so as we swap them  and compare it will current index 
        //that is y swapped comes in handy
      // eg:nums1 = [1, 3, 5, 4,8] and nums2 = [1, 2, 3, 7,8] if the index is at 4 and we have swapped the 3rd index which is 7 and 4
      //when we are in 4th index we will take prev1 as 7 and prev2 as 4 as we have swapped that is why we use variable to check if we
      //have swapped the previous number 
        if(swapped){
            swap(prev1,prev2);
        }
        //noswap
        if(prev1<nums1[index]&&prev2<nums2[index]){
            ans=solve(nums1,nums2,index+1,0);
        }
        //swap
        if(prev1<nums2[index]&&prev2<nums1[index]){
            ans=min(ans,1+solve(nums1,nums2,index+1,1));
        }
        return ans;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        bool swapped=0;//this is to indicate if the previous indexed were swapped
        return solve(nums1,nums2,1,swapped);
    }
};
*//solved using memoisation
class Solution {
public:
    int solveMem(vector<int>& nums1, vector<int>& nums2,int index,bool swapped,vector<vector<int>>&dp){
        if(index==nums1.size())return 0;
        if(dp[index][swapped]!=-1){
            return dp[index][swapped];
        }
        int ans=INT_MAX;

        int prev1=nums1[index-1];
        int prev2=nums2[index-1];
        if(swapped){
            swap(prev1,prev2);
        }
        //noswap
        if(prev1<nums1[index]&&prev2<nums2[index]){
            ans=solveMem(nums1,nums2,index+1,0,dp);
        }
        //swap
        if(prev1<nums2[index]&&prev2<nums1[index]){
            ans=min(ans,1+solveMem(nums1,nums2,index+1,1,dp));
        }
        dp[index][swapped]=ans;
        return dp[index][swapped];
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        bool swapped=0;//this is to indicate if the previous indexed were swapped
        vector<vector<int>>dp(nums1.size(),vector<int>(2,-1));
        return solveMem(nums1,nums2,1,swapped,dp);
    }
};
*//solve using tabulation
class Solution {
public:
    int solveMem(vector<int>& nums1, vector<int>& nums2){
        vector<vector<int>>dp(nums1.size()+1,vector<int>(2,0));
        for(int index=nums1.size()-1;index>=1;index--){
            for(int swapped=1;swapped>=0;swapped--){
                int ans=INT_MAX;

                int prev1=nums1[index-1];
                int prev2=nums2[index-1];
                if(swapped){
                    swap(prev1,prev2);
                }
                //noswap
                if(prev1<nums1[index]&&prev2<nums2[index]){
                    ans=dp[index+1][0];
                }
                //swap
                if(prev1<nums2[index]&&prev2<nums1[index]){
                    ans=min(ans,1+dp[index+1][1]);
                }
                dp[index][swapped]=ans;
                
            }
        }
        return dp[1][0];
        
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        bool swapped=0;//this is to indicate if the previous indexed were swapped
        
        return solveMem(nums1,nums2);
    }
};
*//Space optimisation
 as dp[index][swapped] is depending on dp[index+1][0] and dp[index+1][1]
class Solution {
public:
    int solveMem(vector<int>& nums1, vector<int>& nums2){
        
        vector<int> curr(2,0);
        vector<int> next(2,0);
        for(int index=nums1.size()-1;index>=1;index--){
            for(int swapped=1;swapped>=0;swapped--){
                int ans=INT_MAX;

                int prev1=nums1[index-1];
                int prev2=nums2[index-1];
                if(swapped){
                    swap(prev1,prev2);
                }
                //noswap
                if(prev1<nums1[index]&&prev2<nums2[index]){
                    ans=next[0];
                }
                //swap
                if(prev1<nums2[index]&&prev2<nums1[index]){
                    ans=min(ans,1+next[1]);
                }
                curr[swapped]=ans;
                
            }
            next=curr;
        }
        return curr[0];
        
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        bool swapped=0;//this is to indicate if the previous indexed were swapped
        
        return solveMem(nums1,nums2);
    }
};
