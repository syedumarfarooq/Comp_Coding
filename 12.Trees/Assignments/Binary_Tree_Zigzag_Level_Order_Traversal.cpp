https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
// Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

// Example 1:


// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[20,9],[15,7]]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)return ans;
        bool LtoRdir=true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int width=q.size();
            vector<int> oneLevel(width);
            for(int i=0;i<width;i++){
                TreeNode* front=q.front();q.pop();
                int index=LtoRdir?i:width-i-1;
                oneLevel[index]=front->val;
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
            LtoRdir=!LtoRdir;
            ans.push_back(oneLevel);

        }
        return ans;
    }
};
