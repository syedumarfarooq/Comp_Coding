https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
// Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

 

// Example 1:


// Input: root = [3,1,4,null,2], k = 1
// Output: 1
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
    int kthSmallest(TreeNode* root, int &k) {
        if(root==NULL){
            return -1;
        }
        int leftAns=kthSmallest(root->left,k);
        if(leftAns!=-1){//if there is answer present in left then return left;
            return leftAns;
        }
        k--;
        if(k==0){
            return root->val;
        }
        int rightAns=kthSmallest(root->right,k);
        return rightAns;
    }
};
