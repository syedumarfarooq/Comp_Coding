https://leetcode.com/problems/interleaving-string/
// Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

// An interleaving of two strings s and t is a configuration where s and t are divided into n and m 
// substrings
//  respectively, such that:

// s = s1 + s2 + ... + sn
// t = t1 + t2 + ... + tm
// |n - m| <= 1
// The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
// Note: a + b is the concatenation of strings a and b.
//   Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
// Output: true
// Explanation: One way to obtain s3 is:
// Split s1 into s1 = "aa" + "bc" + "c", and s2 into s2 = "dbbc" + "a".
// Interleaving the two splits, we get "aa" + "dbbc" + "bc" + "a" + "c" = "aadbbcbcac".
// Since s3 can be obtained by interleaving s1 and s2, we return true.
*//logic
  // in this we pointer for each string i,j,k we will match any string 1 or 2 with 3 until they match then stiff to another string and 
// one after the other we try to completely match s3 eg;s1 matches with s3 we iteratie i and k if the next character in s3 i.e k not matches i
// then we try to match it with s2 i.e j so if all the pointers reach end that means s3 is formed by interleaving of s1 and s2
  //eg;s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac" we start match s1 with s3 until aa after that it is not equal so we try to match it with
  // s2 so dbbc is matched similarly we do for the rest alternatively until all the s1,s2 and s3 are iterated that means s3 is made of
// interleaving of s1 and s2
*//solved using recursion
class Solution {
public:
    bool solve(string &s1, string& s2, string &s3,int i,int j,int k){
        if(i==s1.size()&&j==s2.size()&&k==s3.size()){
            return true;
        }
        bool flag=false;
        if(i<s1.size()&&s1[i]==s3[k]){//when we try to acces s1[i] it should be a valid and within the size()
            flag=flag||solve(s1,s2,s3,i+1,j,k+1);
        }
        if(j<s2.size()&&s2[j]==s3[k]){//when we try to acces s2[j] it should be a valid and within the size()
            flag=flag||solve(s1,s2,s3,i,j+1,k+1);
        }
        return flag;
    }
    bool isInterleave(string s1, string s2, string s3) {
        return solve(s1,s2,s3,0,0,0);
    }
};
*//solved using memoisation
class Solution {
public:
    bool solveMem(string &s1, string& s2, string &s3,int i,int j,int k,vector<vector<vector<int>>>&dp){
        if(i==s1.size()&&j==s2.size()&&k==s3.size()){
            return true;
        }
        if(dp[i][j][k]!=-1){
            return dp[i][j][k];
        }
        bool flag=false;
        if(i<s1.size()&&s1[i]==s3[k]){
            flag=flag||solveMem(s1,s2,s3,i+1,j,k+1,dp);
        }
        if(j<s2.size()&&s2[j]==s3[k]){
            flag=flag||solveMem(s1,s2,s3,i,j+1,k+1,dp);
        }
        dp[i][j][k]=flag;
        return dp[i][j][k];
    }
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<vector<int>>>dp(s1.size()+1,vector<vector<int>>(s2.size()+1,vector<int>(s3.size()+1,-1)));
      //from the ith and jth index can we interleave string and match s3 from k
        return solveMem(s1,s2,s3,0,0,0,dp);
    }
};
*//solve using tabulation
class Solution {
public:
    int solveTab(string &s1, string& s2, string &s3){
        vector<vector<vector<int>>>dp(s1.size()+1,vector<vector<int>>(s2.size()+1,vector<int>(s3.size()+1,0)));
        dp[s1.size()][s2.size()][s3.size()]=1;//base condition
        for(int i=s1.size();i>=0;i--){//y from s1.size not from s1.size()-1 eg: Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
          //as we match aa from s1, ddbbc from s2,then bc from s1 ,then a from s2 and the s2 has reached its end but not s1 and s3 so 
          //for this case where dp[not ended][ended][not ended] so we start from s.size() to make all combination
            for(int j=s2.size();j>=0;j--){
                for(int k=s3.size();k>=0;k--){
                    bool flag=false;
                    if(i==s1.size()&&j==s2.size()&&k==s3.size())continue;//this is same as base condition so we are skipping this
                    if(i<s1.size()&&s1[i]==s3[k]){
                        flag=flag||dp[i+1][j][k+1];
                    }
                    if(j<s2.size()&&s2[j]==s3[k]){
                        flag=flag||dp[i][j+1][k+1];
                    }
                    dp[i][j][k]=flag;
                }
            }
        }
        
        return dp[0][0][0];
    }
    bool isInterleave(string s1, string s2, string s3) {
        
        return solveTab(s1,s2,s3);
    }
};
