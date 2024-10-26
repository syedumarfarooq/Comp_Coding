https://leetcode.com/problems/balanced-binary-tree/description/
https://github.com/syedumarfarooq/Comp_Coding/blob/main/12.Trees/*Balanced_Binary_Tree.cpp
// Given a binary tree, determine if it is 
// height-balanced
// .

 

// Example 1:


// Input: root = [3,9,20,null,null,15,7]
// Output: true
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
    bool isbalanced=true;
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int lh=height(root->left);
        int rh=height(root->right);
        if(isbalanced && abs(lh-rh)>1){
            isbalanced=false;
        }
        return max(lh,rh)+1;
    }
    bool isBalanced(TreeNode* root) {
        height(root);
        return isbalanced;
    }
};
