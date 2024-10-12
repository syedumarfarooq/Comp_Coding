https://leetcode.com/problems/merge-two-sorted-lists/description/
// You are given the heads of two sorted linked lists list1 and list2.

// Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

// Return the head of the merged linked list.

 

// Example 1:


// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }
        ListNode* ans=new ListNode(-1);
        ListNode* mptr=ans;
        while((list1!=NULL)&&(list2!=NULL)){
            if(list1->val<=list2->val){
                mptr->next=list1;
                mptr=list1;
                list1=list1->next;
            }else{
                mptr->next=list2;
                mptr=list2;
                list2=list2->next;
            }
        }
        if(list1!=NULL){
            mptr->next=list1;
        }
        if(list2!=NULL){
            mptr->next=list2;
        }
        return ans->next;
    }
};
