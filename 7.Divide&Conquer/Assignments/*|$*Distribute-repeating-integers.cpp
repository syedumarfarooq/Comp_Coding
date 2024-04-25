https://leetcode.com/problems/distribute-repeating-integers/description/
// You are given an array of n integers, nums, where there are at most 50 unique values in the array. You are also given an array of m customer order quantities, quantity, where quantity[i] is the amount of integers the ith customer ordered. Determine if it is possible to distribute nums such that:

// The ith customer gets exactly quantity[i] integers,
// The integers the ith customer gets are all equal, and
// Every customer is satisfied.
// Return true if it is possible to distribute nums according to the above conditions.

 

// Example 1:

// Input: nums = [1,2,3,4], quantity = [2]
// Output: false
// Explanation: The 0th customer cannot be given two different integers.
// Example 2:

// Input: nums = [1,2,3,3], quantity = [2]
// Output: true
// Explanation: The 0th customer is given [3,3]. The integers [1,2] are not used.
// Example 3:

// Input: nums = [1,1,2,2], quantity = [2,2]
// Output: true
// Explanation: The 0th customer is given [1,1], and the 1st customer is given [2,2].
 

// Constraints:

// n == nums.length
// 1 <= n <= 105
// 1 <= nums[i] <= 1000
// m == quantity.length
// 1 <= m <= 10
// 1 <= quantity[i] <= 105
// There are at most 50 unique values in nums.
class Solution {
public:
    bool canDistributeHelper(vector<int>& counts, vector<int>& quantity,int ithCustomer){
        if(ithCustomer==quantity.size()){
            return true;
        }
        for(int i=0;i<counts.size();i++){
            if(counts[i]>=quantity[ithCustomer]){
                counts[i]-=quantity[ithCustomer];
                if(canDistributeHelper(counts,quantity,ithCustomer+1)){
                    return true;
                }
                counts[i]+=quantity[ithCustomer];
            }
        }
        return false;
    }
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int,int> countMap;
        for(auto num:nums){
            countMap[num]++;
        }
        vector<int> counts;
        for(auto it:countMap){
            counts.push_back(it.second);
        }
        sort(quantity.rbegin(),quantity.rend());//sort DESC.
        //if the quantity is arranged in descending order then we can reach to 
        //conclusion faster as if the first quatity that is the biggest quantity
        //is not satified then it all customer cannot be distributed
        return canDistributeHelper(counts,quantity,0);
    }
};
