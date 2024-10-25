https://leetcode.com/problems/balanced-binary-tree/description/
// Given a binary tree, determine if it is 
// height-balanced
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
    int maxDepth(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int leftHeight=maxDepth(root->left);
        int rightHeight=maxDepth(root->right);
        int ans=max(leftHeight,rightHeight)+1;
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        int leftHeight=maxDepth(root->left);
        int rightHeight=maxDepth(root->right);
        int diff=abs(leftHeight-rightHeight);
        bool ans1=(diff<=1);
        bool leftans=isBalanced(root->left);
        bool rightans=isBalanced(root->right);
        if(ans1&&leftans&&rightans){
            return true;
        }else{
            return false;
        }

    }
};
