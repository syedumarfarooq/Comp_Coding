void convertIntoSortedDLL(Node* root,Node* &head){
  if(root==NULL){
    return;
  }
  convertIntoSortedDLL(root->right,head);//sorting right first because it is easier to track head and add nodes to linked list
  root->right=head;
  if(head!=NULL){
    head->left=root;
  }
  head=root;
  convertIntoSortedDLL(root->left,head);
}
int main(){
  convertIntoSortedDLL(root,NULL);
}
