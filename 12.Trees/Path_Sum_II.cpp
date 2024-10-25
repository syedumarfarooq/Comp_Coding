https://leetcode.com/problems/path-sum-ii/description/
// Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

// A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

 

// Example 1:
// Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
// Output: [[5,4,11,2],[5,8,4,5]]
// Explanation: There are two paths whose sum equals targetSum:
// 5 + 4 + 11 + 2 = 22
// 5 + 8 + 4 + 5 = 22
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
*//Value passed without reference******
class Solution {
public:
    void solve(TreeNode* root, int targetSum,int currSum,vector<int> path,vector<vector<int>> &ans){
        if(root==NULL){
            return;
        }
        if(root->right==NULL&&root->left==NULL){
            currSum+=root->val;
            path.push_back(root->val);
            if(currSum==targetSum){
                ans.push_back(path);
            }
            return;
        }
        currSum+=root->val;
        path.push_back(root->val);
        solve(root->left,targetSum,currSum,path,ans);
        solve(root->right,targetSum,currSum,path,ans);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        int sum=0;
        solve(root,targetSum,sum,path,ans);
        return ans;
    }
};
*//Value passed with reference******
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
    void solve(TreeNode* root, int targetSum,int &currSum,vector<int> &path,vector<vector<int>> &ans){
        if(root==NULL){
            return;
        }
        if(root->right==NULL&&root->left==NULL){
            currSum+=root->val;
            path.push_back(root->val);
            if(currSum==targetSum){
                ans.push_back(path);
            }
            currSum-=root->val;
            path.pop_back();
            return;
        }
        currSum+=root->val;
        path.push_back(root->val);
        solve(root->left,targetSum,currSum,path,ans);
        solve(root->right,targetSum,currSum,path,ans);
        currSum-=root->val;
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        int sum=0;
        solve(root,targetSum,sum,path,ans);
        return ans;
    }
};
