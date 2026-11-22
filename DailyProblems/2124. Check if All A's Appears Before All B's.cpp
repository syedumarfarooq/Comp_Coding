*//My solution using stack
class Solution {
public:
    bool checkString(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a'&&!st.empty()){
                return false;
            }
            else if(s[i]=='b'){
                st.push(s[i]);
            }

        }
        return true;
            
    }
};
*//using array
class Solution {
public:
    bool checkString(string s) {
        for(int i=1;i<s.length();i++){
            if(s[i]=='a'&&s[i-1]=='b')return false;
        }
        return true;
    }
};
*//another approach
class Solution {
public:
    bool checkString(string s) {
        bool bflag=false;
        for(int i=0;i<s.length();i++){
            if(s[i]=='b'){
                 bflag=true;
            }else if(s[i]=='a'&&bflag==true){
                return false;
            }
        }
        return true;
            
    }
};

*// other multiple arroaches can be
// 1.is to find the index of last occurance of a and index of first occurance of b if alast index< b first index then valid
// 2.is to find the a patter in the string or substring have ab as the substring O(n*2) it goes to every index and check the substring which is of 
// length 2
// 3.is to check if the string is sorted if it is sorted then it will have all a's before b
