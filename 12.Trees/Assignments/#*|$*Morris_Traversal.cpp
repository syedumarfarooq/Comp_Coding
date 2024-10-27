//It is a inorder traversal which uses O(n) time complexity and O(1) space complexity
//Inorder predecessor is the node that comes before the node in an inorder traversal i.e iorder traversal 40,20,50,10,30 ;50 is the inorder 
//predecessor of 10
//To find inorder predecessor we go left then right right right
//eg         10
   //      /    \
   //    20      30
   //  /   \ 
   // 40   50
https://leetcode.com/problems/binary-tree-inorder-traversal/
// Given the root of a binary tree, return the inorder traversal of its nodes' values.

 

// Example 1:

// Input: root = [1,null,2,3]

// Output: [1,3,2]
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode* curr=root;
        while(curr){
            //left node is null then visit it and go right
            if(curr->left==nullptr){
                ans.push_back(curr->val);
                curr=curr->right;
            }//left node is not null
            else{
                //find inorder predecessor
                TreeNode* pre=curr->left;
                while(pre->right!=curr&&pre->right){//if pre->right==curr then it is already connected the curr to pred so no need to find the pred and remove the link as we  have already visited
                    pre=pre->right;
                }
                //if pre->right is null then  go left after establishing the link from pred to curr
                if(pre->right==nullptr){
                    pre->right=curr;
                    curr=curr->left;
                }
                //left is already visited,go right after visiting curr node,while removing the link
                else{
                    pre->right=nullptr;
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};

