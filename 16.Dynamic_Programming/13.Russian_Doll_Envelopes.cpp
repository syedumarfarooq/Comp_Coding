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
                 //so basically it does is compare every element that is from ans.begin to end with arr[i] then if a[1]< b[1] then it 
                 // will continue for a[1]>b[1] it returns false and sends the iterator of element where the a[1] is just greater
                 //so the iterator will will stop where it return flase and it will contain that index
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
            if(a[0]==b[0])//if width is same then we place it in decreasing order 
             //eg:4,5|4,6|6,7|2,3|1,1
               // 1,1|2,3|4,5|4,6|6,7//if the height is not sorted in decreasing order if width are same
             //this will create problem so if only the height is take i.e 1,3,5,6,7 //so the longest increasing subsequence for height alone
             // will include all the elements are it is strictly increasing but u cannot all the envelopes as 4,5 cannot be put in 4,6 bcz of 
             // width are same ,but 
               // 1,1|2,3|4,5|4,6|6,7//if the height is sorted in decreasing order if width are same
             // the height will be 1,3,6,5,7 then the longest increasing subsequence is 1,3,6,7 and u can put every envelopes inside the 
             // another and we can drop the 4,5 which is giving us wrong answer
             //this is the reason we place it in decreasing order
             *//you many think what is the reason to put custom comprator for the sort as either way we are checking before inserting and also the reason for sorting
              *//in decending order
         //      bcz where there are element 4,2 4,5 they should be sorted in decreasing order why because  as 4,2 will be place before as it 
         //    will be greater than previous element then when 4,5 comes when they go into the  lower bound function and it checks with which
         // element to swap the lower bound will give end index and as there is no element just greater then 4,5 and we are comparing 5 so
         // there is no element just greater than 5 and it will give end index and when the *index is accessed which is out of array
         // and accessing it will give overflow error 
         // but if 4,5 is placed and in comes under else part and 4,2 check for the lower bound to give next greatest number it will give
         // 4,5 as 5>2 so it will be swapped with 4,5 so it works fine
              
                return a[1]>b[1];
            return a[0]<b[0];
        });
        int ans=solveOptimal(envelopes);
        return ans;
    }
};
*//solve optimal same code as above as there is lot of explanation above so i am just pasting the code here
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
        ans.push_back(arr[0]);

        for(int i=1; i<arr.size(); i++) {
            if(check(arr[i] , ans.back())) {
                //include
                ans.push_back(arr[i]);
            }
            else {
                auto index = lower_bound(ans.begin(), ans.end(),arr[i],[](const vector<int>& a,const vector<int>& b) {
                    return a[1] < b[1];
                });
                *index = arr[i];
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
        return solveOptimal(envelopes);
    }
    
};
