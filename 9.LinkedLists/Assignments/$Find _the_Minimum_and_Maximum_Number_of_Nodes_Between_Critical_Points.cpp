https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description/
Find the Minimum and Maximum Number of Nodes Between Critical Points
// A critical point in a linked list is defined as either a local maxima or a local minima.

// A node is a local maxima if the current node has a value strictly greater than the previous node and the next node.

// A node is a local minima if the current node has a value strictly smaller than the previous node and the next node.

// Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.

// Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] where minDistance is the minimum distance between any two distinct critical points and maxDistance is the maximum distance between any two distinct critical points. If there are fewer than two critical points, return [-1, -1].

// Example 1:
// Input: head = [3,1]
// Output: [-1,-1]
// Explanation: There are no critical points in [3,1].
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans= {-1,-1};
        ListNode* prev=head;
        if(prev==NULL)return ans;
        ListNode* curr=head->next;
        if(curr==NULL)return ans;
        ListNode* nxt=head->next->next;
        if(nxt==NULL)return ans;
        int i=1;
        int firstCP=-1;
        int lastCP=-1;
        int minDist=INT_MAX;
        while(nxt!=NULL){
            bool isCP=((curr->val>prev->val&&curr->val>nxt->val)||(curr->val<prev->val&&curr->val<nxt->val))?true:false;
            if(isCP&&firstCP==-1){
                firstCP=i;
                lastCP=i;
            }else if(isCP){
                minDist=min(minDist,i-lastCP);
                lastCP=i;
            }
            i++;
            prev=prev->next;
            curr=curr->next;
            nxt=nxt->next;
        }
        if(lastCP==firstCP){
            return ans;
        }else{
            ans[0]=minDist;
            ans[1]=lastCP-firstCP;
        }return ans;



    }
};
