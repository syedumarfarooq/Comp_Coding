https://leetcode.com/problems/range-sum-of-bst/description/
// Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].

 

// Example 1:


// Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
// Output: 32
// Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.
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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==NULL){
            return 0;
        }
        int ans=0;
        bool wasInRange=false;
        if(root->val>=low&&root->val<=high){
            wasInRange=true;
            ans+=root->val;
        }
        if(wasInRange){
            ans+=rangeSumBST(root->left,low,high)+rangeSumBST(root->right,low,high);
        }else if(root->val>high){
            ans+=rangeSumBST(root->left,low,high);
        }else if(root->val<low){
            ans+=rangeSumBST(root->right,low,high);
        }
        return ans;
    }
};
