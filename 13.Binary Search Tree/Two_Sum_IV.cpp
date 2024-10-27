https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
// Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

 

// Example 1:


// Input: root = [5,3,6,2,4,null,7], k = 9
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
    void storeInorder(TreeNode* root,vector<int> &inorder){
        if(root==NULL)return;
        storeInorder(root->left,inorder);
        inorder.push_back(root->val);
        storeInorder(root->right,inorder);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        storeInorder(root,inorder);
        int s=0;
        int e=inorder.size()-1;
        while(s<e){
            int sum=inorder[s]+inorder[e];
            if(sum==k)return true;
            if(sum>k){
                e--;
            }
            else{
                s++;
            }
        }
        return false;
    }
};
