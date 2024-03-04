// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

// Example 1:

// Input: haystack = "sadbutsad", needle = "sad"
// Output: 0
// Explanation: "sad" occurs at index 0 and 6.
// The first occurrence is at index 0, so we return 0.
// Example 2:

// Input: haystack = "leetcode", needle = "leeto"
// Output: -1
// Explanation: "leeto" did not occur in "leetcode", so we return -1.
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.length();
        int m=needle.length();
        for(int i=0;i<=n-m;i++){
            for(int j=0;j<m;j++){
                if(haystack[i+j]!=needle[j]){
                    break;
                }
                if(j==m-1){
                    return i;
                }
            }
        }
        return -1;
    }
};
//Time complexity:O((n-m+1)*m))=>m*n>m^2
                //   O(mn)                  
