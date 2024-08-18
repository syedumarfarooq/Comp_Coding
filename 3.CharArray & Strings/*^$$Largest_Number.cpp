// https://leetcode.com/problems/largest-number/description/
// Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

// Since the result may be very large, so you need to return a string instead of an integer.

 

// Example 1:

// Input: nums = [10,2]
// Output: "210"
// Example 2:

// Input: nums = [3,30,34,5,9]
// Output: "9534330"
class Solution {
public:
    static bool cmp(string a,string b){//we are using t1 and t2 to handle a case where the sort function tells 30>3 but in this solution we need to find the largest eg:30,3 it gives 303 but303<330  so we have to make changes in the cmp so that 330>303 so we take t1 and t2 and combine them and it places them in such order where t1>t2 in that 330 >303
      //at last it return whoever is the greatest first as first>second condition given in the return 
        string t1=a+b;
        string t2=b+a;
        return t1>t2;
    }
    string largestNumber(vector<int>& nums) {
        vector<string>snums;
        for(auto n:nums){
            snums.push_back(to_string(n));
        }
     //in strings sorting is done in lexicographically that is alphabatically if "ab" and "ac" are to be sorted in descending order
     //it first compares the first character as both are same then the second as c is greater and has higher value is ascii table
     //ac>ab
        sort(snums.begin(),snums.end(),cmp);
        if(snums[0]=="0")return "0";
        string ans="";
        for(auto str:snums){
            ans+=str;
        }
        return ans;
    }
};
