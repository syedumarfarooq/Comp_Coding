https://www.geeksforgeeks.org/problems/count-the-reversals0401/1
// Given a string S consisting of only opening and closing curly brackets '{' and '}', find out the minimum number of reversals required to convert the string into a balanced expression.
// A reversal means changing '{' to '}' or vice-versa.

// Example 1:

// Input:
// S = "}{{}}{{{"
// Output: 3
// Explanation: One way to balance is:
// "{{{}}{}}". There is no balanced sequence
// that can be formed in lesser reversals.
// Example 2:

// Input: 
// S = "{{}{{{}{{}}{{"
// Output: -1
// Explanation: There's no way we can balance
// this sequence of braces.
int countRev (string s)
{
    //if odd sized string then impossible to make poirs
    if(s.length()&1)return -1;
    stack<char> st;
    int ans=0;
    for(char ch:s){
        if(ch=='{'){
            st.push(ch);
        }else{
            if(!st.empty()&&st.top()=='{'){
              st.pop();
            }else{
                st.push(ch);
            }
        }
    }
    //if stack is still not empty then lets count the reversible
    while(!st.empty()){
        char a=st.top();
        st.pop();
        char b=st.top();
        st.pop();
        if(a==b){
            ans+=1;
        }else{
            ans+=2;
        }
    }
    return ans;
}
