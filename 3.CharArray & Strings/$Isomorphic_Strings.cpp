// https://leetcode.com/problems/isomorphic-strings/description/
// Given two strings s and t, determine if they are isomorphic.

// Two strings s and t are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

// Example 1:

// Input: s = "egg", t = "add"
// Output: true
// Example 2:

// Input: s = "foo", t = "bar"
// Output: false
// Example 3:

// Input: s = "paper", t = "title"
// Output: true
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int hash[256]={0};//mapping each char of s to t
        bool isSecondCharsMapped[256]={0};//stores if t is already mapped with s
        for(int i=0;i<s.length();i++){
            if(hash[s[i]]==0&& isSecondCharsMapped[t[i]]==0){
                hash[s[i]]=t[i];
                isSecondCharsMapped[t[i]]=true;
            }
        }
         for(int i=0;i<s.length();i++){
            if(char(hash[s[i]])!=t[i]){
                return false;
            }
        }
        return true;


    }
};
