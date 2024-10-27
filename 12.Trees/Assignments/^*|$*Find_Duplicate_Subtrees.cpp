https://leetcode.com/problems/find-duplicate-subtrees/description/
// Given the root of a binary tree, return all duplicate subtrees.

// For each kind of duplicate subtrees, you only need to return the root node of any one of them.

// Two trees are duplicate if they have the same structure with the same node values.

 

// Example 1:


// Input: root = [1,2,3,4,null,2,4,null,null,4]
// Output: [[2,4],[4]]
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
    vector<TreeNode*> ans;//this will store ans
    unordered_map<string,int> subTreeMap;//this will store preorder string of every node and its repetition
    string preorder(TreeNode* root){
        if(!root)return "N";
        string curr=to_string(root->val);
        string l=preorder(root->left);
        string r=preorder(root->right);
        string s=curr+","+l+","+r;
        if(subTreeMap.find(s)!=subTreeMap.end()){//if there is a duplicate
            if(subTreeMap[s]==1){
                ans.push_back(root);//adding root node of the duplicate tree 
            }
            subTreeMap[s]++;
        }else{
            subTreeMap[s]=1;
        }
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        preorder(root);
        return ans;
    }
};
