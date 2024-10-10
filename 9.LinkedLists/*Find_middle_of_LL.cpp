https://leetcode.com/problems/middle-of-the-linked-list/description/
//Finding the middle of the linked list if the list contains even then n/2 node is the middle and if the lenght is odd then n/2+1 is the middle
//TWO POINTER APPROACH
*//TORTOISE ALGORITHM*****
*//SLOW AND FAST POINTER APPROACH******
  // in fast and slow pointer approach two pointer fast and slow are kept on the first node and fast node takes two steps every time if it  
  // can take two steps then slow takes one step this process continues until the fast excedes the length of linked list
// Given the head of a singly linked list, return the middle node of the linked list.

// If there are two middle nodes, return the second middle node.

 

// Example 1:


// Input: head = [1,2,3,4,5]
// Output: [3,4,5]
// Explanation: The middle node of the list is node 3.
// Example 2:


// Input: head = [1,2,3,4,5,6]
// Output: [4,5,6]
// Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
 

// Constraints:

// The number of nodes in the list is in the range [1, 100].
// 1 <= Node.val <= 100
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(slow!=NULL&&fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
                slow=slow->next;
            }
        }
        return slow;
    }
};
eg;1,2,3,4,5,6  if u want middle as 3,4,5,6 check the below code and the changes made
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head->next;//changes made
        while(slow!=NULL&&fast!=NULL){//check will it work fine without slow!=null
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
                slow=slow->next;
            }
        }
        return slow;
    }
};
//my method
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(slow!=NULL&&fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
              if(fast!=NULL){
                slow=slow->next;
              }
                
            }
        }
        return slow;
    }
};
