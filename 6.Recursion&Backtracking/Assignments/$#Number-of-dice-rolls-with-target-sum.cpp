// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
// You have n dice, and each dice has k faces numbered from 1 to k.

// Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll the dice, so the sum of the face-up numbers equals target. Since the answer may be too large, return it modulo 109 + 7.

 

// Example 1:

// Input: n = 1, k = 6, target = 3
// Output: 1
// Explanation: You throw one die with 6 faces.
// There is only one way to get a sum of 3.
// Example 2:

// Input: n = 2, k = 6, target = 7
// Output: 6
// Explanation: You throw two dice, each with 6 faces.
// There are 6 ways to get a sum of 7: 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.
// Example 3:

// Input: n = 30, k = 30, target = 500
// Output: 222616187
// Explanation: The answer must be returned modulo 109 + 7.
TIME LIMIT EXCEEDED USING DYNAMIC PROGRAMMING
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {//think n a s no of chances to roll the dice the first time you get k different answer and next time k ans till the no of chances are zero
        if(target<0)return 0;
        if(target==0&&n==0)return 1;
        if(n==0&&target!=0)return 0;
        if(n!=0&&target==0)return 0;
        int ans=0;
        for(int i=1;i<=k;i++){//i=1 because we have to minus it from target
            ans+=numRollsToTarget(n-1,k,target-i);
        }
        return ans;
    }
};
Time Complexity:O(k^n)
Space Complexity:O(n)
