// add two given linked list 
// eg:l1:99
//    l2:99
//   =>198
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
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* forward=curr->next;
        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverse(l1);
        l2=reverse(l2);
        ListNode* ansHead=NULL;
        ListNode* ansTail=NULL;
        int carry=0;
        while((l1!=NULL)&&(l2!=NULL)){
            int sum=carry+l1->val+l2->val;
            int digit=sum%10;
            carry=sum/10;
            ListNode* newNode=new ListNode(digit);
            if(ansHead==NULL){
                ansHead=newNode;
                ansTail=newNode;
            }else{
                ansTail->next=newNode;
                ansTail=newNode;
            }
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL){
            int sum=carry+l1->val;
            int digit=sum%10;
            carry=sum/10;
            ListNode* newNode=new ListNode(digit);
            ansTail->next=newNode;
            ansTail=newNode;
            l1=l1->next;
        }
         while(l2!=NULL){
            int sum=carry+l2->val;
            int digit=sum%10;
            carry=sum/10;
            ListNode* newNode=new ListNode(digit);
            ansTail->next=newNode;
            ansTail=newNode;
            l2=l2->next;
        }
        while(carry!=0){
            int sum=carry;
            int digit=sum%10;
            carry=sum/10;
            ListNode* newNode=new ListNode(digit);
            ansTail->next=newNode;
            ansTail=newNode;
        }
        // ansHead=reverse(ansHead);
        return ansHead;
    }
};
