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
            if(check(arr[i],ans.back())) {//had to add this because 
                //include
                ans.push_back(arr[i]);
            }
            else {
                //overwrite
                //find index of just bada element
                auto it = lower_bound(ans.begin(), ans.end(), arr[i], [](const vector<int>& a,const vector<int>& b) {//made changes here
                    return a[1] < b[1];
                });
                //Returns an iterator to the first element not less than 
             // the given value. or function gives you the number that is just greater than or equal to the given value in a sorted range.
             //lower bound gives address as output so that we minus it with the ans.begin() which is the address of the first element
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
