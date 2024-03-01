// https://leetcode.com/problems/palindromic-substrings/description/
// Given a string s, return the number of palindromic substrings in it.
// A string is a palindrome when it reads the same backward as forward.
// A substring is a contiguous sequence of characters within the string.
// Example 1:

// Input: s = "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".
// Example 2:

// Input: s = "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
class Solution {
public:
    int expandArountIndex(string s,int i,int j){
        int count=0;
        while((i>=0&&j<=s.length()-1)&&s[i]==s[j]){
            count++;
            i--;
            j++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int totalCount=0;
        for(int i=0;i<s.length();i++){
            int odd=expandArountIndex(s,i,i);
            totalCount+=odd;
            int even=expandArountIndex(s,i,i+1);
            totalCount+=even;

        }
        return totalCount;
    }
};
