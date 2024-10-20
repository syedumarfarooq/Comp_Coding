// Sum of minimum and maximum elements of all subarrays of size k.
// Given an array of both positive and negative integers, the task is to compute sum of minimum and maximum elements of all sub-array of size k.

// Examples: 

// Input : arr[] = {2, 5, -1, 7, -3, -1, -2}  
//         K = 4
// Output : 18
// Explanation : Subarrays of size 4 are : 
//      {2, 5, -1, 7},   min + max = -1 + 7 = 6
//      {5, -1, 7, -3},  min + max = -3 + 7 = 4      
//      {-1, 7, -3, -1}, min + max = -3 + 7 = 4
//      {7, -3, -1, -2}, min + max = -3 + 7 = 4   
     
//      Missing sub arrays - 
     
//      {2, -1, 7, -3}
//      {2, 7, -3, -1}
//      {2, -3, -1, -2}
//      {5, 7, -3, -1}
//      {5, -3, -1, -2}
//      and few more -- why these were not considered??
//      Considering missing arrays result coming as 27
     
//      Sum of all min & max = 6 + 4 + 4 + 4 = 18
vector<int> sumofminmaxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq,dq2;
     
        int ans=0;
        for(int i=0;i<k;i++){
            while(!dq.empty()&&nums[i]>=nums[dq.back()]){//if anything smaller than the ith number(i.e before) than pop
                dq.pop_back();
            }
             while(!dq2.empty()&&nums[i]<=nums[dq2.back()]){//if anything greater than the ith number(i.e before) than pop
                dq2.pop_back();
            }
            dq.push_back(i);
             dq2.push_back(i);
        }
        ans+=nums[dq.front()]+nums[dq2.front()];
        for(int i=k;i<nums.size();i++){
            if(!dq.empty()&&i-dq.front()>=k){
                dq.pop_front();
            }
             if(!dq.empty()&&i-dq2.front()>=k){
                dq2.pop_front();
            }
            while(!dq.empty()&&nums[i]>=nums[dq.back()]){
                dq.pop_back();
            }
             while(!dq2.empty()&&nums[i]<=nums[dq2.back()]){
                dq2.pop_back();
            }
            dq.push_back(i);            
             dq2.push_back(i);
        ans+=nums[dq.front()]+nums[dq2.front()];

            
        }
        return ans;
    }
