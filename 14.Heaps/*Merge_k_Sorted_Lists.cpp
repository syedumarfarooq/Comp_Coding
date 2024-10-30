https://leetcode.com/problems/merge-k-sorted-lists/description/
// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

// Merge all the linked-lists into one sorted linked-list and return it.
// Example 1:

// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted list:
// 1->1->2->3->4->4->5->6
// Example 2:

// Input: lists = []
// Output: []
// Example 3:

// Input: lists = [[]]
// Output: []
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
 class compare {
    public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;

        int k = lists.size();
        if(k == 0) 
            return NULL;

        //first element of every blinked list ko insert krdo heap me 
        for(int i=0; i<k; i++) {
            if(lists[i] != NULL ) {
                minHeap.push(lists[i]);
            }
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(!minHeap.empty()) {
            ListNode* temp = minHeap.top();
            minHeap.pop();

            //temp may or may not be the first element of answer linked list 
            if(head == NULL) {
                //temp -> first element of ans LL
                head = temp;
                tail = temp;
                if(tail->next != NULL) {
                    minHeap.push(tail->next);
                }

            }
            else {
                //temp isnnot the first element of LL
                tail->next = temp;
                tail = temp;
                if(tail->next != NULL) {
                    minHeap.push(tail->next);
                }
            }
        }
    return head;
    }
};x
