https://leetcode.com/problems/unique-binary-search-trees-ii/
// Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.
// Example 1:
// Input: n = 3
// Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
// Example 2:

// Input: n = 1
// Output: [[1]]
*//logic
  // in this we are taking start and end value and then making every element root and  and attaching there subtrees which is provided by
// recursion for we are doing this to get all the possible bst
  //eg;1,2,3,4,5 we are taking 3 root node then the recursion will give from left for 1,2 {null,1,2}if 1 is the root node
// {1,2,null} if 2 is root rode similarly for 4,5 {null,4,5} and {4,5,null} so we have to make combination of all 4 while adding
// i.e {1,2,null} {null,4,5} and {1,2,null}{4,5,null} and {null,1,2}{null,4,5} similarly to all possible combination as all of this make differnt
// trees for making this combination we use 2 for loops after every combination we add it to answer then return the answer
*//solved using recursion
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
    vector<TreeNode*> allPossibleBst(int start,int end){
        if(start>end)return {0};//return null
        if(start==end)return {new TreeNode(start)};//returning one node as it is the only node available
        vector<TreeNode*> ans;
        for(int i=start;i<=end;i++){
            vector<TreeNode*>left=allPossibleBst(start,i-1);
            vector<TreeNode*>right=allPossibleBst(i+1,end);
            for(int j=0;j<left.size();j++){
                for(int k=0;k<right.size();k++){
                    TreeNode* root=new TreeNode(i);
                    root->left=left[j];
                    root->right=right[k];
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return {};
       
        return allPossibleBst(1,n);

    }
};
*//solved using memoinsation
class Solution {
public:
    vector<TreeNode*> allPossibleBstMem(int start,int end,map<pair<int,int>,vector<TreeNode*>>&dp){
        if(start>end)return {0};
        if(start==end)return {new TreeNode(start)};
        if(dp.find({start,end})!=dp.end()){
            return dp[{start,end}];
        }
        vector<TreeNode*> ans;
        for(int i=start;i<=end;i++){
            vector<TreeNode*>left=allPossibleBstMem(start,i-1,dp);
            vector<TreeNode*>right=allPossibleBstMem(i+1,end,dp);
            for(int j=0;j<left.size();j++){
                for(int k=0;k<right.size();k++){
                    TreeNode* root=new TreeNode(i);
                    root->left=left[j];
                    root->right=right[k];
                    ans.push_back(root);
                }
            }
        }
        dp[{start,end}]=ans;//as the dp[start,end] is giving a vector of multiple Trees so that is why we are storing it in map 
        return dp[{start,end}];
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return {};
         map<pair<int,int>,vector<TreeNode*>>dp;//as the dp[start,end] is giving a vector of multiple Trees so that is why we are storing it in map 
        return allPossibleBstMem(1,n,dp);

    }
};
