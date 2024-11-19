https://leetcode.com/problems/longest-palindromic-subsequence/description/
// Given a string s, find the longest palindromic subsequence's length in s.

// A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

// Example 1:

// Input: s = "bbbab"
// Output: 4
// Explanation: One possible longest palindromic subsequence is "bbbb".
// Example 2:

// Input: s = "cbbd"
// Output: 2
// Explanation: One possible longest palindromic subsequence is "bb".
*//Logic
  // as we did learn in longest common subsequence between two strings then for this we we reverse the same string and check the longest common
// subsequence between the original string and reverse string then it is the longest palindromic subsequence 
  class Solution {
public:
int solveUsingTabSO(string a, string b) {//code from https://github.com/syedumarfarooq/Comp_Coding/blob/main/16.Dynamic_Programming/9.*%7C%24*Longest_Common_Subsequence.cpp
        //vector<vector<int> > dp(a.length()+101, vector<int>(b.length()+129, 0));
        vector<int> curr(b.length()+1, 0);
        vector<int> next(b.length()+1, 0);

        for(int i = a.length()-1; i>=0; i--) {
            for(int j = b.length()-1; j>=0; j--) {
                int ans = 0;
                if(a[i] == b[j])
                    ans =  1 + next[j+1];
                else {
                    ans =  0 + max(curr[j+1], next[j]);
                }
                curr[j] =  ans;      
            }
            //shift
            next = curr;
        }
        return next[0];
    }
    int longestPalindromeSubseq(string s) {
        string first=s;
        reverse(s.begin(),s.end());
        string second=s;
        return solveUsingTabSO(first,second);
    }
};
