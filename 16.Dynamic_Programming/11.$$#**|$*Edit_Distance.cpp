https://leetcode.com/problems/edit-distance/
// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

// You have the following three operations permitted on a word:

// Insert a character
// Delete a character
// Replace a character
 

// Example 1:

// Input: word1 = "horse", word2 = "ros"
// Output: 3
// Explanation: 
// horse -> rorse (replace 'h' with 'r')
// rorse -> rose (remove 'r')
// rose -> ros (remove 'e')
*//logic
//   we have two pointer i and j one in each word if they match they we move forward and let the recursion do its work if it does not match
//   we can insert, delete or replace if we insert in word1 then we move only the j pointer and i stays there 
// if we delete we move that i forward j remains the same
// if we replace we move both pointer
// for every operation we do we add 1 so at last we take the minimum out of these three which give least operation to match word1 with word2
  *//solve using recursion
  class Solution {
public:
    int solveUsingRecursion(string a,string b,int i,int j){
        if( i == a.length()) {//if i goes out of bound and there are still elements left in b then we will need the operation equal to 
          //number of elements left that is to insert that many elements 
          //if both i and j ends then it will return 0 as there are no elements left b.length()-j will be zero as j has iterated to last
            return b.length()-j;
        }

        if(j == b.length()) {//if j goes out of bound and there are elements left in a then we have to delete the remaining elements
          // to match it with string b so we return a.length()-i that is the remaining length
          //if both i and j ends then it will return 0 as i has reached to the end 
            return a.length()-i;
        }
        int ans=0;
        if(a[i]==b[j]){
            ans=solveUsingRecursion(a,b,i+1,j+1);//if it matches no need for any operation
        }else{
            int insert=1+solveUsingRecursion(a,b,i,j+1);//if we insert a new element(just imagining)in word1 that matches the char then we have to only move
          //j+1 thinking that it is matched eg:horse and hotr for before r if we insert t the i index will stay the same and only the j will move
            int deleted=1+solveUsingRecursion(a,b,i+1,j);//if we delete a element in a we just move the i pointer
            int replaced=1+solveUsingRecursion(a,b,i+1,j+1);// if we replace a element in a we move both i and j bcz we replace the word1 with the char
         //which is same as the word2 character
            ans=min(insert,min(deleted,replaced));//we find the minimum operation taken to match the word
        }
        return ans;
    }
    int minDistance(string word1, string word2) {
        if(word1.length()==0){
            return word2.length();
        }
        if(word2.length()==0){
            return word1.length();
        }
        return solveUsingRecursion(word1,word2,0,0);
    }
};
*//Solve using memoisation
class Solution {
public:
    int solveUsingMem(string& a, string& b, int i, int j, vector<vector<int> >& dp) {

        //base case
        if( i == a.length()) {
            return b.length()-j;
        }

        if(j == b.length()) {
            return a.length()-i;
        }

        if(dp[i][j] != -1) 
            return dp[i][j];

        int ans = 0;
        if(a[i] == b[j]) {
            ans = solveUsingMem(a,b,i+1,j+1, dp);
        }
        else {
            //operation perform karo 
            int insert = 1 + solveUsingMem(a,b,i,j+1, dp);
            int deleted = 1 + solveUsingMem(a,b,i+1,j, dp);
            int replace = 1 + solveUsingMem(a,b,i+1, j+1, dp);
            ans = min(insert, min(deleted, replace));
        }
        dp[i][j] =  ans;
        return dp[i][j];
    }

    int minDistance(string word1, string word2) {
        if(word1.length()==0){
            return word2.length();
        }
        if(word2.length()==0){
            return word1.length();
        }
     //here the 2d array will give u the minimum operations need from that i index to j index
        vector<vector<int> > dp(word1.length(), vector<int>(word2.length(), -1));
        return solveUsingMem(word1,word2,0,0,dp);
    }
};
*//Solve using Tabulation
int solveUsingTab(string a, string b) {
        vector<vector<int> > dp(a.length()+1, vector<int>(b.length()+1,0));

        for(int j =0; j<=b.length(); j++) {//if the the index or word1 has gone out of bound then it should perform operation equal to elements
         // left in word2
            dp[a.length()][j] =  b.length()-j;
        }

        for(int i =0; i<=a.length(); i++) {
            dp[i][b.length()] = a.length() - i;
        }

        for(int i = a.length()-1; i>=0; i--) {
            for(int j =b.length()-1; j>=0; j--) {
                int ans = 0;
                if(a[i] == b[j]) {
                    ans = dp[i+1][j+1];
                }
                else {
                    //operation perform karo 
                    int insert = 1 + dp[i][j+1];
                    int deleted = 1 + dp[i+1][j];
                    int replace = 1 + dp[i+1][j+1];
                    ans = min(insert, min(deleted, replace));
                }
                dp[i][j] =  ans;
                
            }
        }
        return dp[0][0];
    }
*//Space optimisation
int solveUsingTabSO(string a, string b) {
        //vector<vector<int> > dp(a.length()+1, vector<int>(b.length()+1,0));
        vector<int> curr(b.length()+1, 0);
        vector<int> next(b.length()+1, 0);

        for(int j =0; j<=b.length(); j++) {
            next[j] =  b.length()-j;
        }

        for(int i = a.length()-1; i>=0; i--) {
            //every row starts here
            //yaha galti karoge
            curr[b.length()] = a.length()-i;//j is out of bound so remaining elements in word1 will be the number of operation i.e deleteing
            //after shifting the curr[b.length()] will be overridden so we calculate whenever there is new rwo
            for(int j =b.length()-1; j>=0; j--) {
                int ans = 0;
                if(a[i] == b[j]) {
                    ans = next[j+1];
                }
                else {
                    //operation perform karo 
                    int insert = 1 + curr[j+1];
                    int deleted = 1 + next[j];
                    int replace = 1 + next[j+1];
                    ans = min(insert, min(deleted, replace));
                }
                curr[j] =  ans;
            }
            //shift
            next = curr;
         //as we are going from last to 0 next is moving upwards so next=curr
         //if we are going from 0 to last next is moving downwards then curr=next
        }
        return next[0];
    }

