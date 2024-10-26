// left view intuition
// 1)store only one element in every level vy traversing left then right
// 2)store the node in the vector if the size of vector and level are equal i.e for first the level is 0 and the vector size is also zero etc
void printLeftView(Node* root,vector<int> &ans,int level){
  if(root==NULL){
    return;
  }
  if(level==ans.size()){
    ans.push_back(root->data);
  }
  printLeftView(root->left,ans,level+1);
  printLeftView(root->right,ans,level+1);
}
