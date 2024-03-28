// https://leetcode.com/problems/wildcard-matching/
// Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).

 

// Example 1:

// Input: s = "aa", p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".
// Example 2:

// Input: s = "aa", p = "*"
// Output: true
// Explanation: '*' matches any sequence.
// Example 3:

// Input: s = "cb", p = "?a"
// Output: false
// Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
TIME LIMIT EXCEEDED USE DYNAMIC PROGRAMMING SOLVED USING RECURSION TO LEARN RECURSION
class Solution {
public:
bool isMatchHelper(string& s,int si,string& p,int pi){
    //single char matching
    if(si>=s.size()&&pi>=p.size()){
        return true;
    }
    //if the s is fully traveserd and only * is left in p then it will show true else false
    if(si==s.size()&&pi<p.size()){
        while(pi<p.size()){
            if(p[pi]!='*'){
                
                return false;
            }
            pi++;
        }
        return true;
    }
    if(s[si]==p[pi]||p[pi]=='?'){
        isMatchHelper(s,si+1,p,pi+1);
    }
    if(p[pi]=='*'){
        //treat * as empty or null
        bool caseA=isMatchHelper(s,si,p,pi+1);
        //let * consume on character
        bool caseB=isMatchHelper(s,si+1,p,pi);
        return caseA||caseB;
    }
    //char does'nt match
    return false;
}
    bool isMatch(string s, string p) {
        int si=0;
        int pi=0;
        return isMatchHelper(s,si,p,pi);

    }
};
Time Complexity:O(2^N)}//same as fibonacci as the function is checking for * is empty and consume a character in the worst case there might a *
 //because of 2^n it goes exponential as there are 2 calls in one function
Space complexity:O(n)//was told that maximum dept of a recursion function or max no of recursive call can determine the space complexity
