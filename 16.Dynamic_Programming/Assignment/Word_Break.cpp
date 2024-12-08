https://leetcode.com/problems/word-break/
// Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

// Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

// Example 1:

// Input: s = "leetcode", wordDict = ["leet","code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".
*//logic
//   in this we are adding every letter of s into a new string and check if it is present in the dictionary and then letting recursion check 
// from next character eg: s="aaaaaaa" wordDict=["aaa","aaaa"] in this if add 3 a in first and check we will get true and then for then next 4 
//   a's if we check if we add only 3 that comes true then one a is left we might get false for this reason in every function we iterate
//   through every character and check and make all possible solution by doing this for the above example we check for 3 a's and 4 a's in the
// same function then there are 4 and 3 a's left respectively then for the 4 a's part we check 3 a's and 4 a's which both will return true
// and then for 3a's part it will directly return true
*//solve using recursion
  class Solution {
public:
    bool check( vector<string>& wordDict,string word){
        for(auto i:wordDict){
            if(word==i){
                return true;
            }
        }
        return false;
    }
    bool solve(string s, vector<string>& wordDict,int start){
        if(start==s.size())return true;
        string word="";
        bool flag=false;
        for(int i=start;i<s.size();i++){
            word+=s[i];
            if(check(wordDict,word)){
                flag=flag||solve(s,wordDict,i+1);
            }
        }
        return flag;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        return solve(s,wordDict,0);
    }
};
*//solved using memoisation
class Solution {
public:
    bool check( vector<string>& wordDict,string word){
        for(auto i:wordDict){
            if(word==i){
                return true;
            }
        }
        return false;
    }
    bool solveMem(string s, vector<string>& wordDict,int start,vector<int>&dp){
        if(start==s.size())return true;
        if(dp[start]!=-1){
            return dp[start];
        }
        string word="";
        bool flag=false;
        for(int i=start;i<s.size();i++){
            word+=s[i];
            if(check(wordDict,word)){
                flag=flag||solveMem(s,wordDict,i+1,dp);
            }
        }
        dp[start]=flag;
        return dp[start];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.size(),-1);
        return solveMem(s,wordDict,0,dp);
    }
};
*//solved using tabulation
class Solution {
public:
    bool check( vector<string>& wordDict,string word){
        for(auto i:wordDict){
            if(word==i){
                return true;
            }
        }
        return false;
    }
    bool solveTab(string s, vector<string>& wordDict){
        vector<int>dp(s.size()+1,true);//used true here intentionally or else it wont work 
     //as it start from check last character and slowly increases the length of the start so when the some word matches in dictionay
     //it check dp[i+1] if we place false while intialising it will show false
        for(int start=s.size()-1;start>=0;start--){
            string word="";
            bool flag=false;
            for(int i=start;i<s.size();i++){
                word+=s[i];
                if(check(wordDict,word)){
                    flag=flag||dp[i+1];
                }
            }
            dp[start]=flag;
        }
        
        return dp[0];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        return solveTab(s,wordDict);
    }
};
*//space optimisation not possible
