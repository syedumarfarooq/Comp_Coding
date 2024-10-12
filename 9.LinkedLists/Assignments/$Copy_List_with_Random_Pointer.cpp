https://leetcode.com/problems/copy-list-with-random-pointer/description/
//There a linked list we need to copy the original ll has val,next,random and the random points to the random node from the original ll we 
//need to copy the ll and point the random same as the original but in the copies ll eg;if a node has a val 3 pointing random to 7 so in the 
//copy u have to point the new 3 to the new 7
/*

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
*// Time Complexity is O(n)*******

*// class Solution {
// public:
//     Node* helper(Node* head,unordered_map<Node*,Node*>&mp){
//         if(head==NULL)return NULL;
//         Node* newHead=new Node(head->val);
//         mp[head]=newHead;
//         newHead->next=helper(head->next,mp);
//         if(head->random){
//             newHead->random=mp[head->random];
//         }
//         return newHead;
//     }

//     Node* copyRandomList(Node* head) {
        
//         unordered_map<Node*,Node*>mp;
//         return helper(head,mp); 
//     }
// };****
*// Time Complexity is O(1)*******
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)return NULL;
        Node* it=head;
        while(it!=NULL){
            Node* newNode=new Node(it->val);
            newNode->next=it->next;
            it->next=newNode;
            it=it->next->next;
        }
        it=head;
        while(it){
            Node* cloneNode=it->next;
            cloneNode->random=it->random?it->random->next:NULL;
            it=it->next->next;

        }
        
        it=head;
        Node* cloneHead=it->next;
        while(it){
            Node* cloneNode=it->next;
            it->next=it->next->next;
            if(cloneNode->next){
                cloneNode->next=cloneNode->next->next;
            }
            it=it->next;
        }
        return cloneHead;
    }
};
