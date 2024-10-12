https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
// Given a Linked List, where every node represents a sub-linked-list and contains two pointers:
// (i) a next pointer to the next node,
// (ii) a bottom pointer to a linked list where this node is head.
// Each of the sub-linked lists is in sorted order.
// Flatten the Link List so all the nodes appear in a single level while maintaining the sorted order.

// Note: The flattened list will be printed using the bottom pointer instead of the next pointer. Look at the printList() function in the driver code for more clarity.

// Examples:

// Input:

// Output:  5-> 7-> 8- > 10 -> 19-> 20-> 22-> 28-> 30-> 35-> 40-> 45-> 50.
// Explanation: The resultant linked lists has every node in a single level.(Note: | represents the bottom pointer.)
class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    Node* merge(Node* a,Node* b){
        if(a==NULL)return b;
        if(b==NULL)return a;
        Node* ans=0;
        if(a->data<b->data){
            ans=a;
            ans->bottom=merge(a->bottom,b);
        }else{
            ans=b;
            ans->bottom=merge(a,b->bottom);
        }
        return ans;
    }
    Node *flatten(Node *root) {
        // Your code here
        if(root==NULL){
            return NULL;
        }
        //we are doing this in reverse order because if we add first two,to 
        //access the third pointer we have to searched in the merged list and the second list have been merged to the fist list
        //if we do it from behind we can easily merge last two 
        Node* mergedLL=merge(root,flatten(root->next));
        return mergedLL;
    }
};
