https://workat.tech/problem-solving/practice/inorder-predecessor-bst
// The inorder predecessor of a node p is the node q that comes just before p in the binary tree's inorder traversal.

// Given the root node of a binary search tree and the node p, find the inorder predecessor of node p. If it does not exist, return null.

// inorder-predecessor-bst
Node* findPredecessor(Node* root, Node* p) {
    // add your logic here
	Node* curr=root;
	Node* pred=0;
	while(curr){
		if(curr->data<p->data){
			pred=curr;
			curr=curr->right;
		}else{
			curr=curr->left;
		}
	}
	return pred;
}
  
