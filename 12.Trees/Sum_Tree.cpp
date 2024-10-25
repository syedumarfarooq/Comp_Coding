*//Congradulations this is your solution*******
https://www.geeksforgeeks.org/problems/sum-tree/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
// Given a Binary Tree. Check for the Sum Tree for every node except the leaf node. Return true if it is a Sum Tree otherwise, return false.

// A SumTree is a Binary Tree where the value of a node is equal to the sum of the nodes present in its left subtree and right subtree. An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. A leaf node is also considered a Sum Tree.

// Examples :

// Input:
//     3
//   /   \    
//  1     2
// Output: true
// Explanation: The sum of left subtree and right subtree is 1 + 2 = 3, which is the value of the root node. Therefore,the given binary tree is a sum tree.
class Solution {
  public:
    int totalSum(Node* root){
        int sum=0;
        if(root==NULL){
            return 0;
        }
        int left=totalSum(root->left);
        int right=totalSum(root->right);
        return left+right+root->data;
    }
    bool isSumTree(Node* root) {
        // Your code here
        if(root==NULL){
            return true;
        }
        if(root->right==NULL&&root->left==NULL){//if leaf node return true
            return true;
        }
        bool leftAns=isSumTree(root->left);
        bool rightAns=isSumTree(root->right);
        if(leftAns&&rightAns){
            int leftData = (root->left != NULL) ? totalSum(root->left) : 0;
            int rightData = (root->right != NULL) ? totalSum(root->right) : 0;
    
            int sum = leftData + rightData;
            // cout<<"sum of"<<root->data<<" :"<<sum<<endl;
            if(sum==root->data){
                return true;
            }else{
                return false;
            }
        }
        return false;
        
        
    }
};
