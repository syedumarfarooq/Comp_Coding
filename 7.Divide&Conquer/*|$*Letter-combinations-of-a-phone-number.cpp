https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// Example 2:

// Input: digits = ""
// Output: []
// Example 3:

// Input: digits = "2"
// Output: ["a","b","c"]
class Solution {
public:
    void solve(vector<string>& ans,vector<string>& mapping,string digits,int index,string output ){
        if(index>=digits.length()){
            ans.push_back(output);
            return;
        }
        int digit=digits[index]-'0';
        string value=mapping[digit];
        for(int i=0;i<value.length();i++){
            output.push_back(value[i]);
            solve(ans,mapping,digits,index+1,output);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0){
            return ans;
        }
        vector<string> mapping(10);
        mapping[2]="abc";
        mapping[3]="def";
        mapping[4]="ghi";
        mapping[5]="jkl";
        mapping[6]="mno";
        mapping[7]="pqrs";
        mapping[8]="tuv";
        mapping[9]="wxyz";
        string output="";
        int index=0;
        solve(ans,mapping,digits,index,output);
        return ans;
    }
};
Time Complexity:O(4^N)
Space Complexity:O(4^N)as ans can contain 4^N strings 
