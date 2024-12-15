https://leetcode.com/problems/make-array-strictly-increasing/
// Given two integer arrays arr1 and arr2, return the minimum number of operations (possibly zero) needed to make arr1 strictly increasing.
// In one operation, you can choose two indices 0 <= i < arr1.length and 0 <= j < arr2.length and do the assignment arr1[i] = arr2[j].
// If there is no way to make arr1 strictly increasing, return -1.
// Example 1:

// Input: arr1 = [1,5,3,6,7], arr2 = [1,3,2,4]
// Output: 1
// Explanation: Replace 5 with 2, then arr1 = [1, 2, 3, 6, 7].
*//logic 
//   we are checking prev and current if prev is less than current then we just move and if not we replace the curr with upperbound of prev 
// in arr2 so that it becomes strictly increasing but if we follow this above case we might get wrong answer in some cases
// eg:arr1=1,5,3,6,7 arr2=1,2,3,4 if we apply above method and solve it will return -1 as in the [2] index 5>3 and there is no upperbound of 
// 5 in arr2 so it is -1 but if we change the 5 in the previous iteration when [0] is prev and [1] is curr we check upperbound of 1 [0]
// and replace 5 [1] with 2 then we get a possible solution
//so basically for every iteration if current > prev we should check both i.e we should change the current position from the prev upper_bound
// and move forward and also count the number of operations to0 i.e increament one as we are performing one operation and also check by 
// just moving it forward without changingso we are checking both possible ways
  //at last the point is, even though prev is less than current then also change prev and check so totally we have to consider two possibility
  //one is change prev even thoush it is less and one more is more forward as it is and check
*//solved using recursion
 class Solution {
public:
    #define INF (1e9+1)
    int solve(vector<int>& arr1, vector<int>& arr2,int prev,int i){
        if(i==arr1.size())return 0;
        int op1=INF;//if we use int_max we add +1 in op2 so if will give overflow so we are using 1e9+1 y 1e9+1 nothing specific we just 
      // used the maximum value of 0 <= arr1[i], arr2[i] <= 10^9 of an element considere it as int_max itself 
      // or else simply use INT_MAX_1 if we add 1 also it wont exceed the bound
      // in worst case op1 will be INT_MAX-1 and op2 will be INT_MAX-1+1 minimum of those will be INT_MAX-1 
        // so in the end ans==INT_MAX-1?-1:ans; as the the returned answer will be INT_MAX-1 atmost wont exceed this as we even took the worst case
        if(prev<arr1[i]){
            op1=solve(arr1,arr2,arr1[i],i+1);
        }
        int op2=INF;
        auto it=upper_bound(arr2.begin(),arr2.end(),prev);
        //lower_bound = Find the position of the first element >= target.
        // upper_bound = Find the position of the first element > target.
        if(it!=arr2.end()){
            int index=it-arr2.begin();
            // arr1[i]=arr2[index]; we shouldn't make direct changes into the array as it might create problems
            //while accessing arr1[i]
            op2=1+solve(arr1,arr2,arr2[index],i+1);
        }
        return min(op1,op2);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());//we are sorting arr2 because we have to apply upperbound for that the array should be sorted
        int ans=solve(arr1,arr2,-1,0);
        return ans==INF?-1:ans;
    }
};
*//solved using memoisation
class Solution {
public:
    #define INF (1e9+1)
    int solveMem(vector<int>& arr1, vector<int>& arr2,int prev,int i, map<pair<int,int>,int>&dp){
        if(i==arr1.size())return 0;
        int op1=INF;
        if(dp.find({prev,i})!=dp.end()){
            return dp[{prev,i}];
        }
        if(prev<arr1[i]){
            op1=solveMem(arr1,arr2,arr1[i],i+1,dp);
        }
        int op2=INF;
        auto it=upper_bound(arr2.begin(),arr2.end(),prev);
        //lower_bound = Find the position of the first element >= target.
        // upper_bound = Find the position of the first element > target.
        if(it!=arr2.end()){
            int index=it-arr2.begin();
            
            op2=1+solveMem(arr1,arr2,arr2[index],i+1,dp);
        }
        dp[{prev,i}]= min(op1,op2);
        return dp[{prev,i}];
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        map<pair<int,int>,int>dp;//we are using map as we are send values of prev than it index so it can be 
        //anything s
        int ans=solveMem(arr1,arr2,-1,0,dp);
        return ans==INF?-1:ans;
    }
};
*//buttom up is only possible if we use prev as index but we are passing values in prev and that can range from 0 to 10^9 so running those
// many loops is not efficient we passed values bcz it was easier to understand
