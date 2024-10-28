https://leetcode.com/problems/balance-a-binary-search-tree/
// Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

// A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

 

// Example 1:


// Input: root = [1,null,2,null,3,null,4,null,null]
// Output: [2,1,3,null,null,null,4]
// Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.
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
    TreeNode* buildTree(vector<int> &in,int s,int e){
        if(s>e){
            return NULL;
        }
        int mid=s+(e-s)/2;
        TreeNode* root=new TreeNode(in[mid]);
        root->left=buildTree(in,s,mid-1);
        root->right=buildTree(in,mid+1,e);
        return root;
    }
    void inorder(TreeNode *root,vector<int> &in){
        if(!root)return;
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> in;
        inorder(root,in);
        //build balanced bst using inorder traversal
        return buildTree(in,0,in.size()-1);
    }
};
