// eg:1,2,3,4,5,6,7,8,9
//   using the inorder we have to create a BSt
Node* bstUsingInorder(int inorder[],int s,int e){
  if(s>e){
    return NULL;
  }
  int mid=s+(e-s)/2;
  int element=inorder[mid];
  Node* root=new Node(element);
  root->left=bstUsingInorder(inorder,s,mid-1);
  root->right=bstUsingInorder(inorder,mid+1,e);
  return root;
}
