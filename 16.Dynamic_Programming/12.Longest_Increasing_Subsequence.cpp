https://leetcode.com/problems/longest-increasing-subsequence/
// Given an integer array nums, return the length of the longest strictly increasing 
// subsequence
// .

 

// Example 1:

// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
// Example 2:

// Input: nums = [0,1,0,3,2,3]
// Output: 4
*//Logic
  // we are using the include and exclude method we compare the current element with previous if it is greater we add it and return the longest
// increasing subsequence and if it is greater than prev we move the pointer front and let the recursion do its work
  *//Solved Using recursion
  class Solution {
public:
    int solveUsingRecursion(vector<int>& arr,int curr,int prev){
        if(curr>=arr.size()){
            return 0;
        }
        //include
        int include=0;
        if(prev==-1||arr[curr]>arr[prev]){//if the subsequence arr is empty and if curr> prev then only it is included
            include=1+solveUsingRecursion(arr,curr+1,curr);//we move curr and prev to curr and the last element that is included in curr
        }
        int exclude=0+solveUsingRecursion(arr,curr+1,prev);//we move only curr and as curr element was not include we only not increment prev
        int ans=max(include,exclude);
        return ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int curr=0;
        int prev=-1;//this is used to keep a track element to compare and add
        // the element bcz only number greater than prev is added
        int ans=solveUsingRecursion(nums,curr,prev);
        return ans;
    }
};
*//Solved using mem
int solveUsingMem(vector<int>& arr, int curr, int prev, vector<vector<int> >& dp) {
        if(curr >= arr.size()) {
            return 0;
        }

        if(dp[curr][prev + 1] != -1)//we are doing prev +1 because for prev=-1 it will give error invalid index
          //so while storing we are storing prev+1 thats is rest is same as recursion
            return dp[curr][prev+1];

        //include
        int include = 0;
        if(prev == -1 || arr[curr] > arr[prev])
            include = 1 + solveUsingMem(arr, curr+1, curr, dp);

        //excude
        int exclude = 0 + solveUsingMem(arr, curr+1, prev, dp);

        dp[curr][prev + 1] = max(include, exclude);
        return dp[curr][prev + 1];

    }
*//solved using tab
int solveUsingTab(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int> > dp(n+1, vector<int>(n+1, 0));

        for(int curr = n-1; curr>=0; curr--) {
            for(int prev = curr - 1; prev >= -1; prev--) {//prev always starts from curr -1 
                //include
                int include = 0;
                if(prev == -1 || arr[curr] > arr[prev])
                    include = 1 + dp[curr+1][curr + 1];//while storing we store in +1 index and while accesing we access +1 rest is all the same 

                //excude
                int exclude = 0 + dp[curr+1][prev + 1];

                dp[curr][prev + 1] = max(include, exclude); //as the dp[curr][prev+1] depends or only curr and curr+1 row so it can be done with 2 array
             
            }
        }
        return dp[0][0];
    }
*//Solve using space optimisation
int solveUsingTabSO(vector<int>& arr) {
        int n = arr.size();
        //vector<vector<int> > dp(n+1, vector<int>(n+1, 0));
        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);

        for(int curr = n-1; curr>=0; curr--) {
            for(int prev = curr - 1; prev >= -1; prev--) {
                //include
                int include = 0;
                if(prev == -1 || arr[curr] > arr[prev])
                    include = 1 + nextRow[curr + 1];

                //excude
                int exclude = 0 + nextRow[prev + 1];

                currRow[prev + 1] = max(include, exclude);   
            }
            //shift
            nextRow = currRow;
        }
        return nextRow[0];
    }
*//Solve using O(nlogn) 
*//logic:we are traversing through the array and adding elements in the ans if the element is greater than last element we add it into the 
// answer array if the element is less then we replace it with the number just greater than the element present in the answer array
 int solveOptimal(vector<int>& arr) {
        if(arr.size() == 0)
            return 0;
        vector<int> ans;
        ans.push_back(arr[0]);//adding first element into the answer

        for(int i=1; i<arr.size(); i++) {
            if(arr[i] > ans.back()) {
                //include
                ans.push_back(arr[i]);
            }
            else {
                //overwrite
                //find index of just bada element
                int index = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();//Returns an iterator to the first element not less than 
             // the given value. or function gives you the number that is just greater than or equal to the given value in a sorted range.
                ans[index] = arr[i];
            }
        }
        return ans.size();
    }
