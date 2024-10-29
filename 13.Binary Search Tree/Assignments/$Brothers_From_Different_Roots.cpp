question also know as*//count pairs from 2 Bst whose sum is equal to given x **
https://www.geeksforgeeks.org/problems/brothers-from-different-root/1
// Given two BSTs containing N1 and N2 distinct nodes respectively and given a value x, your task is to complete the function countPairs(), that returns the count of all pairs of (a, b), where a belongs to one BST and b belongs to another BST, such that a + b = x.

// Example 1:

// Input:
// BST1:
//        5
//      /   \
//     3     7
//    / \   / \
//   2   4 6   8
// BST2:
//        10
//      /    \
//     6      15
//    / \    /  \
//   3   8  11   18
// x = 16
// Output:
// 3
// Explanation:
// The pairs are: (5, 11), (6, 10) and (8, 8)
*//LOGIC***
// we are taking inorder traversal of first and reverse inorder traversal for the second so first is in increasong order and second one is in
// decreasing order then we are adding it to a stack if the pair makes a answer we pop and move to next element if the sum is greater than the 
// target we poping from second stack and checking for next number if the sum is less than the target we are popoing the first stack and checking

class Solution
{
public:
    int countPairs(Node* root1, Node* root2, int x)
    {   int ans=0;
        stack<Node*>s1,s2;
        Node* a=root1;
        Node* b=root2;
        while(1){
          while(a){
              //inorder traversal
              s1.push(a);
              a=a->left;
          }
          while(b){
              //reverse inorder traversal
              s2.push(b);
              b=b->right;
          }
          if(s1.empty()||s2.empty()){
              break;
          }
          auto atop=s1.top();
          auto btop=s2.top();
          
          int sum=atop->data+btop->data;
          if(sum==x){
              ans++;
              s1.pop();
              s2.pop();
              a=atop->right;
              b=btop->left;
          }
          else if(sum<x){
              s1.pop();
              a=atop->right;
          }else{
              s2.pop();
              b=btop->left;
          }
      }
      return ans;
      
    }
};
