https://leetcode.com/problems/validate-binary-search-tree/description/
// Given the root of a binary tree, determine if it is a valid binary search tree (BST).

// A valid BST is defined as follows:

// The left 
// subtree
//  of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.
 

// Example 1:


// Input: root = [2,1,3]
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
    bool solve(TreeNode* root,long long int lb,long long int ub){
        if(root==NULL){
            return true;
        }
        if(root->val>lb&&root->val<ub){
            bool leftAns=solve(root->left,lb,root->val);//the left side should be always be less than the root node
            bool rightAns=solve(root->right,root->val,ub);//the left side should be always be more than the root node
            return leftAns&&rightAns;
        }else{
            return false;
        }
    }
    bool isValidBST(TreeNode* root) {
        long long int lowerBound=-4294967296;
        long long int upperBound=4294967296;
        bool ans=solve(root,lowerBound,upperBound);
        return ans;
    }
};
