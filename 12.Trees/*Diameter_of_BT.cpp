https://leetcode.com/problems/diameter-of-binary-tree/description/
// Given the root of a binary tree, return the length of the diameter of the tree.

// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

// The length of a path between two nodes is represented by the number of edges between them.

 

// Example 1:


// Input: root = [1,2,3,4,5]
// Output: 3
// Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int maxDepth(TreeNode* root) {
        if(root==NULL){
    return 0;
  }
  int leftHeight=maxDepth(root->left);
  int rightHeight=maxDepth(root->right);
  int ans=max(leftHeight,rightHeight)+1;
  return ans;
    }
    //as the question says may or may not include node so the longest path can 
    //be on the left side or right side or with including both side with root
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int op1=diameterOfBinaryTree(root->left);
        int op2=diameterOfBinaryTree(root->right);
        int op3=maxDepth(root->right)+maxDepth(root->left);
        int ans=max(op1,max(op2,op3));
        return ans;
    }
};
