Node* sortedLinkedListIntoBst(Node* &head,int n){//head is the starting point of linked list
  if(n<=0||head==NULL){
    return NULL:
  }
  Node* leftSubTree=sortedLinkedListIntoBst(head,n/2);
  Node* root=head;
  root->left=leftSubTree;
  head=head->right;//students forget this line
  root->right=sortedLinkedListIntoBst(head,n-1-n/2);//left node is n-main node(1)-rest of the half;
  return root;
}
