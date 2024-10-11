https://www.hackerrank.com/challenges/get-the-value-of-the-node-at-a-specific-position-from-the-tail/problem
// Given a pointer to the head of a linked list and a specific position, determine the data value at that position. 
// Count backwards from the tail node. The tail is at postion 0, its parent is at 1 and so on.
// example:3->2->1->0 positionfromtail=2
//         =>2
  void fun(SinglyLinkedListNode* head,int &positionFromTail,int &ans){
    if(head==NULL){
        return;
    }
    fun(head->next,positionFromTail,ans);
    if(positionFromTail==0){
        ans=head->data;
    }
    positionFromTail--;
}
int getNode(SinglyLinkedListNode* llist, int positionFromTail) {
int ans=-1;
fun(llist,positionFromTail,ans);
return ans;
}
