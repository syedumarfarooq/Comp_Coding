// https://leetcode.com/problems/longest-common-prefix/description/
// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".
// Example 1:

// Input: strs = ["flower","flow","flight"]
// Output: "fl"
// Example 2:

// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i=0;
        string ans="";
        while(true){
            int currentChar=0;
            for(auto str:strs){
                if(i>=str.size()){
                    //out of bound
                    currentChar=0;
                    break;
                }
                if(currentChar==0){
                    currentChar=str[i];
                }
                else if(currentChar!=str[i]){
                    currentChar=0;
                    break;
                }
            }
            if(currentChar==0){
                break;
            }
            ans.push_back(currentChar);
            i++;
        }
        return ans;
    }
};
