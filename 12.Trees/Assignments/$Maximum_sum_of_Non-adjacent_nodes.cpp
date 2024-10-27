https://www.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1
// Given a binary tree with a value associated with each node, we need to choose a subset of these nodes such that sum of chosen nodes is maximum under a constraint that no two chosen node in subset should be directly connected that is, if we have taken a node in our sum then we can’t take its any children or parents in consideration and vice versa.

                                               

// Example 1:

// Input:
//      11
//     /  \
//    1    2
// Output: 11
// Explanation: The maximum sum is sum of
// node 11.
class Solution{
  public:
    pair<int,int> getMaxSum_Helper(Node* root){
        if(root==NULL)return {0,0};//sum including the node,sum excluding the node
        //eg:for 1 {4+11+1,(max{2,4}+{max3.11})}//in this if we include 1 then we have to exclude 2,3 but if we exclude 1 then we can include 2 or 3 or exclude 2 or 3
            //  / \
         // 2{2,4}  3{3,11}
         //  /         / \
    // 4{4,0}     5{5,0}  6{6,0}
        auto left=getMaxSum_Helper(root->left);
        auto right=getMaxSum_Helper(root->right);
        //sum including the node;
        //if we include current node then we have to exclude the bottom node;
        int a=root->data+left.second+right.second;
        //sum excludingthe node
        //if we exclude the current node we can include the bottom node or exclude the bottom node for their bottom we cannout use both 
        //so we use the max sum to determine to include bottom node or not
        int b=max(left.first,left.second)+max(right.first,right.second);
        return{a,b};
        
    }
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        auto ans=getMaxSum_Helper(root);
        return max(ans.first,ans.second);
    }
};
