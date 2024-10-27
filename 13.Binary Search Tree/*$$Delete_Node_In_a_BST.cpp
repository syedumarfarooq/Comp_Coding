https://leetcode.com/problems/delete-node-in-a-bst/description/
// Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

// Basically, the deletion can be divided into two stages:

// Search for a node to remove.
// If the node is found, delete the node.
 

// Example 1:


// Input: root = [5,3,6,2,4,null,7], key = 3
// Output: [5,4,6,2,null,null,7]
// Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
// One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
// Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.
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
    int maxVal(TreeNode* root) {
	TreeNode* temp = root;
	if(temp == NULL) {
		return -1;
	}

	while(temp -> right != NULL) {//as in bst the max value is at right
		temp = temp ->right;
	}
	return temp -> val;
}
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL ) {
		return NULL;
	}
	if(root->val == key) {
		//isi ko delete krna h 
		//4 cases 
		if(root->left == NULL && root->right == NULL) {
			//leaf node
			//delete root;
			return NULL;
		}
		else if(root->left == NULL && root->right != NULL) {
			TreeNode* child = root->right;
			//delete root;
			return child;
		}
		else if(root->left != NULL && root->right == NULL) {
			TreeNode* child  = root->left;
			//delete root;
			return child;
		}
		else {
			//both child
			//find inorder predecessor which is present in the left subtree in that the maximum is the predecessor as the left tree 
			//consists of all the smaller elements so the maximum in it will be the predecessor
			int inorderPre = maxVal(root->left);
			//replace root->val value with inorder predecessor
			//replacing value to keep bst rules preserved 
			root->val = inorderPre;
			//delete inorder predecessor from left subtree
			root->left = deleteNode(root->left,inorderPre);
			return root;
			
		}
		
	}
	else if(key > root -> val) {
		//right jana chahiye
		root->right =  deleteNode(root->right, key);
	}
	else if(key < root->val) {
		//left jana chahioye
		root->left = deleteNode(root->left, key);
	}
	return root;

    }
};
