https://leetcode.com/problems/house-robber-iii/
// The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.
// Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.
// Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.
// Example 1:
// Input: root = [3,2,3,null,3,null,1]
// Output: 7
// Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
*//logic
  // as we cannot two continues house we rob current house then rob then grand children or we rob the children leaving the parent and let
// recursion do the rest of it
*//Solved using recursion
  class Solution {
public:
    int solve(TreeNode* root){
        if(!root){
            return 0;
        }
        int robThisHouse=0,dontRobThisHouse=0;
        //robbing current house
        robThisHouse+=root->val;
        if(root->left)
            robThisHouse+=solve(root->left->left)+solve(root->left->right);
        if(root->right)
            robThisHouse+=solve(root->right->left)+solve(root->right->right);

        // dont rob current house
        dontRobThisHouse=solve(root->left)+solve(root->right);
        return max(robThisHouse,dontRobThisHouse);

    }
    int rob(TreeNode* root) {
        return solve(root);
    }
};
*//solved in memoisation
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
    int solve(TreeNode* root,unordered_map<TreeNode*,int>&dp){
        if(!root){
            return 0;
        }
        if(dp.find(root)!=dp.end()){
            return dp[root];
        }
        int robThisHouse=0,dontRobThisHouse=0;
        //robbing current house
        robThisHouse+=root->val;
        if(root->left)
            robThisHouse+=solve(root->left->left,dp)+solve(root->left->right,dp);
        if(root->right)
            robThisHouse+=solve(root->right->left,dp)+solve(root->right->right,dp);

        // dont rob current house
        dontRobThisHouse=solve(root->left,dp)+solve(root->right,dp);
        dp[root]=max(robThisHouse,dontRobThisHouse);
        return dp[root];

    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int> dp;
        return solve(root,dp);
    }
};
*//as bottom up approach will not make sense as its a tree structure so if we have to start from leaf node then we have to iterate to the 
*// bottom by traversing from top 
