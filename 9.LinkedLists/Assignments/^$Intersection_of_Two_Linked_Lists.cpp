https://leetcode.com/problems/intersection-of-two-linked-lists/description/
// Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

// For example, the following two linked lists begin to intersect at node c1:
// Example 1:


// Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
// Output: Intersected at '8'
// Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
// From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.
// - Note that the intersected node's value is not 1 because the nodes with value 1 in A and B (2nd node in A and 3rd node in B) are different node references. In other words, they point to two different locations in memory, while the nodes with value 8 in A and B (3rd node in A and 4th node in B) point to the same location in memory.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a=headA;
        ListNode* b=headB;
        while((a->next!=NULL)&&(b->next!=NULL)){
            if(a==b){//if both the ll has same length there will be a node which is the  point of intersection, is so we can directly return answer
                return a;
            }
            a=a->next;
            b=b->next;
        }
        if(a->next==0 && b->next==0&& a!=b)return 0;//if the length is same and u didn't find any same node then there is no intersection, we are doing this to save time as this will not go through the below process
        if(a->next==NULL){
            //B ll is bigger 
            //we need to find out how much bigger it is
            int blen=0;
            while(b->next!=NULL){
                blen++;
                b=b->next;
            }
            while(blen--){
                headB=headB->next;
            }
        }else{
            //A ll is bigger 
            //we need to find out how much bigger it is
            //doing this so we can change the starting point of a so that 
            //both the ll will be equal so if they meet somewhere that is the
            //intersection point
            int alen=0;
            while(a->next!=NULL){
                alen++;
                a=a->next;
            }
            while(alen--){
                headA=headA->next;
            }

        }
        while(headA!=headB){//if there is no intesection point they will traverse through the whole ll and become null
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};
