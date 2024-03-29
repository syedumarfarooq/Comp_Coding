// https://leetcode.com/problems/perfect-squares/description/
// Given an integer n, return the least number of perfect square numbers that sum to n.

// A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

 

// Example 1:

// Input: n = 12
// Output: 3
// Explanation: 12 = 4 + 4 + 4.
// Example 2:

// Input: n = 13
// Output: 2
// Explanation: 13 = 4 + 9.
TIME EXCEEDED 
  class Solution {
public:
    int numSquareHelper(int n){
        if(n<=0){
            return 0;
        }
        int i=1;
        int ans=INT_MAX;
        int end=sqrt(n);
        while(i<=end){
            int perfectsquare=i*i;
            int numberofPerfectSquare=1+numSquareHelper(n-perfectsquare);//as it has to count every numsquare that is used to make n we add 1 in every step to count number of perfectsquare added to make n 
            if(numberofPerfectSquare<ans){
                ans=numberofPerfectSquare;
            }
            i++;
            
        }
        return ans;
    }
    int numSquares(int n) {
        return numSquareHelper(n);
    }
};
Time Complexity:O(sqrt(n)^n){//as in fibonacci n is divided into 2 division every time so 2^n in this it is divided into sqrt n times 
Space Complexiy:O(n)//as the maximum depth is going is n times in worst case
