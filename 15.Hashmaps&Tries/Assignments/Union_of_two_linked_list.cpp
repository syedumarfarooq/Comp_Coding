https://www.geeksforgeeks.org/problems/union-of-two-linked-list/1
// Given two linked lists (L1 & L2), your task is to complete the function makeUnion(), which returns the union list of two linked lists. This union list should include all the distinct elements only and it should be sorted in ascending order.

// Examples:

// Input: L1 = 9->6->4->2->3->8, L2 = 1->2->8->6->2
// Output: 1 -> 2 -> 3 -> 4 -> 6 -> 8 -> 9

// Explanation: All the distinct numbers from two lists, when sorted form the list in the output. 
class Solution {
  public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2) {
        
        map<int,Node*>map;
        Node* curr=head1;
        while(curr){
            map[curr->data]=curr;
            curr=curr->next;
        }
        curr=head2;
        while(curr){
            map[curr->data]=curr;
            curr=curr->next;
        }
        Node* UL=NULL;
        curr=NULL;
        for(auto it=map.begin();it!=map.end();it++){
            if(!UL){
                UL=it->second;
                curr=UL;
            }else{
                curr->next=it->second;
                curr=curr->next;
            }
        }
        curr->next=NULL;
        return UL;
    }
};
