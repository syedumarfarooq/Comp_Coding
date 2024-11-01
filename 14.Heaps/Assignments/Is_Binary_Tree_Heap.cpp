https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1
// Given a binary tree. The task is to check whether the given tree follows the max heap property or not.
// Note: Properties of a tree to be a max heap - Completeness and Value of node greater than or equal to its child.

// Example 1:

// Input:
//       5
//     /  \
//    2    3
// Output: 1
// Explanation: The given tree follows max-heap property since 5,
// is root and it is greater than both its children.

// Example 2:

// Input:
//        10
//      /   \
//     20   30 
//   /   \
//  40   60
// Output: 0
class Solution {
  public:
    int nodeCount(Node* &tree){
        if(!tree)return 0;
        int l=nodeCount(tree->left);
        int r=nodeCount(tree->right);
        return l+r+1;
    }
    bool isCBT(Node* &root,int i,int&n){
        if(!root)return true;
        if(i>n){
            return false;
        }
        return isCBT(root->left,2*i,n)&&isCBT(root->right,2*i+1,n);
        
    }
    bool isMaxOrder(Node* root){
        if(!root) return true;
        bool l=isMaxOrder(root->left);
        bool r=isMaxOrder(root->right);
        bool ans=false;
        if(!root->left&&!root->right){
            ans=true;
        }else if(root->left&&!root->right){
            ans=root->data>root->left->data;
        }else{
            ans=root->data>root->right->data&&root->data>root->left->data;
        }
        return ans&&l&&r;
    }
    bool isHeap(struct Node* tree) {
        int n=nodeCount(tree);
        int i=1;
        return isCBT(tree,i,n)&&isMaxOrder(tree);
    }
};
