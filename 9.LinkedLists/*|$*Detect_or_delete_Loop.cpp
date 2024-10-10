// In detect or delete loop, the question may be asked 
*// -check if there is a loop present**********
      // Floyd cycle detection algorithm i.e slow fast pointer
      https://leetcode.com/problems/linked-list-cycle/description/
      // Given head, the head of a linked list, determine if the linked list has a cycle in it.
      
      // There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
      
      // Return true if there is a cycle in the linked list. Otherwise, return false.
      
       
      
      // Example 1:
      
      
      // Input: head = [3,2,0,-4], pos = 1
      // Output: true
      // Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
      /**
       * Definition for singly-linked list.
       * struct ListNode {
       *     int val;
       *     ListNode *next;
       *     ListNode(int x) : val(x), next(NULL) {}
       * };
       */
      class Solution {
      public:
          bool hasCycle(ListNode *head) {
              ListNode* slow=head;
              ListNode* fast=head;
              while(fast!=NULL){
                  fast=fast->next;
                  if(fast!=NULL){
                      fast=fast->next;
                      slow=slow->next;
                  }
                  if(fast==slow){
                      return true;
                  }
              }
              return false;
          }
      };
*// -starting point of loop************
      https://leetcode.com/problems/linked-list-cycle-ii/description/
Explained logic below
      /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    ListNode *detectCycle(ListNode *head) {
        if(head==NULL||head->next==NULL){
            return NULL;
            
        }
        ListNode* slow=head;
        ListNode* fast=head;
              while(fast!=NULL){
                  fast=fast->next;
                  if(fast!=NULL){
                      fast=fast->next;
                      slow=slow->next;
                  }
                  if(fast==slow){
                    slow=head;
                    break;
                  }
              }
           if(fast==NULL){
            return NULL;
           }

              while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
              }
              return slow;

    }
};
// eg:1-2-3-4-5-6
//          |    |
//          9-8-7
// let A be the distance from the head to the starting of the loop
// let C be the number of cycles inside the loop before meeting slow and fast(starts from the begining of the loop and will end at the same point
//       this is counted as one loop or cycles)i.e from 4 to 4
// let B be the distance from the starting of the loop to where slow and fast meet for eg slow and fast meet at 6 after many cycles so the 
//       distance from 4-6 is B
// WKT
// Distance travelled by fast=2*Distance travelled by slow
// so,
// A+xC+B=2(A+yC+B)
// (x-2y)C=A+B
// let x-2y=k
// so,
// A+B=kC,i.e A+B is k cycles
// from the above formula we can predict the initial point of the loop
// so slow and fast meet at some point in the loop,so the distance from the begining of the loop to meeting point is B if we add A to it
// we will come back to the starting part of the loop, so we put slow back to head to track A distance then we iterate one by one then 
// at the point they meet again is the initial point of the loop as it has coverd A distance that is it has travelled A distance
*// -remove loop****************
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    ListNode *remoceCycle(ListNode *head) {
        if(head==NULL||head->next==NULL){
            return NULL;
            
        }
        ListNode* slow=head;
        ListNode* fast=head;
              while(fast!=NULL){
                  fast=fast->next;
                  if(fast!=NULL){
                      fast=fast->next;
                      slow=slow->next;
                  }
                  if(fast==slow){
                    slow=head;
                    break;
                  }
              }
           if(fast==NULL){
            return NULL;
           }
            ListNode* prev=fast;
              while(slow!=fast){
                prev=fast;
                slow=slow->next;
                fast=fast->next;
              }
              prec-next=NULL;
              return slow;

    }
};
