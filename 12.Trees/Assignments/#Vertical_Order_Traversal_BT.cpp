https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/
// Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

// For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

// The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

// Return the vertical order traversal of the binary tree.

 

// Example 1:


// Input: root = [3,9,20,null,null,15,7]
// Output: [[9],[3,15],[20],[7]]
// Explanation:
// Column -1: Only node 9 is in this column.
// Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
// Column 1: Only node 20 is in this column.
// Column 2: Only node 7 is in this column.
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        queue<pair<TreeNode*,pair<int,int>>>q;//node row,col
        q.push({root,{0,0}});
        map<int,map<int,multiset<int>>>mp;//col.{row,multiset}//multiset because sorts in order and can store repeating values
     //we used map becase we wanted to answer in column wise and then in row wise as map sort the key in ascending order 
        while(!q.empty()){
            auto front=q.front();q.pop();
            TreeNode*& node=front.first;//taking by reference so that it wont take more space as pair inside pair or map inside map
            auto coordinate=front.second;
            int &row=coordinate.first;
            int &col=coordinate.second;
            mp[col][row].insert(node->val);
            if(node->left){
                q.push({node->left,{row+1,col-1}});
            }
            if(node->right){
                q.push({node->right,{row+1,col+1}});
            }
        }
        //store final vertical order into vector
        for(auto it:mp){
            auto&colMap=it.second;
            vector<int>vLine;
            for(auto colMapIt:colMap){
                auto&mset=colMapIt.second;
                vLine.insert(vLine.end(),mset.begin(),mset.end());//add in vline end 
            }
            ans.push_back(vLine);
        }
        return ans;
    }
};
