https://leetcode.com/problems/symmetric-tree/
// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

// Example 1:


// Input: root = [1,2,2,3,4,4,3]
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
    bool isMirror(TreeNode* p, TreeNode* q) {
        if(p==NULL&&q==NULL)return true;
        if(p!=NULL&q!=NULL){
            return (p->val==q->val)
                &&isMirror(p->left,q->right)
                &&isMirror(p->right,q->left);
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left,root->right);
    }
};
