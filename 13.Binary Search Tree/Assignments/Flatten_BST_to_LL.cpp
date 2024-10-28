// flatten bst into ll i.e the left should point to null and the right should point to next node
void in(Node* root,Node* &prev){
  if(!root)return;
  in(root->left,prev);
  prev->left=0;
  prev->right=root;
  prev=root;
  in(root->right,prev);
}
Node* flatten(Node* root){
  Node* dummy=new Node(-1);
  Node* prev=dummy;
  in(root,prev);
  prev->left=0;//as the last node of the tree much be pointed to null
  prev->right=0;
  root=dummy->right;//the answer starts from dummy's right;
  return root;
}
