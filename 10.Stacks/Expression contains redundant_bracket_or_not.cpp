https://www.geeksforgeeks.org/problems/expression-contains-redundant-bracket-or-not/0
// Given a string of balanced expression str, find if it contains a redundant parenthesis or not. A set of parenthesis are redundant if the same sub-expression is surrounded by unnecessary or multiple brackets. Return 1 ifit contains a redundant parenthesis, else 0.
// Note: Expression may contain + , - , *, and / operators. Given expression is valid and there are no white spaces present.

// Example 1:

// Input:
// exp = ((a+b))
// Output:
// Yes
// Explanation:
// ((a+b)) can reduced to (a+b).
class Solution {
  public:
    int checkRedundancy(string s) {
        // code here
        stack<char> st;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            
            if(ch=='('||ch=='+'||ch=='-'||ch=='/'||ch=='*'){
                st.push(ch);
            }else if(ch==')'){
                bool hasOperator = false;

                // Pop the elements from the stack and check for an operator
                while (!st.empty() && st.top() != '(') {
                    char top = st.top();
                    st.pop();
                    if (top == '+' || top == '-' || top == '*' || top == '/') {
                        hasOperator = true;  // Found an operator
                    }
                }

                // If we reach an open bracket '(' but no operator was found, it's redundant
                if (!hasOperator) {
                    return 1;
                }

                // Pop the opening bracket '(' as well
                if (!st.empty()) {
                    st.pop();
                }
                
                
            }
        }
        return 0;
                
        
        
        
    }
};
