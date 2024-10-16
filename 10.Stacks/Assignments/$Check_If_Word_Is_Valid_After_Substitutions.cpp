https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/description/
// Given a string s, determine if it is valid.

// A string s is valid if, starting with an empty string t = "", you can transform t into s after performing the following operation any number of times:

// Insert string "abc" into any position in t. More formally, t becomes tleft + "abc" + tright, where t == tleft + tright. Note that tleft and tright may be empty.
// Return true if s is a valid string, otherwise, return false.

 

// Example 1:

// Input: s = "aabcbc"
// Output: true
// Explanation:
// "" -> "abc" -> "aabcbc"
// Thus, "aabcbc" is valid.
*//Solution 1*********
//   class Solution {
// public:
//     bool isValid(string s) {
//         if(s.size()==0){
//             return true;
//         }
//         int fnd=s.find("abc");
//         if(fnd!=string::npos){
//             string tleft=s.substr(0,fnd);
//             string tright=s.substr(fnd+3,s.size());
//             return isValid(tleft+tright);
//         }
//         return false;
//     }
// };
  *//Solution 2 optimised*********
 class Solution {
public:
    bool isValid(string s) {
        if(s[0]!='a'){
            return false;
        }
        stack<char> st;
        for(char ch:s){
            if(ch=='a'){
                st.push('a');
            }
            else if(ch=='b'){
                if(!st.empty()&&st.top()=='a'){
                    st.push('b');
                }else{
                    return false;
                }
            }else{
                if(!st.empty()&&st.top()=='b'){
                    st.pop();
                    if(!st.empty()&&st.top()=='a'){
                        st.pop();
                    }else{
                        return false;
                    }
                }else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};
 
