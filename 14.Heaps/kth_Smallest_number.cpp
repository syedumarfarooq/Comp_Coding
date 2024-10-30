https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
//generally we would think to use min heap and then find the k-1th element but this will give space complexity O(n) which takes more space
*//LOGIC**
//Max heap method
// create max heap for first k elements and remanining elements will only be inserted if the elements is less than heap top element then heapify
// Space Complexity:O(k) that is the max heap only contains k elements which is less than the min heap method
class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int>pq;
        for(int i=0;i<k;i++){
            pq.push(arr[i]);
        }
        for(int i=k;i<arr.size();i++){
            if(arr[i]<pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        int ans=pq.top();
        return ans;
    }
    
};
