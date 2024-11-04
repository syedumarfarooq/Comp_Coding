https://www.geeksforgeeks.org/problems/intersection-of-two-linked-list/1
// Given two linked lists head1 and head2, find the intersection of two linked lists. Each of the two linked lists contains distinct node values.

// Note: The order of nodes in this list should be the same as the order in which those particular nodes appear in input head1 and return null if no common element is present.

// Examples:

// Input: LinkedList1: 9->6->4->2->3->8 , LinkedList2: 1->2->8->6
 
// Output: 6->2->8
// Explanation: Nodes 6, 2 and 8 are common in both of the lists and the order will be according to LinkedList1. 
class Solution {
  public:
     Node* findIntersection(Node* head1, Node* head2) {
        unordered_map<int,int>map;//data,occurrence
        Node* curr=head2;
        //hash l2 items bcz as we have to give output in the order of ll1 so 
        //thats why we add ll2 then compare ll1 with if present then add that
        // node so it will in ll1's order
        while(curr){
            map[curr->data]++;
            curr=curr->next;
        }
        Node* IL=NULL;
        Node* it=0;
        curr=head1;
        while(curr){
            if(map.find(curr->data)!=map.end()){
                //node val found in l2
                if(!IL){
                    IL=curr;
                    it=IL;
                }else{
                    if(map[curr->data]>0){
                        it->next=curr;
                    it=it->next;
                    map[curr->data]--;
                    }
                    
                }
            }
            curr=curr->next;
        }
        
             it->next=NULL;*//*Giving error in compiler but this code is currect to run this code without error in gfg platform use
               *//if(it){*
              *// it->next=NULL;*
               *// }*
        
       
        return IL;
    }
};
