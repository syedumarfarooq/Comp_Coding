// https://leetcode.com/problems/climbing-stairs/
// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

// Example 1:

// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps
// Example 2:

// Input: n = 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step
//Solution correct but time limit exceeded will be taught in exponential time
class Solution {
public:
    int climbStairs(int n) {
        if(n==1||n==0){
            return 1;//in this the 0th stair can be reached in 1 way not 0, so n==0 return 1; if n==0 returns 0 then the way to reach 0th stair will 0 and that we will be a false statement there must be a way to reach to 0th stair so that the next stairs can be reached
        }
        return climbStairs(n-1)+climbStairs(n-2); // in this to reach final stair either u have to be on n-1 or n-2 as it can jump only one or two stairs so we add the combination of  n-1 and n-2
    }
};
