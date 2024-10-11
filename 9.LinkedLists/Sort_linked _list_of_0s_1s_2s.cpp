// Given a linked list of 'N' nodes, where each node has an integer value that can be 0, 1, or 2. You need to sort the linked list in non-decreasing order and the return the head of the sorted list.
// Example:
// Given linked list is 1 -> 0 -> 2 -> 1 -> 2. 
// The sorted list for the given linked list will be 0 -> 1 -> 1 -> 2 -> 2.
Node* Sort0s1s2s(Node* &head){
  //creating three dummy nodes for 0,1,2
  Node* zeroHead=new Node(-1);
  Node* zeroTail=zeroHead;

  Node* oneHead=new Node(-1);
  Node* oneTail=oneHead;

  Node* twoHead=new Node(-1);
  Node* twoTail=twoHead;

  Node* curr=head;
  while(curr!=NULL){
    //connecting nodes from the original ll to there respecting sub ll
    if(curr->data==0){
      Node* temp=curr;
      curr=curr->next;
      temp->next=NULL;
      zeroTail->next=temp;
      zeroTail=temp;
      
    }else if(curr->data==1){
       Node* temp=curr;
      curr=curr->next;
      temp->next=NULL;
      oneTail->next=temp;
      oneTail=temp;
    }
    else if(curr->data==2){
       Node* temp=curr;
      curr=curr->next;
      temp->next=NULL;
      twoTail->next=temp;
      twoTail=temp;
    }
  }
  //deleting the dummy node of the 1 ll
  Node* temp=oneHead;
  oneHead=oneHead->next;
  temp->next=NULL;
  delete temp;
  //deleting the dummy node of the 2 ll
  Node* temp=twoHead;
  twoHead=twoHead->next;
  temp->next=NULL;
  delete temp;
  //joining
  if(oneHead!=NULL){
    zeroTail->next=oneHead;
    if(twoHead!=NULL){
      oneTail->next=twoHead;
    }
  }else{
    if(twoHead!=NULL){
      zeroTail->next=twoHead;
    }
  }
  //deleting the dummy node of the 0 ll
  Node* temp=zeroHead;
  zeroHead=zeroHead->next;
  temp->next=NULL;
  delete temp;
  //returning the ll
  return zeroHead;
}
