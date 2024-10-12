https://leetcode.com/problems/rotate-list/description/
// Given the head of a linked list, rotate the list to the right by k places.
// Example 1:
// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]
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
    int findlen(ListNode* head){
        int len=0;
        ListNode* temp=head;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            return head;
        }
        int len=findlen(head);
        int actualRotateK=(k%len);//doing this bcz if a list of 5 length will be same after one rotation and 6 rotations and similarlly for 2 and 7 rotations
        if(actualRotateK==0)return head;
        int newLastNodePos=len-actualRotateK-1;
        ListNode* newLastNode=head;
        for(int i=0;i<newLastNodePos;i++){
            newLastNode=newLastNode->next;
        }
        ListNode* newHead=newLastNode->next;
        newLastNode->next=0;
        ListNode* it=newHead;
        while(it->next!=NULL){
            it=it->next;
        }
        it->next=head;
        return newHead;

    }
};
