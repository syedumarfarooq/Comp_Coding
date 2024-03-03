// https://leetcode.com/problems/valid-anagram/description/
// Given two strings s and t, return true if t is an anagram of s, and false otherwise.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
// Example 1:
// Input: s = "anagram", t = "nagaram"
// Output: true
// Example 2:

// Input: s = "rat", t = "car"
// Output: false
// --------MY SOLUTION/LOGIC---------
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         sort(s.begin(),s.end());
//         sort(t.begin(),t.end());
//         int n=max(s.length(),t.length());
//         for(int i=0;i<n;i++){
//             if(s[i]!=t[i]){
//                 return false;
//             }
//         }
//         return true;
//     }
// };
