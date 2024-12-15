https://leetcode.com/problems/russian-doll-envelopes/
// You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.
// One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.
// Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).
// Note: You cannot rotate an envelope.
// Example 1:
// Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
// Output: 3
// Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
*//logic
https://github.com/syedumarfarooq/Comp_Coding/blob/main/16.Dynamic_Programming/12.Longest_Increasing_Subsequence.cpp
*//we are using the logic of longest increasing subsequence in that we add the elemnt if the current is greater than the prev in this we do
*// the same we add the envelope only if it is greater than the previous one 
*//same logic can be use to solve https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/
  *//solve using space optimisation
  *//TLE 
  *//removed check also to check if it runs but tle
  class Solution {
public:
//  bool check(vector<int>& curr, vector<int>& prev) {
//         if(prev[0] < curr[0] && prev[1]<curr[1] )
//             return true;
//         else
//             return false;
//     }
    int solveUsingTabSO(vector<vector<int>>& arr) {
        int n = arr.size();
        //vector<vector<int> > dp(n+1, vector<int>(n+1, 0));
        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);

        for(int curr = n-1; curr>=0; curr--) {
            for(int prev = curr - 1; prev >= -1; prev--) {
                //include
                int include = 0;
                if(prev == -1 || arr[curr]>arr[prev])
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
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),[](vector<int>&a ,vector<int>&b){
            if(a[0]==b[0])
                return a[1]>b[1];
            return a[0]<b[0];
        });
        int ans=solveUsingTabSO(envelopes);
        return ans;
    }
};
*//solve optimal using binary search lowebound
 *//explained in https://github.com/syedumarfarooq/Comp_Coding/blob/main/16.Dynamic_Programming/12.Longest_Increasing_Subsequence.cpp
class Solution {
public:
 bool check(vector<int>& curr, vector<int>& prev) {
        if(prev[0] < curr[0] && prev[1]<curr[1] )
            return true;
        else
            return false;
    }
    int solveOptimal(vector<vector<int>>& arr) {
        if(arr.size() == 0)
            return 0;
        vector<vector<int>> ans;
        ans.push_back(arr[0]);//adding first element into the answer

        for(int i=1; i<arr.size(); i++) {
            if(check(arr[i],ans.back())) {//had to add this because for this example [[1,3],[3,5],[6,7],[6,8],[8,4],[9,5]] it was give 5 as
             //output but it is 3 it was comparing the 0th index of all array and comparing so last two also got added but height of them
             //are small we cannot add them so we use check function to check both height and width both should be greater
                //include
                ans.push_back(arr[i]);
            }
            else {
                //overwrite
                //find index of just bada element
                auto it = lower_bound(ans.begin(), ans.end(), arr[i], [](const vector<int>& a,const vector<int>& b) {
                 //had to add this because this else part will run only if the width is same as last because the the array is already 
                 //sorted based on width so the next array will be greater or equal 
                    return a[1] < b[1];//this is just a lambda function compare the heigth for finding the lower bound so it returns
                 //the iterator of the array whose height is just greater than the current height rathter than comparing it with the
                 //width 
                 //so basically it does is compare every element with arr[i] then if a[1]< b[1] then it will continue a[1]>b[1] it returns
                 // false and sends the iterator of element where the a[1] is greater
                 *//at first we didn't add const to the lambda function parameters so it was showing error
                 //  If you don't use const, the compiler might get confused because it thinks your lambda could try to change the data, even though lower_bound 
                 // only wants to read it. That's why it gives an error when const is missing: it's about making sure the data is treated as read-only while it's
                 // being used in certain functions.
                });
                *it = arr[i];
            }
        }
        return ans.size();
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),[](vector<int>&a ,vector<int>&b){
            if(a[0]==b[0])
                return a[1]>b[1];
            return a[0]<b[0];
        });
        int ans=solveOptimal(envelopes);
        return ans;
    }
};
