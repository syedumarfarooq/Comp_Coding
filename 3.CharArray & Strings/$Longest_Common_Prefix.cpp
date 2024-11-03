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
*//another solution similar but used for loop*
class Solution{
    public:
     string longestCommonPrefix(vector<string>& strs) {
            string ans="";
            //loop on first string
            for(int i=0; i<strs[0].length(); i++) {
                char ch = strs[0][i];
                bool match = true;
    
                //compare this charachter with alll 
                //the remaining strings at the same index
                for(int j=1; j<strs.size(); j++  ) {
                    //compare
                    if(strs[j].size() < i || ch != strs[j][i]) {
                        match = false;
                        break;
                    }
                }
    
                if(match == false)
                    break;
                else
                    ans.push_back(ch);
            }
            return ans;
        }
};
