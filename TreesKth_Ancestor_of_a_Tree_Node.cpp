// Easy level question finding the kth ancestor
bool getKthAncestor(Node* root,int &k,int p){
  if(root==NULL){
    return false;
  }
  if(root->data==p){
    return true;
  }
  bool leftAns=getKthAncestor(root->left,k,p);
  bool rightAns=getKthAncestor(root->right,k,p);
  if(leftAns||rightAns){
    k--;
  }
  if(k==0){
    cout<<"Ans:"<<root->data<<endl;
    k=-1;
  }
  return leftAns||rightAns;
}
