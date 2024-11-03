// Check Linked List is a circular ll or has a loop present in it
*//Logic
  // we keep on adding node to the map so whenever there is a node which is already added then it is a circular

bool checkCircular(Node* head){
  unordered_map<Node*,bool>visit;
  Node* temp=head;
  while(temp!=NULL){
    if(visit.find(temp)!=v.end()){
      return true;
    }else{
      visit[temp]=true;
    }
    temp=temp->next;
  } 
  return false;
}
