https://www.geeksforgeeks.org/problems/the-celebrity-problem/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
// A celebrity is a person who is known to all but does not know anyone at a party. A party is being organized by some people.  A square matrix mat is used to represent people at the party such that if an element of row i and column j is set to 1 it means ith person knows jth person. You need to return the index of the celebrity in the party, if the celebrity does not exist, return -1.

// Note: Follow 0-based indexing.

// Examples:

// Input: mat[][] = [[0 1 0],
//                 [0 0 0], 
//                 [0 1 0]]
// Output: 1
// Explanation: 0th and 2nd person both know 1. Therefore, 1 is the celebrity. 
int celebrity(vector<vector<int> >& mat) {
        stack<int> st;
        //push all persons into the stack
        for(int i=0;i<mat.size();i++){
            st.push(i);
        }
        while(st.size()!=1){
            int a=st.top();st.pop();
            int b=st.top();st.pop();
            //if a know b
            if(mat[a][b]){
                //a is not a celebrity
                st.push(b);
            }else{
                //b is not a celebrity
                st.push(a);
            }
        }
        //check if the single person is actually a celebrity
        int mightBeCelebrity=st.top(); st.pop();
        //celebrity should not know anyone
        for(int i=0;i<mat.size();i++){
            if(mat[mightBeCelebrity][i]){
                return -1;
            }
        }
        //everyone should know celebrity
        for(int i=0;i<mat.size();i++){
            if(mat[i][mightBeCelebrity]==0&&i!=mightBeCelebrity){
                return -1;
            }
        }
        // mightbecelebrity is celebrity
        return mightBeCelebrity;
