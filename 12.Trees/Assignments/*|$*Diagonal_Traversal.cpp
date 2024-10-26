https://www.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1
// Given a Binary Tree, print the diagonal traversal of the binary tree.

// Consider lines of slope -1 passing between nodes. Given a Binary Tree, print all diagonal elements in a binary tree belonging to same line.
// If the diagonal element are present in two different subtress then left subtree diagonal element should be taken first and then right subtree. 

// Example 1:

// Input :
//             8
//          /     \
//         3      10
//       /   \      \
//      1     6     14
//          /   \   /
//         4     7 13
// Output : 8 10 14 3 6 7 13 1 4
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
