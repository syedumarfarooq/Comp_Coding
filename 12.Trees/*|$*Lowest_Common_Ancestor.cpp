https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 

// Example 1:


// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
// Output: 3
// Explanation: The LCA of nodes 5 and 1 is 3.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        if(root->val==p->val)return p;
        if(root->val==q->val)return q;
        TreeNode* leftAns=lowestCommonAncestor(root->left,p,q);
        TreeNode* rightAns=lowestCommonAncestor(root->right,p,q);
        if(leftAns==NULL&&rightAns==NULL){
            return NULL;
        }else if(leftAns!=NULL&&rightAns==NULL){
            return leftAns;
        }else if(leftAns==NULL&&rightAns!=NULL){
            return rightAns;
        }else{
            return root;//if the left and right both of a root is not null meaning they have found p and q and meet at the lowest commmon anscestor
        }
    
    }
};
