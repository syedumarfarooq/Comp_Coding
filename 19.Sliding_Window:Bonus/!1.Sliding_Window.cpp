*//Sliding window patterns
// 1.Fixed window size
// 2.Variable window size
// start with a small window and gradually expand or shrink based on certain condition
// 3.two Pointers
// 4.Optimised Sliding Window(i.e using extra data structure)
*//Question 1 :Sliding Window Maximum
//using deque
*//Question 2:Two Sum
https://leetcode.com/problems/two-sum/
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.
// Example 1:
// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

*//logic 
// in this we are using two pointer one in the begining and one in the end, if u move the pointer from the end the overall sum of two elements will decrease if me move the front pointer 
// the overall sum increases
*//code
  class Solution {
public:
    static bool cmp(pair<int,int>& a,pair<int,int>&b){
        return a.first<b.first;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>data;//nums and their respective index as we are sorting them we have to return index as answer
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            int val=nums[i];
            data.push_back({val,i});
        }
        sort(data.begin(),data.end(),cmp);
        int start=0;
        int end=data.size()-1;
        while(start<=end){
            if(data[start].first+data[end].first==target){
                ans.push_back(data[start].second);
                ans.push_back(data[end].second);
                return ans;
            }else if(data[start].first+data[end].first>target){
                end--;
            }else{
                start++;
            }
        }
        return ans;
    }
};
*//Question 3:Minimum Size Subarray Sum
https://leetcode.com/problems/minimum-size-subarray-sum/
// Given an array of positive integers nums and a positive integer target, return the minimal length of a 
// subarray
//  whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.
// Example 1:
// Input: target = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: The subarray [4,3] has the minimal length under the problem constraint.
*//logic
// 1.start with 1 size window from the extreme left start =0 and end=1
// 2.increament end till u achieve the target 
// 3.once u achieve target try minimizing the window by incrementing the start if the sum becomes less then again increment the end to achieve target
// 4.save the length whenever u reach the target
// do the above two steps until u reach out of bound
*//code
  class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int j = 0;
        int sum  = 0;
        int len = INT_MAX;

        while( j < nums.size()) {
            //include ciurrent number 
            sum = sum + nums[j];
            //mere paas ek window ka sum ready h 
            while(sum >= target) {
                //minimise -> sum me se decrease karo, len bhi update krelna, i/start ko aage badhana padega

                len = min(len, j-i+1);
                sum = sum - nums[i];
                i++;
            }
            j++;
        }

        if(len == INT_MAX)
            return 0;
        else
            return len;

    }
};
