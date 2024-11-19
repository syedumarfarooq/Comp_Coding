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
            int insert=1+solveUsingRecursion(a,b,i,j+1);//if we insert a new element in word1 that maches the char then we have to only move
          //j+1 
            int deleted=1+solveUsingRecursion(a,b,i+1,j);//if we delete a element in a we just move the i pointer
            int replaced=1+solveUsingRecursion(a,b,i+1,j+1);// if we replace a element in a we move both i and j 
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
