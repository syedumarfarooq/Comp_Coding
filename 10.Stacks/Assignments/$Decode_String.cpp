https://leetcode.com/problems/decode-string/description/
// Given an encoded string, return its decoded string.

// The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

// You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

// The test cases are generated so that the length of the output will never exceed 105.

 

// Example 1:

// Input: s = "3[a]2[bc]"
// Output: "aaabcbc"
// Example 2:

// Input: s = "3[a2[c]]"
// Output: "accaccacc"
class Solution {
public:
    string decodeString(string s) {
        stack<string>st;
        for(char ch:s){
            if(ch==']'){
                string stringToRepeat="";
                while(!st.empty()&&st.top()!="["){
                    string top=st.top();
                    stringToRepeat+=top;
                    st.pop();
                }
                st.pop();//removing the [ 
                string numericTimes="";
                while(!st.empty()&&isdigit(st.top()[0])){
                    numericTimes+=st.top();
                    st.pop();
                }
                reverse(numericTimes.begin(),numericTimes.end());
                int n=stoi(numericTimes);
                string currentdecode="";
                while(n--){
                    currentdecode+=stringToRepeat;
                }
                st.push(currentdecode);
            }else{
                string temp(1,ch);//1 is the number of time it should repeat
                st.push(temp);
            }
        }
        string ans;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
