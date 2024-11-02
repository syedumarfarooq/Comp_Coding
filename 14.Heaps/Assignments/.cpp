https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/
// You are given a 0-indexed integer array nums consisting of 3 * n elements.

// You are allowed to remove any subsequence of elements of size exactly n from nums. The remaining 2 * n elements will be divided into two equal parts:

// The first n elements belonging to the first part and their sum is sumfirst.
// The next n elements belonging to the second part and their sum is sumsecond.
// The difference in sums of the two parts is denoted as sumfirst - sumsecond.

// For example, if sumfirst = 3 and sumsecond = 2, their difference is 1.
// Similarly, if sumfirst = 2 and sumsecond = 3, their difference is -1.
// Return the minimum difference possible between the sums of the two parts after the removal of n elements.

 

// Example 1:

// Input: nums = [3,1,2]
// Output: -1
// Explanation: Here, nums has 3 elements, so n = 1. 
// Thus we have to remove 1 element from nums and divide the array into two equal parts.
// - If we remove nums[0] = 3, the array will be [1,2]. The difference in sums of the two parts will be 1 - 2 = -1.
// - If we remove nums[1] = 1, the array will be [3,2]. The difference in sums of the two parts will be 3 - 2 = 1.
// - If we remove nums[2] = 2, the array will be [3,1]. The difference in sums of the two parts will be 3 - 1 = 2.
// The minimum difference between sums of the two parts is min(-1,1,2) = -1. 
// Example 2:

// Input: nums = [7,9,5,8,1,3]
// Output: 1
// Explanation: Here n = 2. So we must remove 2 elements and divide the remaining array into two parts containing two elements each.
// If we remove nums[2] = 5 and nums[3] = 8, the resultant array will be [7,9,1,3]. The difference in sums will be (7+9) - (1+3) = 12.
// To obtain the minimum difference, we should remove nums[1] = 9 and nums[4] = 1. The resultant array becomes [7,5,8,3]. The difference in sums of the two parts is (7+5) - (8+3) = 1.
// It can be shown that it is not possible to obtain a difference smaller than 1.
*//LOGIC***
//For the sum of a - sum of b to be minimal then the sum of a must be minimum or small and sum of b must be maximum or big so that we can 
// obtain minimal solution
// eg:3-10=-7
//so we are finding minimum sum from left and maximum from right bcz sum of a is n elements from left to right and sum of b is n elements from 
// right to left
                                 eg:7,9,5,8,1,3 n=2
sum of 2 minimum no                 -1,16,12,12,6,4
                                    17,17,13,11,4,-1 sum of 2 maximum number
// the possible solution can be 16-13,12-11,12-4 as the sum of two element from the left part - two elements from the right part
// if we consider 6-(-1)not possible as the second array also should be sum of two but there are no w number to add so -1and one more thing why
// can't we subtract from same row eg;16-17 as the question says the array is divided into two equal parts then we should take sum of left part and 
// then sum of right part they cannot be common 
// as the possible solution are 16-13,12-11,12-4  we start the for loop from n-1 to n*2 as the solution starts from adding n numbers from left 
// part thats why we start from n-1 so that the first element is the sum of the n numbers -1 because we are starting index from 0
// and end with n*2 bcz we have to consider n elements from the right side and the possible solution will end before n*2 
// as we have n*3 in which n is deleted and n elements are added to the left part and the rest is  incorporate to the
// right part orelse we cannot accompany the right part
class Solution {
public:
#define ll long long
    long long minimumDifference(vector<int>& nums) {
        int n=nums.size()/3;
        vector<ll>prefix(nums.size(),-1),suffix(nums.size(),-1);
        //prefix[i]=sum of first n minimum valued elements from left side
        //suffix[i]=sum of first n maximum valued elements from right side
        ll sum=0;//min n elements sum
        priority_queue<ll> pq;//max heap
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            pq.push(nums[i]);
            //pop out max elements
            //calculating sum of minimum numbers by removing the maximum number
            if(pq.size()>n){
                sum-=pq.top();
                pq.pop();
            }
            if(pq.size()==n){
                prefix[i]=sum;
            }

        }
        sum=0;
        priority_queue<ll,vector<ll>,greater<ll>>pq2;
        for(int i=nums.size()-1;i>=0;i--){
            sum+=nums[i];
            pq2.push(nums[i]);
            //pop out min elements
            if(pq2.size()>n){
                sum-=pq2.top();
                pq2.pop();
            }
            if(pq2.size()==n){
                suffix[i]=sum;
            }
        }
        ll ans=LONG_LONG_MAX;
        for(int i=n-1;i<n*2;i++){
            ans=min(ans,prefix[i]-suffix[i+1]);
        }
        return ans;
    }
};
