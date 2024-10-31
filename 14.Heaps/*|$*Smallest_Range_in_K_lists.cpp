https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/

// You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

// We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

 

// Example 1:

// Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
// Output: [20,24]
// Explanation: 
// List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
// List 2: [0, 9, 12, 20], 20 is in range [20,24].
// List 3: [5, 18, 22, 30], 22 is in range [20,24].
// Example 2:

// Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
// Output: [1,1]
*//LOGIC******
// if we take all elements a from from every k list and make a min and maximum range then all the number  of every row will lie
// in that range so we have to find that range and the minimum difference is the output
//in the end we have to get smallest range for making the minimum and maximum range smaller we have to either increase the minimum or decrease
//the maximum but as the question say non descending order if we go to next element(as linked list cannot go back)
//it increase and there is no chance of decreasing or going back i.e  we are increasing the minimum that is why we are using min heap so that
// we can delete the minimum number and go further(as the number increases)to create new range which keeps on decreasing the range what if we
// chosse max heap this will update min as we go then the range would keep increasing as the maximum will keep increasing through out the list
//as it is non decreasing order but we want minimum range so that we why we use minimum number and keep on increasing in
*//SOLUTION****
  class Node{
    public:
    int data;
    int row;
    int col;
    Node(int d,int r,int c){
        data=d;
        row=r;
        col=c;
    }
};
class compare{
    public:
    bool operator()(Node* a,Node* b){
        return a->data>b->data;
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Node*,vector<Node*>,compare> pq;
        int k=nums.size();
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<k;i++){
            int element=nums[i][0];
            maxi=max(maxi,element);
            mini=min(mini,element);
            pq.push(new Node(element,i,0));
        }
        //initial range
        int ansStart=mini;
        int ansEnd=maxi;
        while(!pq.empty()){
            Node* top=pq.top();
            int topElement=top->data;
            int topRow=top->row;
            int topCol=top->col;
            pq.pop();
            //mini updated
            mini=topElement;
            //check for answer
            int currRange=maxi-mini;
            int ansRange=ansEnd-ansStart;
            if(currRange<ansRange){
                ansStart=mini;
                ansEnd=maxi;
            }
            //check for new element in the same list
            if(topCol+1<nums[topRow].size()){
                maxi=max(maxi,nums[topRow][topCol+1]);
                Node* newNode=new Node(nums[topRow][topCol+1],topRow,topCol+1);
                pq.push(newNode);
            }else{
                // if there is no element in the same list
                //then it will break the rule that there must be range which has
                //element of every list if one list ends we stop
                break;
            }

        }
        vector<int> ans;
        ans.push_back(ansStart);
        ans.push_back(ansEnd);
        return ans;
    }
};
