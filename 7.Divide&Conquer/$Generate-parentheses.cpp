https://leetcode.com/problems/generate-parentheses/description/
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// Example 2:

// Input: n = 1
// Output: ["()"]
 

// Constraints:

// 1 <= n <= 8
//   USING RECURSION 
//     class Solution {
// public:
//     void solve(vector<string>& ans,int n,int open,int close,string output){
//         if(open<=0&&close<=0){
//             ans.push_back(output);
//             return;
//         }
//         if(open>0){
//             solve(ans,n,open-1,close,output+"(");
//         }
//         if(close>open){
//             solve(ans,n,open,close-1,output+")");
//         }
        
        
//     }
//     vector<string> generateParenthesis(int n) {
//         vector<string> ans;
//         int open=n;
//         int close=n;
//         string output="";
//         solve(ans,n,open,close,output);
//         return ans;
//     }
// };
*//************************************************************************************************************************
  USING BACKTRACKING
  class Solution {
public:
    void solve(vector<string>& ans,int n,int open,int close,string output){
        if(open<=0&&close<=0){
            ans.push_back(output);
            return;
        }
        if(open>0){
            output.push_back('(');
            solve(ans,n,open-1,close,output);
            output.pop_back();
        }
        if(close>open){
            output.push_back(')');
            solve(ans,n,open,close-1,output);
            output.pop_back();
        }
        
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int open=n;
        int close=n;
        string output="";
        solve(ans,n,open,close,output);
        return ans;
    }
};
