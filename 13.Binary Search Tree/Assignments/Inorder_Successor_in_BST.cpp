https://www.geeksforgeeks.org/problems/inorder-successor-in-bst/1
// Given a BST, and a reference to a Node x in the BST. Find the Inorder Successor of the given node in the BST.
 

// Example 1:

// Input:
//       2
//     /   \
//    1     3
// K(data of x) = 2
// Output: 3 
// Explanation: 
// Inorder traversal : 1 2 3 
// Hence, inorder successor of 2 is 3.
class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        Node* succ=0;
        Node* curr=root;
        while(curr){
            if(curr->data>x->data){
                succ=curr;
                curr=curr->left;
            }else{
                curr=curr->right;
            }
        }
        return succ;
    }
};
