https://leetcode.com/problems/path-sum-iii/
// Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

// The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

 

// Example 1:


// Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
// Output: 3
// Explanation: The paths that sum to 8 are shown.
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
    int ans=0;
    void pathFromOneRoot(TreeNode* root, long long sum){
        if(!root)return;
        if(sum==root->val){
            ans++;//not returning because if targetsum is 8 and the path is 5,3,-1+1 so this is also considered as one path
        }
        pathFromOneRoot(root->left,sum-root->val);
        pathFromOneRoot(root->right,sum-root->val);
    }
    int pathSum(TreeNode* root, long long targetSum) {
        if(root){
            pathFromOneRoot(root,targetSum);
            pathSum(root->left,targetSum);//this goes and checks every node for path
            pathSum(root->right,targetSum);
        }
        return ans;
    }
};
