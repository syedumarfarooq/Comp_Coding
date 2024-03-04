// https://leetcode.com/problems/longest-palindromic-substring/
// Given a string s, return the longest 
// palindromic substring in s.

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.
// Example 2:

// Input: s = "cbbd"
// Output: "bb"
// ---------------CAN BE SOLVED USING DYNAMIC PROGRAMING---------------
class Solution {
public:
    bool isPalindrome(string& s,int start,int end){//& is used to send the string by reference(not clear will learn in later time)

        while(start<end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
            
        }
        return true;
    }
    string longestPalindrome(string s) {
        string ans="";
        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                if(isPalindrome(s,i,j)){
                    string t=s.substr(i,j-i+1);
                    ans=t.length()>ans.length() ? t : ans;
                }
            }
        }
        return ans;
    }
};
// Time Complexity:O(N^3) can be reduced to O(N^2) in Dynamic Programming
