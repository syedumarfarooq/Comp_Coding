// You are given an array nums of n integers and an integer k.

// For each subarray of nums, you can apply up to k operations on it. In each operation, you increment any element of the subarray by 1.

// Note that each subarray is considered independently, meaning changes made to one subarray do not persist to another.

// Return the number of subarrays that you can make non-decreasing ​​​​​after performing at most k operations.

// An array is said to be non-decreasing if each element is greater than or equal to its previous element, if it exists.

// Example 1:

// Input: nums = [6,3,1,2,4,4], k = 7

// Output: 17

// Explanation:

// Out of all 21 possible subarrays of nums, only the subarrays [6, 3, 1], [6, 3, 1, 2], [6, 3, 1, 2, 4] and [6, 3, 1, 2, 4, 4] cannot be made non-decreasing after applying up to k = 7 operations. Thus, the number of non-decreasing subarrays is 21 - 4 = 17.

// Example 2:

// Input: nums = [6,3,1,3,6], k = 4

// Output: 12

// Explanation:

// The subarray [3, 1, 3, 6] along with all subarrays of nums with three or fewer elements, except [6, 3, 1], can be made non-decreasing after k operations. There are 5 subarrays of a single element, 4 subarrays of two elements, and 2 subarrays of three elements except [6, 3, 1], so there are 1 + 5 + 4 + 2 = 12 subarrays that can be made non-decreasing.


// 1. if a subarray  satisfies teh condition of becoming increasing with atmost k operation
// 2. then the if we remove elements  from left or right they will also satisfy with the given k operation
// 3. so to cound  total valid subarray from i to j will be j-i+1,only if the subarry from i to j is valid first
// 4. first we are finding operation from every index to the end; in this we go in reverse direction i.e from right to left to make it simpler we calculate the opertion of i using opertion of next greater element and nums[i]*1LL*(m-i))-(rangeSum(i,m-1)
// 5. why this because we want the subarray accending if the current element has some next greater element(nge) that means after that nge the operationm will be same, so we calculate the from i to the nge becuase it can be different
// 6. in the final slidding window method to find the result =operation[i]-operation[m])+((nums[m]*1LL*(j-m+1))-rangeSum(m,j)
// 7.  we use this formula to first find the number of peration from i to max becuase we have already calculated and calculate the rest because we have calulated the operation from i to end in operations arrray, but in the result we dont want till the end so we calculate till j


class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        vector<long long> pref(nums.size(),0);
        pref[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            
            pref[i]=nums[i]+pref[i-1];
        }
        //rangeSum
        auto rangeSum=[&](int i,int j){
            if(i>j)return 0LL;
            return pref[j]-((i>0)?pref[i-1]:0LL);
        };
        ///next greates element
        vector<int> NGE(nums.size(),nums.size());
        stack<int> st;
        for(int i=0;i<nums.size();i++){
            while(!st.empty()&&nums[st.top()]<nums[i]){
                NGE[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        //count number of operation from each index to last to become increasing
        vector<long long> operation(nums.size()+1,0);
        for(int i=nums.size()-1;i>=0;i--){
            int m=NGE[i];
            operation[i]=operation[m]+(nums[i]*1LL*(m-i))-(rangeSum(i,m-1));
        }

        //sliding window
        int i=0;
        int j=0;
        deque<int> dq;
        long long result;
        while(j<nums.size()){
            while(!dq.empty()&& nums[dq.back()]<nums[j]){
                dq.pop_back();
            }
            dq.push_back(j);
            
            while(i<=j){
                int m=dq.front();
                long long total_op=(operation[i]-operation[m])+((nums[m]*1LL*(j-m+1))-rangeSum(m,j));
                if(total_op<=k){
                    break;
                }
                i++;
                if(dq.front()<i){
                    dq.pop_front();
                }
            }
            result+=(j-i+1);
            j++;
            

        }
        return result;
    }
};
