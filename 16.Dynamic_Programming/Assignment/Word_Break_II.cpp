https://leetcode.com/problems/word-break-ii/
// Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.
// Note that the same word in the dictionary may be reused multiple times in the segmentation.
// Example 1:

// Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
// Output: ["cats and dog","cat sand dog"]
// Example 2:

// Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
// Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
// Explanation: Note that you are allowed to reuse a dictionary word.
*//logic
  // we are iterating from i to end and adding each character and checking and if we get a valid word we let recursion find all the valid
//words in front of it and store it in right as there are multiple string inside the vector
// eg;Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
// if the word is pine the right part will contain endpart ["apple pen apple","applepen apple"] two different combination we take each part
// add space in between the word and endPart and push_back it into the ans
  *//this question is can be solved using tries
*//solve using recursion
  class Solution {
public:
    vector<string> solve(string& s, unordered_map<string,bool>&dict,int i){
        if(i==s.size())return {""};
        vector<string>ans;
        string word;
        for(int j=i;j<s.size();j++){
            word.push_back(s[j]);
            if(dict.find(word)==dict.end())continue;
            //found a valid word
            auto right=solve(s,dict,j+1);
            for(auto eachRightPart:right){//right contains all the possible words of string s starting from j+1
            string endPart;
            if(eachRightPart.size()>0) endPart=" "+eachRightPart;
            ans.push_back(word+endPart);
            }
        }
        return ans;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool>dict;
        for(auto word:wordDict) dict[word]=1;//storing this in map to easily find a word is a valid word
        return solve(s,dict,0);
    }
};
*//solve using memoisation
class Solution {
public:
    vector<string> solveMem(string& s, unordered_map<string,bool>&dict,int i,unordered_map<int,vector<string>>&dp){
        if(i==s.size())return {""};
        if(dp.find(i)!=dp.end())return dp[i];
        vector<string>ans;
        string word;
        for(int j=i;j<s.size();j++){
            word.push_back(s[j]);
            if(dict.find(word)==dict.end())continue;
            //found a valid word
            auto right=solveMem(s,dict,j+1,dp);
            for(auto eachRightPart:right){//right contains all the possible words of string s starting from j+1
            string endPart;
            if(eachRightPart.size()>0) endPart=" "+eachRightPart;
            ans.push_back(word+endPart);
            }
        }
        dp[i]=ans;
        return dp[i];
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool>dict;
        for(auto word:wordDict) dict[word]=1;//storing this in map to easily find a word is a valid word
        unordered_map<int,vector<string>>dp;//for every starting point i there is a vector of string
        return solveMem(s,dict,0,dp);
    }
};
