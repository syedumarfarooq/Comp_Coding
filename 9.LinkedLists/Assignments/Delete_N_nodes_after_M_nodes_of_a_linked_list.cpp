https://www.geeksforgeeks.org/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
// Given a linked list, delete n nodes after skipping m nodes of a linked list until the last of the linked list.
// Examples:

// Input: Linked List: 9->1->3->5->9->4->10->1, n = 1, m = 2

// Output: 9->1->5->9->10->1

// Explanation: Deleting 1 node after skipping 2 nodes each time, we have list as 9-> 1-> 5-> 9-> 10-> 1.
class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
        // code here
        if(head==NULL){
            return head;
        }
        int i=1;
        Node* it=head;
        while(i<m&&it!=NULL){
            
            i++;
            it=it->next;
        }
        if(it==NULL){
                return head;
            }
        Node* MthNode=it;
        it=MthNode->next;
        int j=0;
        while(j<n&&it!=NULL){

            Node* temp=it->next;
            it->next=NULL;
            delete it;
            it=temp;
            j++;
        }
        MthNode->next=it;
        linkdelete(it,n,m);
        return head;
    }
};

